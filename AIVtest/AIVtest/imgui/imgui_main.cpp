
#include "imgui_main.h"
#include "sun.h"
// Data
static ID3D11Device* g_pd3dDevice = nullptr;
static ID3D11DeviceContext* g_pd3dDeviceContext = nullptr;
static IDXGISwapChain* g_pSwapChain = nullptr;
static UINT                     g_ResizeWidth = 0, g_ResizeHeight = 0;
static ID3D11RenderTargetView* g_mainRenderTargetView = nullptr;

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Main code
int imgui_main()
{
    
    // Create application window
    ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEXW wc = { sizeof(wc), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"ImGui Example", nullptr };
    ::RegisterClassExW(&wc);
    HWND hwnd = ::CreateWindowW(wc.lpszClassName, L"涟漪 破解是吧 群597942640", WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, nullptr, nullptr, wc.hInstance, nullptr);

    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    ::ShowWindow(hwnd, SW_HIDE);      // 隐藏
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
    io.ConfigViewportsNoAutoMerge = true; 
    
    ImGui::Stylelianyi();

  
    ImGuiWindowFlags window_flags = 0;
    bool p_open = true;
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.FrameRounding = 6.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    
    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

    ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\msyh.ttc", 18.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull());

    // Our state

    ImVec4 clear_color = ImVec4(0.20f, 0.40f, 0.60f, 1.00f);

    // Main loop

    Sun* sun = &Sun::Get();
 
    bool done = false;
 
    const char* move[] = {"Sendinput","Ghub","km-b/b+","RX78","km-net"};
  
    //等待卸载的时间
    int xiezaitime = 0;
    bool dengdai = false;
    int ttt = 0;
    int haoshi = 0;
    while (!done)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // See the WndProc() function below for our to dispatch events to the Win32 backend.
        MSG msg;
        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;

        // Handle window resize (we don't resize directly in the WM_SIZE handler)
        if (g_ResizeWidth != 0 && g_ResizeHeight != 0)
        {
            CleanupRenderTarget();
            g_pSwapChain->ResizeBuffers(0, g_ResizeWidth, g_ResizeHeight, DXGI_FORMAT_UNKNOWN, 0);
            g_ResizeWidth = g_ResizeHeight = 0;
            CreateRenderTarget();
        }

        // Start the Dear ImGui frame    启动 Dear ImGui 框架
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        //代码区============================================================================================
      
            ImGui::Begin(u8"涟漪se 老子免费 倒狗我操死你的妈",&p_open, window_flags);
            if (!p_open) {
                sun->exit_main = true;
                return 0;
            }
            ImGui::TextColored(ImColor(150, 250, 180, 240), u8" 破解是吧 软件免费 ");
            ImGui::TextColored(ImColor(150, 250, 180, 240), u8" 著作权归属 群 597942640. ");
            ImGui::TextColored(ImColor(150, 250, 180, 240), u8" 老子免费 倒狗我操死你的妈 ");
            if (sun->ingAI) {
                if (ImGui::Button(u8"结束线程")) {
                    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.26f, 0.59f, 0.90f, 0.50f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.26f, 0.59f, 0.98f, 0.9f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.06f, 0.53f, 0.98f, 0.9f));
                    ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(1.0f, 0.85f, 0.0f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, ImVec4(1.0f, 0.85f, 0.0f, 1.0f));
                    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.5f, 0.5f, 0.5f, 1.0f)); // 边框  
                    ImGui::PushStyleColor(ImGuiCol_BorderShadow, ImVec4(0.00f, 0.00f, 0.00f, 0.00f)); // 边框阴影

                    sun->stopAI = true;
                    dengdai = true;
                }
                
                ImGui::Checkbox(u8"监视器", &sun->jianshiqi);
                
            }
            else {
                ImGui::Combo(u8"模型文件", &sun->mode_llist, sun->wenjian_show, IM_ARRAYSIZE(sun->wenjian_show));
                if (dengdai) {
                    ImGui::TextColored(ImColor(150, 250, 180, 240), u8" 请稍等，正在清理并复位 著作权归属 群 597942640. ");
                    ImGui::TextColored(ImColor(150, 250, 180, 240), u8" 卸载屏幕监控器 ...... ");
                    xiezaitime++;
                    if (xiezaitime > 600) {
                        xiezaitime = 0;
                        dengdai = false;
                    }
                }
                else {
                    if (ImGui::Button(u8"开始线程")) {
                        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.16f, 0.65f, 0.60f, 0.50f));
                        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.16f, 0.65f, 0.60f, 0.9f));
                        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.06f, 0.53f, 0.50f, 0.9f));
                        ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(0.2f, 0.75f, 0.6f, 0.7f));
                        ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, ImVec4(0.2f, 0.75f, 0.6f, 1.0f));
                        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.16f, 0.65f, 0.60f, 1.0f)); // 边框  
                        ImGui::PushStyleColor(ImGuiCol_BorderShadow, ImVec4(0.16f, 0.65f, 0.60f, 0.00f)); // 边框阴影

                        sun->beginAI = true;
                    }
                    //ImGui::Combo(u8"监视方式", &sun->jietufangshi, jietu, IM_ARRAYSIZE(jietu));
                    ImGui::Checkbox(u8"自动分辨率", &sun->autofenbianlv);
                    if (!sun->autofenbianlv) {
                        ImGui::TextColored(ImColor(150, 250, 180, 240), u8" 破解是吧 软件免费 ");
                        ImGui::TextColored(ImColor(150, 250, 180, 240), u8" 著作权归属 群 597942640.asd ");

                        ImGui::InputText(" width  ", sun->shuru_w, IM_ARRAYSIZE(sun->shuru_w));
                        ImGui::InputText(" height ", sun->shuru_h, IM_ARRAYSIZE(sun->shuru_h));
                    }
                    
                }
            }
            
            ImGui::Checkbox(u8"瞄准总开关 ", &sun->miaozhun);
            ImGui::SameLine();   //使在同一行
            ImGui::TextColored(ImColor(130, 130, 130, 255), u8" } 大括号快捷切换");
            ImGui::TextColored(ImColor(150, 250, 180, 240), u8" 破解是吧 软件免费 ");
            ImGui::TextColored(ImColor(150, 250, 180, 240), u8" 免费软件 我看哪个小笨蛋还花钱买 ");

            ImGui::Checkbox(u8"控制台窗口", &sun->cmd_window);
            ImGui::SliderFloat(u8"偏移量", &sun->head_y, -0.5, 0.5);
            ImGui::SliderFloat(u8"置信度", &sun->conf, 0.1, 1);
            //ImGui::SliderFloat(u8"iou", &sun->iou, 0.1, 1);
            ImGui::SliderFloat(u8"范围", &sun->fanwei, -1, sun->mid, "%.0f");
            ImGui::Checkbox(u8"启用分类", &sun->qiyongfenlei);
            if (sun->qiyongfenlei) {
                ImGui::SliderFloat(u8"类别", &sun->fenlei, 0, 3, "%.0f");
            }
            ImGui::Combo("", &sun->move_llist, move, IM_ARRAYSIZE(move));
            if (sun->move_llist == 1) {
                ImGui::SameLine();
                if (sun->lg_ok) {
                    ImGui::TextColored(ImColor(50, 200, 180, 255), "LG-OK");
                }
                else {
                    ImGui::TextColored(ImColor(200, 50, 50, 255), "LG-NO");
                }
            }
            else if (sun->move_llist == 2 ) {
                ImGui::SameLine();
                if (sun->usb_ok) {
                    ImGui::TextColored(ImColor(50, 200, 180, 255), "BOX-OK");
                }
                else {
                    ImGui::TextColored(ImColor(200, 50, 50, 255), "BOX-NO");
                }
                ImGui::SliderFloat(u8"COM", &sun->usb_num, 0, 128, "%.0f");
                ImGui::SliderFloat(u8"波特率", &sun->usb_botelv, 100000, 115200, "%10.f");
                ImGui::SliderFloat(u8"曲线拟合数", &sun->kmbox_nihe, 1, 10, "%.0f");
                if (ImGui::Button(u8"链接kmbox")) {
                    sun->usb_lianjie = true;
                }
                
            }
            else if (sun->move_llist == 3) {
                ImGui::InputText(u8"RX序列号", sun->rxID, IM_ARRAYSIZE(sun->rxID));
                if (ImGui::Button(u8"链接RX")) {
                    sun->RX_lianjie = true;
                }
            }
            else if (sun->move_llist == 4) {
                ImGui::SameLine();
                if (sun->net_ok) {
                    ImGui::TextColored(ImColor(50, 200, 180, 255), "Net-OK");
                }
                else {
                    ImGui::TextColored(ImColor(200, 50, 50, 255), "Net-NO");
                }
                ImGui::InputText(" IP ", sun->net_ip, IM_ARRAYSIZE(sun->net_ip));
                ImGui::InputText(" port ", sun->net_port, IM_ARRAYSIZE(sun->net_port));
                ImGui::InputText(" mac ", sun->net_mac, IM_ARRAYSIZE(sun->net_mac));
                if (ImGui::Button(u8"链接km-net")) {
                    sun->net_lianjie = true;
                }
            }
            ImGui::TextColored(ImColor(255, 255, 255, 255), u8" 瞄准热键 ");
            // 自瞄按键
            ImGui::Checkbox(u8"左", &sun->zuojian);
            ImGui::SameLine();  
            ImGui::Checkbox(u8"右", &sun->youjian);
            ImGui::SameLine();  
            ImGui::Checkbox(u8"中", &sun->zhongjian);
            ImGui::SameLine();  
            ImGui::Checkbox(u8"侧1", &sun->cejian1);
            ImGui::SameLine();  
            ImGui::Checkbox(u8"侧2", &sun->cejian2);

            // 扳机热键
            ImGui::TextColored(ImColor(255, 255, 255, 255), u8" 扳机热键 ");
            ImGui::SliderFloat(u8"前摇间隔", &sun->qiantime, 0, 300, "%.0f");
            ImGui::SliderFloat(u8"激活间隔", &sun->zhongtime, 0, 300, "%.0f");
            ImGui::Checkbox("all ##b", &sun->bjall);
            ImGui::SameLine();
            ImGui::Checkbox(u8"右##b", &sun->bjyoujian);
            ImGui::SameLine();
            ImGui::Checkbox(u8"中##b", &sun->bjzhongjian);
            ImGui::SameLine();
            ImGui::Checkbox(u8"侧1##b", &sun->bjcejian1);
            ImGui::SameLine();
            ImGui::Checkbox(u8"侧2##b", &sun->bjcejian2);


            ImGui::TextColored(ImColor(255, 255, 255, 255), u8"X轴 控制 越大越慢");
            ImGui::SliderFloat(u8"平滑##X", &sun->X_pid_d, 0, 2.0);
            ImGui::TextColored(ImColor(255, 255, 255, 255), u8"Y轴 控制 愈大越慢");
            ImGui::SliderFloat(u8"平滑##Y", &sun->Y_pid_d, 0, 2.0);
            ImGui::Checkbox(u8"启用压枪", &sun->yaqiang_on);
            if (sun->yaqiang_on) {
                ImGui::SliderFloat(u8"柔软", &sun->yaqiang_xiumian, 1, 50, "%.0f");
                ImGui::SliderFloat(u8"峰值", &sun->yaqiang_zuida, 0, 160, "%.0f");
            }
            ImGui::End();
        
        
        
        

        //============================================================================================================

        // Rendering
        ImGui::Render();
        const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
        g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, nullptr);
        g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

        // Update and Render additional Platform Windows
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        g_pSwapChain->Present(1, 0); // Present with vsync
        //g_pSwapChain->Present(0, 0); // Present without vsync
    }

    // Cleanup
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);

    return 0;
}

// Helper functions
bool CreateDeviceD3D(HWND hWnd)
{
    // Setup swap chain
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 2;
    sd.BufferDesc.Width = 0;
    sd.BufferDesc.Height = 0;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    UINT createDeviceFlags = 0;
    //createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
    D3D_FEATURE_LEVEL featureLevel;
    const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
    HRESULT res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext);
    if (res == DXGI_ERROR_UNSUPPORTED) // Try high-performance WARP software driver if hardware is not available.
        res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_WARP, nullptr, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext);
    if (res != S_OK)
        return false;

    CreateRenderTarget();
    return true;
}

void CleanupDeviceD3D()
{
    CleanupRenderTarget();
    if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = nullptr; }
    if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = nullptr; }
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = nullptr; }
}

void CreateRenderTarget()
{
    ID3D11Texture2D* pBackBuffer;
    g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
    g_pd3dDevice->CreateRenderTargetView(pBackBuffer, nullptr, &g_mainRenderTargetView);
    pBackBuffer->Release();
}

void CleanupRenderTarget()
{
    if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = nullptr; }
}

#ifndef WM_DPICHANGED
#define WM_DPICHANGED 0x02E0 // From Windows SDK 8.1+ headers
#endif

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (wParam == SIZE_MINIMIZED)
            return 0;
        g_ResizeWidth = (UINT)LOWORD(lParam); // Queue resize
        g_ResizeHeight = (UINT)HIWORD(lParam);
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    case WM_DPICHANGED:
        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_DpiEnableScaleViewports)
        {
            //const int dpi = HIWORD(wParam);
            //printf("WM_DPICHANGED to %d (%.0f%%)\n", dpi, (float)dpi / 96.0f * 100.0f);
            const RECT* suggested_rect = (RECT*)lParam;
            ::SetWindowPos(hWnd, nullptr, suggested_rect->left, suggested_rect->top, suggested_rect->right - suggested_rect->left, suggested_rect->bottom - suggested_rect->top, SWP_NOZORDER | SWP_NOACTIVATE);
        }
        break;
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}
