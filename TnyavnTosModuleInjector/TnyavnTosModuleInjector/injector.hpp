#pragma once
#include <windows.h>
#include <tlhelp32.h>
#include <string>
#include <shlwapi.h>

#pragma comment(lib, "Shlwapi.lib")

namespace Injector {

    // Result structure returned by InjectModule
    struct InjectResult {
        bool success;
        std::string message;
    };

    // Check if a file exists on disk
    inline bool FileExists(const char* path) {
        DWORD attr = GetFileAttributesA(path);
        return (attr != INVALID_FILE_ATTRIBUTES && !(attr & FILE_ATTRIBUTE_DIRECTORY));
    }

    // Resolve a process name (wide string comparison) to a PID via Toolhelp snapshot
    inline DWORD GetProcessIdByName(const wchar_t* processName, size_t nameLen) {
        DWORD pid = 0;
        HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (snap == INVALID_HANDLE_VALUE) return 0;

        PROCESSENTRY32W pe{};
        pe.dwSize = sizeof(pe);
        if (Process32FirstW(snap, &pe)) {
            do {
                size_t exeLen = wcslen(pe.szExeFile);
                size_t cmpLen = (exeLen < nameLen) ? exeLen : nameLen;
                if (cmpLen && wcsncmp(processName, pe.szExeFile, cmpLen) == 0 && nameLen == exeLen) {
                    pid = pe.th32ProcessID;
                    break;
                }
            } while (Process32NextW(snap, &pe));
        }
        CloseHandle(snap);
        return pid;
    }

    // Main injection routine — faithfully mirrors the pseudocode logic
    inline InjectResult InjectModule(const char* dllPath, const char* processInput) {
        InjectResult result{};

        // 1. Check that a module has been selected
        if (!dllPath || !dllPath[0]) {
            return { false, "You must select a module first" };
        }

        // 2. Check that the module file still exists
        if (!FileExists(dllPath)) {
            return { false, "Selected module was deleted" };
        }

        // 3. Need a process name / id
        if (!processInput || !processInput[0]) {
            return { false, "You must provide a process name/id" };
        }

        // 4. Try to parse the input as a numeric PID first (strtol)
        DWORD pid = 0;
        {
            char* endptr = nullptr;
            errno = 0;
            long val = strtol(processInput, &endptr, 10);
            if (endptr != processInput && errno != ERANGE) {
                pid = (DWORD)val;
            }
        }

        // 5. If numeric parse failed, treat as process name — snapshot search
        if (pid == 0) {
            // Convert narrow process input to wide
            int wlen = MultiByteToWideChar(CP_ACP, 0, processInput, -1, NULL, 0);
            if (wlen > 0) {
                std::wstring wname(wlen - 1, L'\0');
                MultiByteToWideChar(CP_ACP, 0, processInput, -1, &wname[0], wlen);
                pid = GetProcessIdByName(wname.c_str(), wname.size());
            }
        }

        if (pid == 0) {
            return { false, "Invalid Process Name" };
        }

        // 6. OpenProcess
        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
        if (!hProcess) {
            if (GetLastError() == ERROR_INVALID_PARAMETER) {
                return { false, "Invalid process identifier" };
            }
            return { false, "OpenProcess() Failed. Try to run TMI elevated?" };
        }

        // 7. Allocate remote memory
        size_t dllPathLen = strlen(dllPath) + 1;
        void* remoteBuf = VirtualAllocEx(hProcess, nullptr, dllPathLen, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        if (!remoteBuf) {
            CloseHandle(hProcess);
            return { false, "VirtualAllocEx() Failed" };
        }

        // 8. Write DLL path
        if (!WriteProcessMemory(hProcess, remoteBuf, dllPath, dllPathLen, nullptr)) {
            VirtualFreeEx(hProcess, remoteBuf, 0, MEM_RELEASE);
            CloseHandle(hProcess);
            return { false, "WriteProcessMemory() Failed" };
        }

        // 9. Create remote thread calling LoadLibraryA
        HANDLE hThread = CreateRemoteThread(hProcess, nullptr, 0,
            (LPTHREAD_START_ROUTINE)LoadLibraryA, remoteBuf, 0, nullptr);
        if (!hThread) {
            VirtualFreeEx(hProcess, remoteBuf, 0, MEM_RELEASE);
            CloseHandle(hProcess);
            return { false, "CreateRemoteThread() Failed" };
        }

        // 10. Wait and check
        WaitForSingleObject(hThread, INFINITE);
        DWORD exitCode = 0;
        GetExitCodeThread(hThread, &exitCode);
        CloseHandle(hThread);

        if (!VirtualFreeEx(hProcess, remoteBuf, 0, MEM_RELEASE)) {
            CloseHandle(hProcess);
            return { false, "VirtualFreeEx() Failed" };
        }

        CloseHandle(hProcess);

        if (exitCode != 0) {
            return { true, "Module Successfully Injected" };
        } else {
            return { false, "Injecting Module Failed" };
        }
    }
}
