#include "lib.cpp"

// //функция обработки сообщение окна
// LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
//     switch(uMsg){
//         case WM_CLOSE:
//             DestroyWindow(hwnd);
//             break;
//         case WM_DESTROY:
//             PostQuitMessage(0);
//             break;
//         default:
//             return DefWindowProc(hwnd, uMsg,wParam, lParam);        
//     }
//     return 0;
// }

// int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
// {
//     // Определение класса окна
//     WNDCLASS wc = {};
//     wc.lpfnWndProc = WindowProc; // Установка процедуры окна
//     wc.hInstance = hInstance;
//     wc.lpszClassName = _T("MyWindowClass");

//     // Регистрация класса окна
//     RegisterClass(&wc);

//     // Создание окна
//     HWND hwnd = CreateWindowEx(
//         0,
//         _T("MyWindowClass"), // Имя зарегистрированного класса окна
//         _T("TIMER LEARN"), // Заголовок окна
//         WS_OVERLAPPEDWINDOW, // Стиль окна
//         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, // Положение и размеры окна
//         NULL, NULL, hInstance, NULL);

//     if (hwnd == NULL)
//     {
//         return 0;
//     }

//     // Отображение окна
//     ShowWindow(hwnd, nCmdShow);

//     // Цикл обработки сообщений
//     MSG msg = {};
//     while (GetMessage(&msg, NULL, 0, 0))
//     {
//         TranslateMessage(&msg);
//         DispatchMessage(&msg);
//     }

//     return 0;
// }

int main(){

    Timer timer{25,"C:/learn.txt"};
    timer.start();

    return 0;
}