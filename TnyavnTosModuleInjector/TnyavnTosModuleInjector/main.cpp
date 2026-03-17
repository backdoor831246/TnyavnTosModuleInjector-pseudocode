// TnyavnTo's Module Injector — main.cpp
// Reconstructed from IDA pseudocode — ImGui + Direct3D 11

#include <windows.h>
#include <d3d11.h>
#include <shlwapi.h>
#include <commdlg.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "Shlwapi.lib")
#pragma comment(lib, "Comdlg32.lib")

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include "injector.hpp"

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// ── Globals ─────────────────────────────────────────────────────────────────
static ID3D11Device*            g_pd3dDevice        = nullptr;
static ID3D11DeviceContext*     g_pd3dDeviceContext  = nullptr;
static IDXGISwapChain*          g_pSwapChain         = nullptr;
static ID3D11RenderTargetView*  g_mainRenderTargetView = nullptr;
static HWND                     g_hWnd               = nullptr;

static char  g_selectedModulePath[MAX_PATH] = {};   // full DLL path chosen via dialog
static char  g_processInput[52]             = {};   // process name / ID text (51 chars + null, matching pseudocode)
static std::string g_notificationText;              // popup notification message

// ── D3D11 helpers ───────────────────────────────────────────────────────────
static void CreateRenderTarget()
{
    ID3D11Texture2D* pBackBuffer = nullptr;
    g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
    if (pBackBuffer) {
        g_pd3dDevice->CreateRenderTargetView(pBackBuffer, nullptr, &g_mainRenderTargetView);
        pBackBuffer->Release();
    }
}

static void CleanupRenderTarget()
{
    if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = nullptr; }
}

static bool CreateDeviceD3D(HWND hWnd)
{
    DXGI_SWAP_CHAIN_DESC sd{};
    sd.BufferCount        = 2;
    sd.BufferDesc.Width   = 0;
    sd.BufferDesc.Height  = 0;
    sd.BufferDesc.Format  = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator   = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.Flags              = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    sd.BufferUsage        = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow       = hWnd;
    sd.SampleDesc.Count   = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed           = TRUE;
    sd.SwapEffect         = DXGI_SWAP_EFFECT_DISCARD;

    D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0 };
    D3D_FEATURE_LEVEL featureLevel;

    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
        featureLevels, 2, D3D11_SDK_VERSION,
        &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext);

    if (FAILED(hr)) return false;

    CreateRenderTarget();
    return true;
}

static void CleanupDeviceD3D()
{
    CleanupRenderTarget();
    if (g_pSwapChain)        { g_pSwapChain->Release();        g_pSwapChain        = nullptr; }
    if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release();  g_pd3dDeviceContext = nullptr; }
    if (g_pd3dDevice)        { g_pd3dDevice->Release();         g_pd3dDevice        = nullptr; }
}

// ── WndProc ────────────────────────────────────────────────────────────────
static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return 1;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice && wParam != SIZE_MINIMIZED) {
            CleanupRenderTarget();
            g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
            CreateRenderTarget();
        }
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hWnd, msg, wParam, lParam);
}

// ── Validate selected file is a PE ──────────────────────────────────────────
static bool ValidatePE(const char* path)
{
    HANDLE hFile = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (hFile == INVALID_HANDLE_VALUE) return false;

    HANDLE hMap = CreateFileMappingW(hFile, nullptr, PAGE_READONLY, 0, 0, nullptr);
    if (!hMap) { CloseHandle(hFile); return false; }

    void* pView = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
    if (!pView) { CloseHandle(hMap); CloseHandle(hFile); return false; }

    bool valid = (*(WORD*)pView == 0x5A4D); // "MZ"

    UnmapViewOfFile(pView);
    CloseHandle(hMap);
    CloseHandle(hFile);
    return valid;
}

// ── Entry point ────────────────────────────────────────────────────────────
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
    // Build window title: "TnyavnTo's Module Injector - v<version>"
    const char* version = "1.0";
    char windowTitleA[256];
    sprintf_s(windowTitleA, "TnyavnTo's Module Injector - v%s", version);

    // Convert to wide
    wchar_t windowTitleW[256];
    MultiByteToWideChar(CP_ACP, 0, windowTitleA, -1, windowTitleW, 256);

    // Register window class  (matches pseudocode class name "SMI_MainWindow")
    WNDCLASSEXW wc{};
    wc.cbSize        = sizeof(wc);
    wc.style         = CS_CLASSDC;
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = GetModuleHandleW(nullptr);
    wc.lpszClassName = L"SMI_MainWindow";
    RegisterClassExW(&wc);

    // Window dimensions from pseudocode: 500 x 188, position 100,100
    g_hWnd = CreateWindowExW(
        0, wc.lpszClassName, windowTitleW,
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        100, 100, 500, 188,
        nullptr, nullptr, wc.hInstance, nullptr);

    // Init D3D11
    if (!CreateDeviceD3D(g_hWnd)) {
        MessageBoxA(g_hWnd, "Failed to create Direct3D device", nullptr, MB_ICONERROR);
        CleanupDeviceD3D();
        UnregisterClassW(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    ShowWindow(g_hWnd, SW_SHOWDEFAULT);
    UpdateWindow(g_hWnd);

    // Init ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr; // no ini saving

    // Load Verdana 26px (matches pseudocode: "\\Windows\\Fonts\\Verdana.ttf", 26)
    {
        char fontPath[MAX_PATH]{};
        const char* sysDrive = getenv("SystemDrive");
        if (sysDrive)
            sprintf_s(fontPath, "%s\\Windows\\Fonts\\Verdana.ttf", sysDrive);
        else
            sprintf_s(fontPath, "C:\\Windows\\Fonts\\Verdana.ttf");

        FILE* f = fopen(fontPath, "rb");
        if (f) {
            fclose(f);
            io.Fonts->AddFontFromFileTTF(fontPath, 16.0f);
        }
    }

    ImGui_ImplWin32_Init(g_hWnd);
    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

    // Style — dark theme
    ImGui::StyleColorsDark();
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding   = 0.0f;
    style.FrameRounding    = 2.0f;
    style.WindowBorderSize = 0.0f;

    // ── Main loop ───────────────────────────────────────────────────────────
    bool done = false;
    MSG msg{};
    while (!done)
    {
        while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done) break;

        // New frame
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        // ── Notification popup (matches pseudocode "###PopupNotification") ──
        if (!g_notificationText.empty())
        {
            ImGui::OpenPopup("###PopupNotification");
        }
        if (ImGui::BeginPopupModal("###PopupNotification", nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar))
        {
            ImGui::Text("%s", g_notificationText.c_str());
            ImVec2 btnSize(120.0f, 0.0f);
            if (ImGui::Button("OK", btnSize))
            {
                g_notificationText.clear();
                ImGui::CloseCurrentPopup();
            }
            ImGui::EndPopup();
        }

        // ── Main window (matches pseudocode "MainWindow", flags = no decoration + no resize + no move + no scrollbar + no collapse) ──
        {
            ImGuiWindowFlags flags =
                ImGuiWindowFlags_NoDecoration |
                ImGuiWindowFlags_NoMove |
                ImGuiWindowFlags_NoResize |
                ImGuiWindowFlags_NoScrollbar |
                ImGuiWindowFlags_NoScrollWithMouse;

            // Fill the entire client area
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::SetNextWindowSize(io.DisplaySize);

            ImGui::Begin("MainWindow", nullptr, flags);

            // ── "Module Name:" label + display ──
            ImGui::Text("Module Name:");
            ImGui::SameLine();
            if (g_selectedModulePath[0]) {
                const char* fileName = PathFindFileNameA(g_selectedModulePath);
                ImGui::Text("%s", fileName);
            }

            // ── "Select Module" button (matches pseudocode, full width) ──
            ImGui::SameLine();
            float itemSpacing = ImGui::GetStyle().ItemSpacing.x;
            float availWidth = ImGui::GetContentRegionAvail().x;
            if (ImGui::Button("Select Module", ImVec2(availWidth, 0)))
            {
                char fileBuf[MAX_PATH + 4]{};
                OPENFILENAMEA ofn{};
                ofn.lStructSize  = sizeof(ofn);
                ofn.hwndOwner    = g_hWnd;
                ofn.lpstrFile    = fileBuf;
                ofn.lpstrFile[0] = '\0';
                ofn.nMaxFile     = MAX_PATH;
                ofn.lpstrFilter  = "DLL Files\0*.dll\0All Files\0*.*\0";
                ofn.nFilterIndex = 1;
                ofn.Flags        = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

                if (GetOpenFileNameA(&ofn))
                {
                    if (ofn.lpstrFile && ofn.lpstrFile[0])
                    {
                        if (ValidatePE(ofn.lpstrFile)) {
                            strcpy_s(g_selectedModulePath, ofn.lpstrFile);
                        } else {
                            g_notificationText = "Selected file is not a valid NT executable";
                        }
                    }
                }
            }

            // ── "Process Name/ID:" input  (matches pseudocode "##ProcessNameOrIDInput", 51 char buf) ──
            ImGui::Text("Process Name/ID:");
            ImGui::SameLine();
            ImGui::PushItemWidth(-1);
            ImGui::InputText("##ProcessNameOrIDInput", g_processInput, sizeof(g_processInput));
            ImGui::PopItemWidth();

            ImGui::Spacing();

            // ── "Inject Module" button (matches pseudocode size roughly 250x30) ──
            {
                ImVec2 injectSize(ImGui::GetContentRegionAvail().x, 30.0f);
                if (ImGui::Button("Inject Module", injectSize))
                {
                    if (!g_selectedModulePath[0])
                    {
                        g_notificationText = "You must select a module first";
                    }
                    else
                    {
                        // Build std::string of process input
                        std::string procStr(g_processInput);
                        if (procStr.empty())
                        {
                            g_notificationText = "You must provide a process name/id";
                        }
                        else
                        {
                            auto result = Injector::InjectModule(g_selectedModulePath, g_processInput);
                            g_notificationText = result.message;
                        }
                    }
                }
            }

            // ── "About" button ──
            {
                ImVec2 aboutSize(ImGui::GetContentRegionAvail().x, 0.0f);
                if (ImGui::Button("About", aboutSize))
                {
                    ImGui::OpenPopup("About TMI###AboutPopup");
                }

                if (ImGui::BeginPopupModal("About TMI###AboutPopup", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
                {
                    // Matches pseudocode: "Author: TnyavnTo\nCompiled: Feb 24 2023 14:08:24"
                    ImGui::Text("Author: TnyavnTo\nCompiled: %s %s", __DATE__, __TIME__);

                    if (ImGui::Button("Close", ImVec2(120.0f, 0.0f)))
                    {
                        ImGui::CloseCurrentPopup();
                    }
                    ImGui::EndPopup();
                }
            }

            ImGui::End();
        }

        // ── Render ──────────────────────────────────────────────────────────
        ImGui::Render();
        const float clear_color[4] = { 0.06f, 0.06f, 0.06f, 1.00f };
        g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, nullptr);
        g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

        // Present with vsync (1) — matches pseudocode
        HRESULT hr = g_pSwapChain->Present(1, 0);
        if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET)
        {
            // device lost, just sleep a bit and try to keep going
            Sleep(50);
        }
    }

    // ── Cleanup ─────────────────────────────────────────────────────────────
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    DestroyWindow(g_hWnd);
    UnregisterClassW(wc.lpszClassName, wc.hInstance);

    return 0;
}
