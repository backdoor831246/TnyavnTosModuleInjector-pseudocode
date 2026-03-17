int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    size_t v4; // r13
    void** v5; // r15
    size_t v6; // r14
    unsigned __int64 v7; // rsi
    _QWORD* v8; // rbx
    size_t v9; // rcx
    void* v10; // rax
    void** v11; // rdx
    char* v12; // r8
    const WCHAR* v13; // r8
    WCHAR* v14; // rcx
    void* v15; // rcx
    char* v17; // rax
    __int64 v18; // rcx
    void* v19; // rax
    _QWORD* v20; // r15
    HWND v21; // rsi
    char* v22; // rbx
    __int64 v23; // rsi
    HMODULE LibraryA; // rax
    HMODULE v25; // r14
    ID3D11DeviceContext* v26; // r12
    ID3D11Device* v27; // r14
    _QWORD* v28; // rsi
    char* v29; // rbx
    char* v30; // rax
    void* v31; // rcx
    __int64 v32; // r12
    const CHAR* v33; // rbx
    FILE* v34; // rax
    __int64 v35; // rdx
    __int64 v36; // rcx
    __int64 v37; // r8
    __int64 v38; // r9
    FILE* v39; // rsi
    int v40; // r15d
    int v41; // eax
    size_t v42; // r14
    void* v43; // rax
    void* v44; // r15
    __int128 v45; // xmm3
    unsigned int hwndOwner_high; // xmm5_4^12
    __int128 v47; // xmm6
    __int128 v48; // xmm7
    __m128 v49; // xmm2
    __m128 v50; // xmm2
    __int128 v51; // xmm4
    __int128 v52; // xmm1
    __int128 v53; // xmm8
    const CHAR* v54; // xmm9_8
    __int64 v55; // r9
    const CHAR* v56; // r9
    unsigned __int64 v57; // rcx
    char v58; // al
    __int64 v59; // rcx
    unsigned int v60; // eax
    char* v61; // rcx
    char** v62; // rax
    _BYTE* v63; // rbx
    __int64 v64; // rax
    _DWORD* v65; // rax
    char* FileNameA; // rax
    _DWORD* v67; // rbx
    int v68; // xmm6_4
    char v69; // al
    CHAR* v70; // rax
    const CHAR* lpstrFile; // rsi
    HANDLE FileA; // rax
    __int64 v73; // rcx
    void* v74; // r14
    HANDLE FileMappingW; // rax
    void* v76; // rbx
    _WORD* v77; // r15
    __int64 v78; // rcx
    __int64 v79; // r8
    __int64 v80; // rcx
    int* v81; // rax
    int* v82; // rsi
    const char* v83; // rbx
    unsigned int v84; // r14d
    __int64 v85; // r8
    char* v86; // rcx
    unsigned int v87; // eax
    __int64 v88; // r8
    void** v89; // rbx
    size_t v90; // rsi
    void** v91; // rax
    __int64 v92; // rax
    __int64 v93; // rdx
    __int64 v94; // rax
    void* v95; // rcx
    void* v96; // rcx
    void* v97; // rcx
    void* v98; // rcx
    void* v99; // rcx
    char* v100; // rcx
    char* v101; // rcx
    __int64 v102; // rcx
    _QWORD* v103; // rsi
    _QWORD* v104; // rbx
    __int64 v105; // rcx
    __int64 v106; // rcx
    _DWORD* v107; // rax
    _QWORD* v108; // rbx
    char* v109; // rsi
    HMODULE v110; // rcx
    void* v111; // rbx
    __int64 v112; // rdx
    __int64 v113; // rcx
    __int64 v114; // r8
    __int64 v115; // r9
    void* v116; // rax
    CHAR* v117; // rcx
    WCHAR* v118; // rcx
    void* v119; // rcx
    char v120; // [rsp+60h] [rbp-3A8h] BYREF
    void* Src[2]; // [rsp+68h] [rbp-3A0h] BYREF
    __int64 v122; // [rsp+78h] [rbp-390h]
    unsigned __int64 v123; // [rsp+80h] [rbp-388h]
    void* v124[2]; // [rsp+88h] [rbp-380h] BYREF
    __int64 v125; // [rsp+98h] [rbp-370h]
    unsigned __int64 v126; // [rsp+A0h] [rbp-368h]
    void* v127[2]; // [rsp+A8h] [rbp-360h] BYREF
    __int64 v128; // [rsp+B8h] [rbp-350h]
    unsigned __int64 v129; // [rsp+C0h] [rbp-348h]
    _DWORD v130[2]; // [rsp+C8h] [rbp-340h] BYREF
    _DWORD v131[2]; // [rsp+D0h] [rbp-338h] BYREF
    void* v132[2]; // [rsp+D8h] [rbp-330h] BYREF
    __int128 v133; // [rsp+E8h] [rbp-320h]
    void* Block[2]; // [rsp+F8h] [rbp-310h] BYREF
    __int64 v135; // [rsp+108h] [rbp-300h]
    unsigned __int64 v136; // [rsp+110h] [rbp-2F8h]
    void** v137; // [rsp+118h] [rbp-2F0h]
    D3D_FEATURE_LEVEL pFeatureLevel[2]; // [rsp+128h] [rbp-2E0h] BYREF
    char* EndPtr; // [rsp+130h] [rbp-2D8h] BYREF
    __int64 v140; // [rsp+138h] [rbp-2D0h] BYREF
    struct tagOFNA pSwapChainDesc; // [rsp+140h] [rbp-2C8h] BYREF
    WNDCLASSEXW v142; // [rsp+1E0h] [rbp-228h] BYREF
    LARGE_INTEGER PerformanceCount; // [rsp+230h] [rbp-1D8h] BYREF
    LARGE_INTEGER Frequency; // [rsp+238h] [rbp-1D0h] BYREF
    void* v145[2]; // [rsp+240h] [rbp-1C8h] BYREF
    size_t v146; // [rsp+250h] [rbp-1B8h]
    unsigned __int64 v147; // [rsp+258h] [rbp-1B0h]
    char* String[2]; // [rsp+260h] [rbp-1A8h] BYREF
    __int64 v149; // [rsp+270h] [rbp-198h]
    unsigned __int64 v150; // [rsp+278h] [rbp-190h]
    LPCWSTR lpWindowName[2]; // [rsp+280h] [rbp-188h] BYREF
    __int64 v152; // [rsp+290h] [rbp-178h]
    unsigned __int64 v153; // [rsp+298h] [rbp-170h]
    char* Format[2]; // [rsp+2A0h] [rbp-168h] BYREF
    __int128 v155; // [rsp+2B0h] [rbp-158h]
    LPCCH lpMultiByteStr[3]; // [rsp+2C0h] [rbp-148h] BYREF
    unsigned __int64 v157; // [rsp+2D8h] [rbp-130h]
    struct tagMSG Msg; // [rsp+2E0h] [rbp-128h] BYREF
    __int128 v159; // [rsp+310h] [rbp-F8h]
    __int128 v160; // [rsp+320h] [rbp-E8h]
    __int128 v161; // [rsp+330h] [rbp-D8h]
    __int128 v162; // [rsp+340h] [rbp-C8h]
    __m128 v163; // [rsp+350h] [rbp-B8h]
    char Buffer[16]; // [rsp+360h] [rbp-A8h] BYREF
    __int128 v165; // [rsp+370h] [rbp-98h]
    __int128 v166; // [rsp+380h] [rbp-88h]
    const CHAR* v167; // [rsp+390h] [rbp-78h]
    D3D_FEATURE_LEVEL pFeatureLevels[2]; // [rsp+3A0h] [rbp-68h] BYREF

    v142.cbSize = 80;
    v142.style = 64;
    v142.lpfnWndProc = (WNDPROC)sub_1400059C0;
    *(_QWORD*)&v142.cbClsExtra = 0;
    v142.hInstance = GetModuleHandleW(nullptr);
    memset(&v142.hIcon, 0, 32);
    v142.lpszClassName = L"SMI_MainWindow";
    v142.hIconSm = nullptr;
    RegisterClassExW(&v142);
    v4 = Size;
    if (0x7FFFFFFFFFFFFFFFLL - Size < 0x1E)
        sub_1400011E0();
    v5 = ::Src;
    if (*(&Size + 1) >= 0x10)
        v5 = (void**)::Src[0];
    *(_OWORD*)v145 = 0;
    v146 = 0;
    v147 = 0;
    v6 = Size + 30;
    v7 = 15;
    v8 = v145;
    if (Size + 30 > 0xF)
    {
        v7 = v6 | 0xF;
        if ((v6 | 0xF) <= 0x7FFFFFFFFFFFFFFFLL)
        {
            if (v7 < 0x16)
                v7 = 22;
        }
        else
        {
            v7 = 0x7FFFFFFFFFFFFFFFLL;
        }
        v9 = v7 + 1;
        if (v7 == -1)
            v9 = -1;
        if (v9 < 0x1000)
        {
            if (v9)
                v8 = operator new(v9);
            else
                v8 = nullptr;
        }
        else
        {
            if (v9 + 39 < v9)
                sub_140001140();
            v10 = operator new(v9 + 39);
            if (!v10)
                goto LABEL_242;
            v8 = (_QWORD*)(((unsigned __int64)v10 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *(v8 - 1) = v10;
        }
        v145[0] = v8;
    }
    v146 = v4 + 30;
    v147 = v7;
    qmemcpy(v8, "TnyavnTo's Module Injector - v", 30);
    memcpy((char*)v8 + 30, v5, v4);
    *((_BYTE*)v8 + v6) = 0;
    if (v147 < 0x10)
    {
        v12 = (char*)v145 + v146;
        v11 = v145;
    }
    else
    {
        v11 = (void**)v145[0];
        v12 = (char*)v145[0] + v146;
    }
    sub_140005400(lpWindowName, v11, v12);
    v13 = (const WCHAR*)lpWindowName;
    if (v153 >= 8)
        v13 = lpWindowName[0];
    hWnd = CreateWindowExW(
        0,
        v142.lpszClassName,
        v13,
        0xCA0000u,
        100,
        100,
        500,
        188,
        nullptr,
        nullptr,
        v142.hInstance,
        nullptr);
    *(HINSTANCE*)((char*)&pSwapChainDesc.hInstance + 4) = nullptr;
    *(_QWORD*)&pSwapChainDesc.nMaxCustFilter = 2;
    pSwapChainDesc.lpstrFileTitle = (LPSTR)2;
    *(_QWORD*)&pSwapChainDesc.lStructSize = 0;
    LODWORD(pSwapChainDesc.hInstance) = 28;
    pSwapChainDesc.hwndOwner = (HWND)0x10000003CLL;
    HIDWORD(pSwapChainDesc.lpstrCustomFilter) = 32;
    pSwapChainDesc.lpstrFile = (LPSTR)hWnd;
    *(LPCSTR*)((char*)&pSwapChainDesc.lpstrFilter + 4) = (LPCSTR)1;
    *(_QWORD*)&pSwapChainDesc.nMaxFile = 1;
    pFeatureLevels[0] = D3D_FEATURE_LEVEL_11_0;
    pFeatureLevels[1] = D3D_FEATURE_LEVEL_10_0;
    if (D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        0,
        pFeatureLevels,
        2u,
        7u,
        (const DXGI_SWAP_CHAIN_DESC*)&pSwapChainDesc,
        &ppSwapChain,
        &ppDevice,
        pFeatureLevel,
        &ppImmediateContext))
    {
        MessageBoxA(hWnd, "Failed to create Direct3D device", nullptr, 0x10u);
        ((void (*)(void))sub_1400058D0)();
        UnregisterClassW(v142.lpszClassName, v142.hInstance);
        if (v153 < 8)
        {
        LABEL_29:
            v152 = 0;
            v153 = 7;
            LOWORD(lpWindowName[0]) = 0;
            if (v147 < 0x10)
                return 1;
            v15 = v145[0];
            if (v147 + 1 < 0x1000
                || (v15 = *((void**)v145[0] - 1), (unsigned __int64)((char*)v145[0] - (char*)v15 - 8) <= 0x1F))
            {
                j_j_free(v15);
                return 1;
            }
        LABEL_242:
            invalid_parameter_noinfo_noreturn();
        }
        v14 = (WCHAR*)lpWindowName[0];
        if (2 * v153 + 2 < 0x1000
            || (v14 = *((WCHAR**)lpWindowName[0] - 1), (unsigned __int64)((char*)lpWindowName[0] - (char*)v14 - 8) <= 0x1F))
        {
            j_j_free(v14);
            goto LABEL_29;
        }
    LABEL_237:
        invalid_parameter_noinfo_noreturn();
    }
    sub_140005950();
    ShowWindow(hWnd, 1);
    if (::Block)
        ++*((_DWORD*)::Block + 59);
    v17 = (char*)malloc(0x61D8u);
    EndPtr = v17;
    Frequency.QuadPart = (LONGLONG)&v120;
    PerformanceCount.QuadPart = (LONGLONG)v17;
    if (v17)
        v18 = sub_140005E50(v17, 0);
    else
        v18 = 0;
    v19 = ::Block;
    if (!::Block)
        v19 = (void*)v18;
    ::Block = v19;
    sub_14000C120(v18);
    v20 = ::Block;
    *((_QWORD*)::Block + 4) = 0;
    v21 = hWnd;
    if (QueryPerformanceFrequency(&Frequency) && QueryPerformanceCounter(&PerformanceCount))
    {
        if (::Block)
            ++*((_DWORD*)::Block + 59);
        v22 = (char*)malloc(0x48u);
        EndPtr = v22;
        if (v22)
        {
            *(_OWORD*)v22 = 0;
            *((_OWORD*)v22 + 1) = 0;
            *((_OWORD*)v22 + 2) = 0;
            *((_OWORD*)v22 + 3) = 0;
            *((_QWORD*)v22 + 8) = 0;
        }
        else
        {
            v22 = nullptr;
        }
        v20[18] = v22;
        v20[16] = "imgui_impl_win32";
        *((_DWORD*)v20 + 3) |= 6u;
        *(_QWORD*)v22 = v21;
        v22[45] = 1;
        *((LARGE_INTEGER*)v22 + 4) = Frequency;
        *((LARGE_INTEGER*)v22 + 3) = PerformanceCount;
        *((_DWORD*)v22 + 10) = 9;
        *(_QWORD*)(**((_QWORD**)::Block + 2054) + 40LL) = v21;
        *(_QWORD*)&pSwapChainDesc.lStructSize = "xinput1_4.dll";
        pSwapChainDesc.hwndOwner = (HWND)"xinput1_3.dll";
        pSwapChainDesc.hInstance = (HINSTANCE)"xinput9_1_0.dll";
        pSwapChainDesc.lpstrFilter = "xinput1_2.dll";
        pSwapChainDesc.lpstrCustomFilter = "xinput1_1.dll";
        v23 = 0;
        while (1)
        {
            LibraryA = LoadLibraryA(*((LPCSTR*)&pSwapChainDesc.lStructSize + v23));
            v25 = LibraryA;
            if (LibraryA)
                break;
            if (++v23 >= 5)
                goto LABEL_53;
        }
        *((_QWORD*)v22 + 6) = LibraryA;
        *((_QWORD*)v22 + 7) = GetProcAddress(LibraryA, "XInputGetCapabilities");
        *((_QWORD*)v22 + 8) = GetProcAddress(v25, "XInputGetState");
    }
LABEL_53:
    v26 = ppImmediateContext;
    v27 = ppDevice;
    v28 = ::Block;
    if (::Block)
        ++*((_DWORD*)::Block + 59);
    v29 = (char*)malloc(0x78u);
    EndPtr = v29;
    if (v29)
    {
        *(_OWORD*)v29 = 0;
        *((_OWORD*)v29 + 1) = 0;
        *((_OWORD*)v29 + 2) = 0;
        *((_OWORD*)v29 + 3) = 0;
        *((_OWORD*)v29 + 4) = 0;
        *((_OWORD*)v29 + 5) = 0;
        *((_OWORD*)v29 + 6) = 0;
        *((_QWORD*)v29 + 14) = 0;
        *((_DWORD*)v29 + 28) = 5000;
        *((_DWORD*)v29 + 29) = 10000;
    }
    else
    {
        v29 = nullptr;
    }
    v28[19] = v29;
    v28[17] = "imgui_impl_dx11";
    *((_DWORD*)v28 + 3) |= 8u;
    *(_QWORD*)pFeatureLevel = 0;
    *(_QWORD*)pFeatureLevels = 0;
    v140 = 0;
    if (!((unsigned __int64(__fastcall*)(ID3D11Device*, void*, D3D_FEATURE_LEVEL*))v27->lpVtbl->QueryInterface)(
        v27,
        &unk_14003E778,
        pFeatureLevel)
        && !(*(unsigned int(__fastcall**)(_QWORD, void*, D3D_FEATURE_LEVEL*))(**(_QWORD**)pFeatureLevel + 48LL))(
            *(_QWORD*)pFeatureLevel,
            &unk_14003E788,
            pFeatureLevels)
        && !(*(unsigned int(__fastcall**)(_QWORD, void*, __int64*))(**(_QWORD**)pFeatureLevels + 48LL))(
            *(_QWORD*)pFeatureLevels,
            &unk_14003E798,
            &v140))
    {
        *(_QWORD*)v29 = v27;
        *((_QWORD*)v29 + 1) = v26;
        *((_QWORD*)v29 + 2) = v140;
    }
    if (*(_QWORD*)pFeatureLevel)
        (*(void(__fastcall**)(_QWORD))(**(_QWORD**)pFeatureLevel + 16LL))(*(_QWORD*)pFeatureLevel);
    if (*(_QWORD*)pFeatureLevels)
        (*(void(__fastcall**)(_QWORD))(**(_QWORD**)pFeatureLevels + 16LL))(*(_QWORD*)pFeatureLevels);
    (*(void(__fastcall**)(_QWORD))(**(_QWORD**)v29 + 8LL))(*(_QWORD*)v29);
    (*(void(__fastcall**)(_QWORD))(**((_QWORD**)v29 + 1) + 8LL))(*((_QWORD*)v29 + 1));
    *(_OWORD*)Block = 0;
    v135 = 0;
    v136 = 0;
    sub_1400022F0(Block, "\\Windows\\Fonts\\Verdana.ttf", 26);
    v30 = getenv("SystemDrive");
    sub_1400052D0(lpMultiByteStr, v30, Block);
    if (v136 >= 0x10)
    {
        v31 = Block[0];
        if (v136 + 1 >= 0x1000)
        {
            v31 = *((void**)Block[0] - 1);
            if ((unsigned __int64)((char*)Block[0] - (char*)v31 - 8) > 0x1F)
                invalid_parameter_noinfo_noreturn();
        }
        j_j_free(v31);
    }
    v135 = 0;
    v136 = 15;
    LOBYTE(Block[0]) = 0;
    v32 = v20[10];
    v33 = (const CHAR*)lpMultiByteStr;
    if (v157 >= 0x10)
        v33 = lpMultiByteStr[0];
    v34 = (FILE*)sub_140007640(v33, "rb");
    v39 = v34;
    if (v34)
    {
        v40 = ftell(v34);
        if (v40 == -1)
            goto LABEL_95;
        if (fseek(v39, 0, 2))
            goto LABEL_95;
        v41 = ftell(v39);
        v42 = v41;
        if (v41 == -1 || fseek(v39, v40, 0) || v42 == -1)
            goto LABEL_95;
        if (::Block)
            ++*((_DWORD*)::Block + 59);
        v43 = malloc(v42);
        v44 = v43;
        if (!v43)
        {
        LABEL_95:
            fclose(v39);
        }
        else if (fread(v43, 1u, v42, v39) == v42)
        {
            fclose(v39);
            v45 = 0;
            memset(&pSwapChainDesc, 0, 24);
            *(_OWORD*)&pSwapChainDesc.lpstrInitialDir = 0;
            pSwapChainDesc.lpTemplateName = nullptr;
            BYTE4(pSwapChainDesc.hwndOwner) = 1;
            pSwapChainDesc.lpstrFilter = (LPCSTR)0x100000003LL;
            WORD2(pSwapChainDesc.lpstrInitialDir) = -1;
            hwndOwner_high = HIDWORD(pSwapChainDesc.hwndOwner);
            v159 = *(_OWORD*)&pSwapChainDesc.lStructSize;
            v47 = *(_OWORD*)&pSwapChainDesc.hInstance;
            v160 = *(_OWORD*)&pSwapChainDesc.hInstance;
            v161 = 0;
            v48 = 0;
            v162 = 0;
            v49 = _mm_shuffle_ps((__m128)0LL, (__m128)0LL, 225);
            v49.m128_f32[0] = 3.4028235e38;
            v50 = _mm_shuffle_ps(v49, v49, 225);
            *(__m128*)& pSwapChainDesc.lpstrFileTitle = v50;
            v163 = v50;
            v51 = *(_OWORD*)&pSwapChainDesc.lpstrInitialDir;
            *(float*)&v51 = 1.0;
            *(_OWORD*)&pSwapChainDesc.lpstrInitialDir = v51;
            *(_OWORD*)Buffer = v51;
            v52 = 0;
            v165 = 0;
            v53 = 0;
            v166 = 0;
            v54 = nullptr;
            v167 = nullptr;
            if (!BYTE6(v51))
            {
                v55 = -1;
                do
                    ++v55;
                while (v33[v55]);
                v56 = &v33[v55];
                if (v56 > v33)
                {
                    do
                    {
                        v57 = (unsigned __int64)(v56 - 1);
                        v58 = *(v56 - 1);
                        if (v58 == 47)
                            break;
                        if (v58 == 92)
                            break;
                        --v56;
                    } while (v57 > (unsigned __int64)v33);
                }
                sub_140007510(&Buffer[6], 0x28u, "%s, %.0fpx");
                v54 = v167;
                v53 = v166;
                v52 = v165;
                v51 = *(_OWORD*)Buffer;
                v50 = v163;
                v48 = v162;
                v45 = v161;
                v47 = v160;
                hwndOwner_high = HIDWORD(v159);
            }
            *(_OWORD*)&pSwapChainDesc.hInstance = v47;
            *(_OWORD*)&pSwapChainDesc.lpstrCustomFilter = v45;
            *(_OWORD*)&pSwapChainDesc.lpstrFile = v48;
            *(__m128*)& pSwapChainDesc.lpstrFileTitle = v50;
            *(_OWORD*)&pSwapChainDesc.lpstrInitialDir = v51;
            *(_OWORD*)&pSwapChainDesc.Flags = v52;
            *(_OWORD*)&pSwapChainDesc.lCustData = v53;
            pSwapChainDesc.lpTemplateName = v54;
            *(_QWORD*)&pSwapChainDesc.lStructSize = v44;
            pSwapChainDesc.hwndOwner = (HWND)__PAIR64__(hwndOwner_high, v42);
            HIDWORD(pSwapChainDesc.hInstance) = 1102577664;
            sub_140027660(v32, &pSwapChainDesc);
        }
        else
        {
            fclose(v39);
            if (::Block)
                --*((_DWORD*)::Block + 59);
            free(v44);
        }
    }
    memset(&Msg, 0, sizeof(Msg));
    while (Msg.message != 18)
    {
        if (PeekMessageW(&Msg, nullptr, 0, 0, 1u))
        {
            TranslateMessage(&Msg);
            DispatchMessageW(&Msg);
        }
        else
        {
            if (::Block)
                v59 = *((_QWORD*)::Block + 19);
            else
                v59 = 0;
            if (!*(_QWORD*)(v59 + 72))
                sub_14002C950();
            sub_14002D6B0();
            sub_14000AF30();
            sub_140005A90();
            if ((_QWORD)xmmword_1400460E0)
            {
                v60 = sub_1400095B0(*((_QWORD*)::Block + 1989), "###PopupNotification");
                sub_140014AA0(v60);
                if ((unsigned __int8)sub_140014FD0("###PopupNotification"))
                {
                    v61 = (char*)&qword_1400460D0;
                    if (*((_QWORD*)&xmmword_1400460E0 + 1) >= 0x10u)
                        v61 = qword_1400460D0;
                    sub_1400301E0(v61);
                    v140 = 1137180672;
                    if ((unsigned __int8)sub_140030850("OK", &v140, 0))
                    {
                        v62 = &qword_1400460D0;
                        if (*((_QWORD*)&xmmword_1400460E0 + 1) >= 0x10u)
                            v62 = (char**)qword_1400460D0;
                        *(_QWORD*)&xmmword_1400460E0 = 0;
                        *(_BYTE*)v62 = 0;
                        sub_140014F10();
                    }
                    v63 = ::Block;
                    v64 = *((_QWORD*)::Block + 1989);
                    if (*((_QWORD*)::Block + 2055) == v64 && *((_BYTE*)::Block + 16533) && !*((_DWORD*)::Block + 4125))
                        *((_DWORD*)::Block + 4134) |= 2u;
                    if ((*(_DWORD*)(v64 + 12) & 0x1000000) != 0)
                        v63[15798] = 1;
                    sub_140012BD0();
                    v63[15798] = 0;
                }
            }
            v65 = ::Block;
            *((_DWORD*)::Block + 4052) = 1140457472;
            v65[4053] = 1125449728;
            v65[4046] = 1;
            v65[4044] |= 3u;
            *((_QWORD*)v65 + 2024) = 0;
            *((_QWORD*)v65 + 2025) = 0;
            v65[4045] = 1;
            sub_140010840("MainWindow", 0, 39);
            sub_140030020("Module Name:");
            sub_140013FB0();
            if (pszPath)
            {
                FileNameA = PathFindFileNameA(pszPath);
                sub_1400301E0(FileNameA);
            }
            v67 = ::Block;
            sub_140013FB0();
            v68 = v67[3566];
            v67[3566] = 0;
            *(_QWORD*)pFeatureLevels = 0;
            v69 = sub_140030850("Select Module", pFeatureLevels, 0x8000);
            v67[3566] = v68;
            if (v69)
            {
                v70 = (CHAR*)operator new(0x104u);
                *(&pSwapChainDesc.lStructSize + 1) = 0;
                memset(&pSwapChainDesc.hInstance, 0, 28);
                memset(&pSwapChainDesc.nMaxFile + 1, 0, 20);
                memset(&pSwapChainDesc.lpstrTitle, 0, 64);
                pSwapChainDesc.lStructSize = 152;
                pSwapChainDesc.hwndOwner = hWnd;
                pSwapChainDesc.lpstrFile = v70;
                *v70 = 0;
                pSwapChainDesc.nMaxFile = 260;
                pSwapChainDesc.nFilterIndex = 1;
                pSwapChainDesc.lpstrInitialDir = nullptr;
                pSwapChainDesc.Flags = 530436;
                if (GetOpenFileNameA(&pSwapChainDesc))
                {
                    lpstrFile = pSwapChainDesc.lpstrFile;
                    if (pSwapChainDesc.lpstrFile)
                    {
                        FileA = CreateFileA(pSwapChainDesc.lpstrFile, 0x80000000, 1u, nullptr, 3u, 0x80u, nullptr);
                        v74 = FileA;
                        if (FileA != (HANDLE)-1LL
                            && (FileMappingW = CreateFileMappingW(FileA, nullptr, 2u, 0, 0, nullptr), (v76 = FileMappingW) != nullptr)
                            && (v77 = MapViewOfFile(FileMappingW, 4u, 0, 0, 0)) != nullptr
                            && (CloseHandle(v74), CloseHandle(v76), *v77 == 23117))
                        {
                            pszPath = lpstrFile;
                        }
                        else
                        {
                            sub_140002D70(v73, "Selected file is not a valid NT executable", 42);
                        }
                    }
                }
            }
            sub_140030020("Process Name/ID:");
            sub_140013FB0();
            sub_140014060();
            *(_QWORD*)pFeatureLevel = 0;
            sub_140033590((unsigned int)"##ProcessNameOrIDInput", 0, (unsigned int)Destination, 51, (__int64)pFeatureLevel);
            v130[0] = 0;
            v130[1] = 1084227584;
            sub_1400316B0(v130);
            v131[0] = 1139474432;
            v131[1] = 1108082688;
            if ((unsigned __int8)sub_140030850("Inject Module", v131, 0))
            {
                if (pszPath)
                {
                    *(_OWORD*)String = 0;
                    v149 = 0;
                    v150 = 0;
                    v79 = -1;
                    do
                        ++v79;
                    while (Destination[v79]);
                    sub_1400022F0(String, Destination, v79);
                    if (v149)
                    {
                        v81 = errno();
                        v82 = v81;
                        v83 = (const char*)String;
                        if (v150 >= 0x10)
                            v83 = String[0];
                        *v81 = 0;
                        v84 = strtol(v83, &EndPtr, 10);
                        if (v83 == EndPtr)
                            std::_Xinvalid_argument("invalid stoi argument");
                        if (*v82 == 34)
                            std::_Xout_of_range("stoi argument out of range");
                        v137 = v127;
                        *(_OWORD*)v127 = 0;
                        v128 = 0;
                        v129 = 7;
                        LOWORD(v127[0]) = 0;
                        *(_OWORD*)v124 = 0;
                        v125 = 0;
                        v126 = 0;
                        v85 = -1;
                        do
                            ++v85;
                        while (pszPath[v85]);
                        sub_1400022F0(v124, pszPath, v85);
                        sub_140002590(v124, v127, v84);
                    }
                    else
                    {
                        sub_140002D70(v80, "You must provide a process name/id", 34);
                    }
                    if (v150 >= 0x10)
                    {
                        v86 = String[0];
                        if (v150 + 1 >= 0x1000)
                        {
                            v86 = *((char**)String[0] - 1);
                            if ((unsigned __int64)(String[0] - v86 - 8) > 0x1F)
                                invalid_parameter_noinfo_noreturn();
                        }
                        j_j_free(v86);
                    }
                }
                else
                {
                    sub_140002D70(v78, "You must select a module first", 30);
                }
            }
            PerformanceCount.QuadPart = 0x41F0000043EB0000LL;
            if ((unsigned __int8)sub_140030850("About", &PerformanceCount, 0))
            {
                v87 = sub_1400095B0(*((_QWORD*)::Block + 1989), "About TMI###AboutPopup");
                sub_140014AA0(v87);
            }
            if ((unsigned __int8)sub_140014FD0("About TMI###AboutPopup"))
            {
                *(_OWORD*)v127 = 0;
                v128 = 0;
                v129 = 0;
                sub_1400022F0(v127, "14:08:24", 8);
                *(_OWORD*)Src = 0;
                v122 = 0;
                v123 = 0;
                sub_1400022F0(Src, "Feb 24 2023", 11);
                v88 = v122;
                if (v123 - v122 < 0x1B)
                {
                    v91 = (void**)sub_140005740(Src, "Author: TnyavnTo\nCompiled: ", 0x1Bu);
                }
                else
                {
                    v122 += 27;
                    v89 = Src;
                    if (v123 >= 0x10)
                        v89 = (void**)Src[0];
                    if ("" <= (char*)v89 || "Author: TnyavnTo\nCompiled: " > (char*)v89 + v88)
                    {
                        v90 = 27;
                    }
                    else if (v89 > (void**)"Author: TnyavnTo\nCompiled: ")
                    {
                        v90 = (char*)v89 - "Author: TnyavnTo\nCompiled: ";
                    }
                    else
                    {
                        v90 = 0;
                    }
                    memmove((char*)v89 + 27, v89, v88 + 1);
                    memcpy(v89, "Author: TnyavnTo\nCompiled: ", v90);
                    memcpy((char*)v89 + v90, &aAuthorTnyavnto[v90 + 27], 27 - v90);
                    v91 = Src;
                }
                *(_OWORD*)v132 = 0;
                v133 = 0u;
                *(_OWORD*)v132 = *(_OWORD*)v91;
                v133 = *((_OWORD*)v91 + 1);
                v91[2] = nullptr;
                v91[3] = (void*)15;
                *(_BYTE*)v91 = 0;
                v92 = sub_140002CF0(v132);
                *(_OWORD*)&pSwapChainDesc.lStructSize = *(_OWORD*)v92;
                *(_OWORD*)&pSwapChainDesc.hInstance = *(_OWORD*)(v92 + 16);
                *(_QWORD*)(v92 + 16) = 0;
                *(_QWORD*)(v92 + 24) = 15;
                *(_BYTE*)v92 = 0;
                sub_140005550(v124, v93, &pSwapChainDesc, v127);
                v94 = sub_140002CF0(v124);
                *(_OWORD*)Format = 0;
                v155 = 0u;
                *(_OWORD*)Format = *(_OWORD*)v94;
                v155 = *(_OWORD*)(v94 + 16);
                *(_QWORD*)(v94 + 16) = 0;
                *(_QWORD*)(v94 + 24) = 15;
                *(_BYTE*)v94 = 0;
                if (v126 >= 0x10)
                {
                    v95 = v124[0];
                    if (v126 + 1 >= 0x1000)
                    {
                        v95 = *((void**)v124[0] - 1);
                        if ((unsigned __int64)((char*)v124[0] - (char*)v95 - 8) > 0x1F)
                            invalid_parameter_noinfo_noreturn();
                    }
                    j_j_free(v95);
                }
                v125 = 0;
                v126 = 15;
                LOBYTE(v124[0]) = 0;
                if (pSwapChainDesc.lpstrFilter >= (LPCSTR)0x10)
                {
                    v96 = *(void**)&pSwapChainDesc.lStructSize;
                    if ((unsigned __int64)(pSwapChainDesc.lpstrFilter + 1) >= 0x1000)
                    {
                        v96 = *(void**)(*(_QWORD*)&pSwapChainDesc.lStructSize - 8LL);
                        if ((unsigned __int64)(*(_QWORD*)&pSwapChainDesc.lStructSize - (_QWORD)v96 - 8LL) > 0x1F)
                            invalid_parameter_noinfo_noreturn();
                    }
                    j_j_free(v96);
                }
                if (*((_QWORD*)&v133 + 1) >= 0x10u)
                {
                    v97 = v132[0];
                    if ((unsigned __int64)(*((_QWORD*)&v133 + 1) + 1LL) >= 0x1000)
                    {
                        v97 = *((void**)v132[0] - 1);
                        if ((unsigned __int64)((char*)v132[0] - (char*)v97 - 8) > 0x1F)
                            invalid_parameter_noinfo_noreturn();
                    }
                    j_j_free(v97);
                }
                *(_QWORD*)&v133 = 0;
                *((_QWORD*)&v133 + 1) = 15;
                LOBYTE(v132[0]) = 0;
                if (v123 >= 0x10)
                {
                    v98 = Src[0];
                    if (v123 + 1 >= 0x1000)
                    {
                        v98 = *((void**)Src[0] - 1);
                        if ((unsigned __int64)((char*)Src[0] - (char*)v98 - 8) > 0x1F)
                            invalid_parameter_noinfo_noreturn();
                    }
                    j_j_free(v98);
                }
                v122 = 0;
                v123 = 15;
                LOBYTE(Src[0]) = 0;
                if (v129 >= 0x10)
                {
                    v99 = v127[0];
                    if (v129 + 1 >= 0x1000)
                    {
                        v99 = *((void**)v127[0] - 1);
                        if ((unsigned __int64)((char*)v127[0] - (char*)v99 - 8) > 0x1F)
                            invalid_parameter_noinfo_noreturn();
                    }
                    j_j_free(v99);
                }
                v100 = (char*)Format;
                if (*((_QWORD*)&v155 + 1) >= 0x10u)
                    v100 = Format[0];
                sub_1400301E0(v100);
                Frequency.QuadPart = 1140457472;
                if ((unsigned __int8)sub_140030850("Close", &Frequency, 0))
                    sub_140014F10();
                if (*((_QWORD*)&v155 + 1) >= 0x10u)
                {
                    v101 = Format[0];
                    if ((unsigned __int64)(*((_QWORD*)&v155 + 1) + 1LL) >= 0x1000)
                    {
                        v101 = *((char**)Format[0] - 1);
                        if ((unsigned __int64)(Format[0] - v101 - 8) > 0x1F)
                            invalid_parameter_noinfo_noreturn();
                    }
                    j_j_free(v101);
                }
            }
            sub_140012BD0();
            sub_14000D9D0();
            ((void(__fastcall*)(ID3D11DeviceContext*, __int64, __int64*))ppImmediateContext->lpVtbl->OMSetRenderTargets)(
                ppImmediateContext,
                1,
                &qword_140046AE8);
            v102 = 0;
            if (*(_BYTE*)(**((_QWORD**)::Block + 2054) + 72LL))
                v102 = **((_QWORD**)::Block + 2054) + 72LL;
            sub_14002BEE0(v102);
            if (((unsigned int(__fastcall*)(IDXGISwapChain*, __int64, _QWORD))ppSwapChain->lpVtbl->Present)(
                ppSwapChain,
                1,
                (unsigned int)dword_140046AC0) == 142213121)
            {
                dword_140046AC0 = 1;
                Sleep(0x32u);
            }
            else
            {
                dword_140046AC0 = 0;
            }
        }
    }
    v103 = ::Block;
    if (::Block)
        v104 = *((_QWORD**)::Block + 19);
    else
        v104 = nullptr;
    sub_14002CE90(v36, v35, v37, v38);
    v105 = v104[2];
    if (v105)
        (*(void(__fastcall**)(__int64))(*(_QWORD*)v105 + 16LL))(v105);
    if (*v104)
        (*(void(__fastcall**)(_QWORD))(*(_QWORD*)*v104 + 16LL))(*v104);
    v106 = v104[1];
    if (v106)
        (*(void(__fastcall**)(__int64))(*(_QWORD*)v106 + 16LL))(v106);
    v103[17] = 0;
    v103[19] = 0;
    if (::Block)
        --*((_DWORD*)::Block + 59);
    free(v104);
    v107 = ::Block;
    if (::Block)
        v108 = *((_QWORD**)::Block + 18);
    else
        v108 = nullptr;
    v109 = (char*)::Block + 8;
    v110 = (HMODULE)v108[6];
    if (v110)
    {
        FreeLibrary(v110);
        v107 = ::Block;
    }
    *((_QWORD*)v109 + 15) = 0;
    *((_QWORD*)v109 + 17) = 0;
    if (v107)
        --v107[59];
    free(v108);
    v111 = ::Block;
    sub_14000C430(::Block);
    v116 = ::Block;
    if (::Block == v111)
        v116 = nullptr;
    ::Block = v116;
    if (v111)
    {
        sub_14001BD80(v111);
        if (::Block)
            --*((_DWORD*)::Block + 59);
        free(v111);
    }
    sub_1400058D0(v113, v112, v114, v115);
    DestroyWindow(hWnd);
    UnregisterClassW(v142.lpszClassName, v142.hInstance);
    if (v157 >= 0x10)
    {
        v117 = (CHAR*)lpMultiByteStr[0];
        if (v157 + 1 >= 0x1000)
        {
            v117 = *((CHAR**)lpMultiByteStr[0] - 1);
            if ((unsigned __int64)(lpMultiByteStr[0] - (LPCCH)v117 - 8) > 0x1F)
                invalid_parameter_noinfo_noreturn();
        }
        j_j_free(v117);
    }
    lpMultiByteStr[2] = nullptr;
    v157 = 15;
    LOBYTE(lpMultiByteStr[0]) = 0;
    if (v153 >= 8)
    {
        v118 = (WCHAR*)lpWindowName[0];
        if (2 * v153 + 2 >= 0x1000)
        {
            v118 = *((WCHAR**)lpWindowName[0] - 1);
            if ((unsigned __int64)((char*)lpWindowName[0] - (char*)v118 - 8) > 0x1F)
                goto LABEL_237;
        }
        j_j_free(v118);
    }
    v152 = 0;
    v153 = 7;
    LOWORD(lpWindowName[0]) = 0;
    if (v147 >= 0x10)
    {
        v119 = v145[0];
        if (v147 + 1 >= 0x1000)
        {
            v119 = *((void**)v145[0] - 1);
            if ((unsigned __int64)((char*)v145[0] - (char*)v119 - 8) > 0x1F)
                goto LABEL_242;
        }
        j_j_free(v119);
    }
    return 0;
}
char __fastcall sub_140030850(__int64 a1, _QWORD* a2, int a3)
{
    void* v3; // rbx
    __int64 v7; // rsi
    unsigned int v8; // eax
    __int64 v9; // r8
    void* v10; // r9
    unsigned int v11; // r15d
    unsigned __int8* v12; // rdx
    _BYTE* v13; // rcx
    float v14; // xmm1_4
    float v15; // xmm4_4
    float v16; // xmm8_4
    float v17; // xmm7_4
    float v18; // xmm2_4
    float v19; // xmm0_4
    int v20; // ecx
    char v21; // si
    __int64 v22; // rcx
    int v23; // eax
    int v24; // r9d
    _QWORD* v25; // rax
    float v26; // xmm3_4
    float v27; // xmm2_4
    char v29; // [rsp+48h] [rbp-29h] BYREF
    char v30; // [rsp+49h] [rbp-28h] BYREF
    float v31; // [rsp+50h] [rbp-21h] BYREF
    float v32; // [rsp+54h] [rbp-1Dh]
    float v33; // [rsp+58h] [rbp-19h]
    float v34; // [rsp+5Ch] [rbp-15h]
    __m128 v35; // [rsp+60h] [rbp-11h] BYREF
    float v36; // [rsp+70h] [rbp-1h] BYREF
    float v37; // [rsp+74h] [rbp+3h]
    float v38; // [rsp+78h] [rbp+7h]
    float v39; // [rsp+7Ch] [rbp+Bh]

    v3 = Block;
    *(_BYTE*)(*((_QWORD*)Block + 1989) + 144LL) = 1;
    v7 = *((_QWORD*)v3 + 1989);
    if (*(_BYTE*)(v7 + 147))
        return 0;
    v8 = sub_1400095B0(v7, a1);
    v10 = Block;
    v11 = v8;
    v12 = (unsigned __int8*)a1;
    if (a1 != -1)
    {
        do
        {
            v9 = *v12;
            if (!(_BYTE)v9)
                break;
            v13 = v12 + 1;
            if ((_BYTE)v9 == 35 && *v13 == 35)
                break;
            ++v12;
        } while (v13 != (_BYTE*)-1LL);
    }
    v14 = *((float*)Block + 3814);
    if ((unsigned __int8*)a1 == v12)
    {
        v15 = 0.0;
    }
    else
    {
        sub_14002A550(*((_QWORD*)Block + 1906), (unsigned int)&v31, v9, (_DWORD)Block, -1082130432, a1, (__int64)v12);
        v14 = v32;
        v15 = (float)(int)(float)(v31 + 0.99998999);
    }
    v16 = *(float*)(v7 + 216);
    v17 = *(float*)(v7 + 220);
    v34 = v14;
    v33 = v15;
    if ((a3 & 0x8000) != 0)
    {
        v18 = *((float*)v3 + 3566);
        v19 = *(float*)(v7 + 272);
        if (v19 > v18)
            v17 = v17 + (float)(v19 - v18);
    }
    sub_140014110(&v31, *a2, v9, v10);
    v36 = v16;
    v37 = v17;
    v38 = v16 + v31;
    v39 = v17 + v32;
    sub_140013CE0(&v31);
    if (!(unsigned __int8)sub_140013E30(&v36, v11, 0, 0))
        return 0;
    v20 = a3 | 0x400;
    if ((*((_DWORD*)v3 + 4029) & 2) == 0)
        v20 = a3;
    v21 = sub_1400302A0((unsigned int)&v36, v11, (unsigned int)&v29, (unsigned int)&v30, v20);
    if (v30 && v29)
        v22 = 23;
    else
        v22 = (v29 != 0) + 21LL;
    v35 = *((__m128*)Block + v22 + 900);
    v35.m128_f32[3] = _mm_shuffle_ps(v35, v35, 255).m128_f32[0] * *((float*)Block + 3550);
    sub_140008B90(&v36, v11, 1);
    v23 = sub_140007B20(&v35);
    LOBYTE(v24) = 1;
    sub_1400089F0(LODWORD(v36), LODWORD(v38), v23, v24, *((_DWORD*)v3 + 3567));
    if (*((_BYTE*)v3 + 21332))
    {
        v25 = Block;
        *((_QWORD*)Block + 2671) = "[";
        v25[2672] = "]";
    }
    v26 = *((float*)v3 + 3565);
    v27 = *((float*)v3 + 3566);
    v31 = v38 - v26;
    v35.m128_f32[0] = v26 + v36;
    v32 = v39 - v27;
    v35.m128_f32[1] = v27 + v37;
    sub_140008750(&v35, &v31, a1);
    return v21;
}
void __noreturn sub_1400011E0()
{
    std::_Xlength_error("string too long");
}
LRESULT __fastcall sub_1400059C0(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    if (sub_14002DEE0(hWnd))
        return 1;
    if (Msg == 2)
    {
        PostQuitMessage(0);
    }
    else
    {
        if (Msg != 5)
            return DefWindowProcW(hWnd, Msg, wParam, lParam);
        if (ppDevice && wParam != 1)
        {
            if (qword_140046AE8)
            {
                (*(void(__fastcall**)(__int64))(*(_QWORD*)qword_140046AE8 + 16LL))(qword_140046AE8);
                qword_140046AE8 = 0;
            }
            ((void(__fastcall*)(IDXGISwapChain*, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD))ppSwapChain->lpVtbl->ResizeBuffers)(
                ppSwapChain,
                0,
                (unsigned __int16)lParam,
                WORD1(lParam),
                0,
                0);
            sub_140005950();
        }
    }
    return 0;
}
void __fastcall sub_140002590(SIZE_T* a1, _QWORD* a2, DWORD th32ProcessID)
{
    __int64 v6; // r8
    __int64 v7; // rcx
    bool v8; // si
    void* v9; // rcx
    const char* v10; // rdx
    __int64 v11; // r8
    unsigned __int64 v12; // rdx
    _QWORD* v13; // rcx
    unsigned __int64 v14; // rdx
    _QWORD* v15; // rcx
    HANDLE Toolhelp32Snapshot; // rax
    void* v17; // r14
    unsigned __int64 v18; // rcx
    unsigned __int64 v19; // r10
    char* v20; // r9
    unsigned __int64 v21; // r8
    WCHAR* szExeFile; // rdx
    signed __int64 v23; // r9
    unsigned __int64 v24; // rcx
    unsigned __int64 v25; // r10
    char* v26; // r9
    unsigned __int64 v27; // r8
    WCHAR* v28; // rdx
    signed __int64 v29; // r9
    HANDLE v30; // rax
    void* v31; // rbp
    void* v32; // rax
    void* v33; // r14
    _QWORD* v34; // r8
    HANDLE RemoteThread; // rax
    void* v36; // r15
    void* Block[2]; // [rsp+40h] [rbp-2B8h] BYREF
    __int128 v38; // [rsp+50h] [rbp-2A8h]
    SIZE_T* v39; // [rsp+60h] [rbp-298h]
    _QWORD* v40; // [rsp+68h] [rbp-290h]
    DWORD ExitCode[4]; // [rsp+70h] [rbp-288h] BYREF
    PROCESSENTRY32W pe; // [rsp+80h] [rbp-278h] BYREF

    v39 = a1;
    v40 = a2;
    *(_OWORD*)Block = 0;
    v38 = 0;
    v6 = -1;
    do
        ++v6;
    while (pszPath[v6]);
    sub_1400022F0(Block, pszPath, v6);
    v8 = (unsigned __int8)sub_1400023F0(Block) == 0;
    if (*((_QWORD*)&v38 + 1) >= 0x10u)
    {
        v9 = Block[0];
        if ((unsigned __int64)(*((_QWORD*)&v38 + 1) + 1LL) >= 0x1000)
        {
            v9 = *((void**)Block[0] - 1);
            if ((unsigned __int64)((char*)Block[0] - (char*)v9 - 8) > 0x1F)
                invalid_parameter_noinfo_noreturn();
        }
        j_j_free(v9);
    }
    if (v8)
    {
        pszPath = nullptr;
        v10 = "Selected module was deleted";
    LABEL_10:
        v11 = 27;
        goto LABEL_11;
    }
    if (a2[2])
    {
        pe.dwSize = 568;
        th32ProcessID = 0;
        Toolhelp32Snapshot = CreateToolhelp32Snapshot(2u, 0);
        v17 = Toolhelp32Snapshot;
        if (Toolhelp32Snapshot == (HANDLE)-1LL)
        {
        LABEL_71:
            v11 = 20;
            v10 = "Invalid Process Name";
            goto LABEL_11;
        }
        Process32FirstW(Toolhelp32Snapshot, &pe);
        v18 = -1;
        do
            ++v18;
        while (pe.szExeFile[v18]);
        v19 = a2[2];
        v20 = (char*)a2;
        if (a2[3] >= 8u)
            v20 = (char*)*a2;
        v21 = a2[2];
        if (v18 < v19)
            v21 = v18;
        szExeFile = pe.szExeFile;
        if (v21)
        {
            v23 = v20 - (char*)pe.szExeFile;
            while (*(WCHAR*)((char*)szExeFile + v23) == *szExeFile)
            {
                ++szExeFile;
                if (!--v21)
                    goto LABEL_34;
            }
        }
        else
        {
        LABEL_34:
            if (v19 >= v18 && v19 <= v18)
                th32ProcessID = pe.th32ProcessID;
        }
        while (Process32NextW(v17, &pe))
        {
            v24 = -1;
            do
                ++v24;
            while (pe.szExeFile[v24]);
            v25 = a2[2];
            v26 = (char*)a2;
            if (a2[3] >= 8u)
                v26 = (char*)*a2;
            v27 = a2[2];
            if (v24 < v25)
                v27 = v24;
            v28 = pe.szExeFile;
            if (v27)
            {
                v29 = v26 - (char*)pe.szExeFile;
                while (*(WCHAR*)((char*)v28 + v29) == *v28)
                {
                    ++v28;
                    if (!--v27)
                        goto LABEL_48;
                }
            }
            else
            {
            LABEL_48:
                if (v25 >= v24 && v25 <= v24)
                    th32ProcessID = pe.th32ProcessID;
            }
        }
        CloseHandle(v17);
    }
    if (!th32ProcessID)
        goto LABEL_71;
    v30 = OpenProcess(0x1FFFFFu, 0, th32ProcessID);
    v31 = v30;
    if (v30)
    {
        v32 = VirtualAllocEx(v30, nullptr, a1[2], 0x3000u, 4u);
        v33 = v32;
        if (v32)
        {
            v34 = a1;
            if (a1[3] >= 0x10)
                v34 = (_QWORD*)*a1;
            if (!WriteProcessMemory(v31, v32, v34, a1[2], nullptr))
            {
                v10 = "WriteProcessMemory() Failed";
                goto LABEL_10;
            }
            RemoteThread = CreateRemoteThread(v31, nullptr, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, v33, 0, nullptr);
            v36 = RemoteThread;
            if (!RemoteThread)
            {
                v10 = "CreateRemoteThread() Failed";
                goto LABEL_10;
            }
            WaitForSingleObject(RemoteThread, 0xFFFFFFFF);
            ExitCode[0] = 0;
            GetExitCodeThread(v36, ExitCode);
            CloseHandle(v36);
            if (VirtualFreeEx(v31, v33, 0, 0x8000u))
            {
                CloseHandle(v31);
                if (ExitCode[0])
                {
                    v11 = 28;
                    v10 = "Module Successfully Injected";
                }
                else
                {
                    v11 = 23;
                    v10 = "Injecting Module Failed";
                }
            }
            else
            {
                v11 = 22;
                v10 = "VirtualFreeEx() Failed";
            }
        }
        else
        {
            v11 = 23;
            v10 = "VirtualAllocEx() Failed";
        }
    }
    else if (GetLastError() == 87)
    {
        v11 = 26;
        v10 = "Invalid process identifier";
    }
    else
    {
        v11 = 46;
        v10 = "OpenProcess() Failed. Try to run TMI elevated?";
    }
LABEL_11:
    sub_140002D70(v7, v10, v11);
    v12 = a1[3];
    if (v12 >= 0x10)
    {
        v13 = (_QWORD*)*a1;
        if (v12 + 1 >= 0x1000)
        {
            if ((unsigned __int64)v13 - *(v13 - 1) - 8 > 0x1F)
                invalid_parameter_noinfo_noreturn();
            v13 = (_QWORD*)*(v13 - 1);
        }
        j_j_free(v13);
    }
    a1[2] = 0;
    a1[3] = 15;
    *(_BYTE*)a1 = 0;
    v14 = a2[3];
    if (v14 >= 8)
    {
        v15 = (_QWORD*)*a2;
        if (2 * v14 + 2 >= 0x1000)
        {
            if ((unsigned __int64)v15 - *(v15 - 1) - 8 > 0x1F)
                invalid_parameter_noinfo_noreturn();
            v15 = (_QWORD*)*(v15 - 1);
        }
        j_j_free(v15);
    }
    *(_WORD*)a2 = 0;
    a2[3] = 7;
    a2[2] = 0;
}
char** __fastcall sub_140002D70(__int64 a1, const void* a2, size_t a3)
{
    unsigned __int64 v3; // rbp
    char** v6; // rbx
    __int64 v7; // rdi
    __int64 v8; // rdx
    size_t v9; // rcx
    void* v10; // rax
    _QWORD* v11; // rbx
    char* v12; // rcx

    v3 = *((_QWORD*)&xmmword_1400460E0 + 1);
    if (a3 > *((_QWORD*)&xmmword_1400460E0 + 1))
    {
        v7 = 0x7FFFFFFFFFFFFFFFLL;
        if (a3 > 0x7FFFFFFFFFFFFFFFLL)
            sub_1400011E0();
        if ((a3 | 0xF) <= 0x7FFFFFFFFFFFFFFFLL)
        {
            v8 = *((_QWORD*)&xmmword_1400460E0 + 1) >> 1;
            if (*((_QWORD*)&xmmword_1400460E0 + 1) <= (unsigned __int64)(0x7FFFFFFFFFFFFFFFLL
                - (*((_QWORD*)&xmmword_1400460E0 + 1) >> 1)))
            {
                v7 = a3 | 0xF;
                if ((a3 | 0xF) < v8 + *((_QWORD*)&xmmword_1400460E0 + 1))
                    v7 = v8 + *((_QWORD*)&xmmword_1400460E0 + 1);
            }
        }
        v9 = v7 + 1;
        if (v7 == -1)
            v9 = -1;
        if (v9 < 0x1000)
        {
            if (v9)
                v11 = operator new(v9);
            else
                v11 = nullptr;
        }
        else
        {
            if (v9 + 39 < v9)
                sub_140001140();
            v10 = operator new(v9 + 39);
            if (!v10)
                goto LABEL_26;
            v11 = (_QWORD*)(((unsigned __int64)v10 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
            *(v11 - 1) = v10;
        }
        *(_QWORD*)&xmmword_1400460E0 = a3;
        *((_QWORD*)&xmmword_1400460E0 + 1) = v7;
        memcpy(v11, a2, a3);
        *((_BYTE*)v11 + a3) = 0;
        if (v3 < 0x10)
        {
        LABEL_24:
            qword_1400460D0 = (char*)v11;
            return &qword_1400460D0;
        }
        v12 = qword_1400460D0;
        if (v3 + 1 < 0x1000)
        {
        LABEL_23:
            j_j_free(v12);
            goto LABEL_24;
        }
        if ((unsigned __int64)&qword_1400460D0[-*((_QWORD*)qword_1400460D0 - 1) - 8] <= 0x1F)
        {
            v12 = *((char**)qword_1400460D0 - 1);
            goto LABEL_23;
        }
    LABEL_26:
        invalid_parameter_noinfo_noreturn();
    }
    *(_QWORD*)&xmmword_1400460E0 = a3;
    v6 = &qword_1400460D0;
    if (*((_QWORD*)&xmmword_1400460E0 + 1) >= 0x10u)
        v6 = (char**)qword_1400460D0;
    memmove(v6, a2, a3);
    *((_BYTE*)v6 + a3) = 0;
    return &qword_1400460D0;
}
void* __fastcall sub_1400022F0(_QWORD* a1, const void* a2, size_t a3)
{
    __int64 v3; // rdi
    void* result; // rax
    size_t v8; // rax
    void* v9; // rax
    _QWORD* v10; // rsi

    v3 = 0x7FFFFFFFFFFFFFFFLL;
    if (a3 > 0x7FFFFFFFFFFFFFFFLL)
        sub_1400011E0();
    a1[3] = 15;
    if (a3 < 0x10)
    {
        a1[2] = a3;
        result = memmove(a1, a2, a3);
        *((_BYTE*)a1 + a3) = 0;
        return result;
    }
    if ((a3 | 0xF) > 0x7FFFFFFFFFFFFFFFLL)
    {
        v8 = 0x8000000000000027uLL;
    LABEL_6:
        v9 = operator new(v8);
        if (!v9)
            invalid_parameter_noinfo_noreturn();
        v10 = (_QWORD*)(((unsigned __int64)v9 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
        *(v10 - 1) = v9;
        goto LABEL_17;
    }
    v3 = a3 | 0xF;
    if ((a3 | 0xF) < 0x16)
        v3 = 22;
    if ((unsigned __int64)(v3 + 1) >= 0x1000)
    {
        v8 = v3 + 40;
        if (v3 + 40 < (unsigned __int64)(v3 + 1))
            sub_140001140();
        goto LABEL_6;
    }
    if (v3 == -1)
        v10 = nullptr;
    else
        v10 = operator new(v3 + 1);
LABEL_17:
    *a1 = v10;
    a1[2] = a3;
    a1[3] = v3;
    result = memcpy(v10, a2, a3);
    *((_BYTE*)v10 + a3) = 0;
    return result;
}


