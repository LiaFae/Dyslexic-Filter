#include <windows.h>

// Συνάρτηση διαχείρισης μηνυμάτων του παραθύρου
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        
        // Αν ο χρήστης πατήσει Escape, κλείνει η εφαρμογή
        case WM_KEYDOWN:
            if (wParam == VK_ESCAPE) {
                DestroyWindow(hwnd);
            }
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"DyslexiaOverlayClass";

    WNDCLASSW wc = {};
    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClassW(&wc);

    // Δημιουργία παραθύρου χωρίς borders (WS_POPUP) με click-through
    HWND hwnd = CreateWindowExW(
        WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TRANSPARENT,
        CLASS_NAME,
        L"Dyslexia Screen Overlay",
        WS_POPUP,
        0, 0, 
        GetSystemMetrics(SM_CXSCREEN), // Πλάτος οθόνης
        GetSystemMetrics(SM_CYSCREEN), // Ύψος οθόνης
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    // Ορισμός διαφάνειας και χρώματος φόντου (Cornsilk / απαλό παλ ζεστό χρώμα)
    SetLayeredWindowAttributes(hwnd, RGB(255, 248, 220), 45, LWA_COLORKEY | LWA_ALPHA);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Message loop
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}