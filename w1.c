#include <Windows.h>

long FAR PASCAL WndProc(HWND hwnd, WORD messae, WORD wParam, LONG lParam);

int PASCAL WinMain(HANDLE hInstance, HANDLE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
  HWND hwnd;
  MSG msg;
  WNDCLASS wc;
  if (!hPrevInstance)
  {
    wc.style = NULL;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "Class_W1";
    RegisterClass(&wc);
  }
  hwnd = CreateWindow
  (
    "Class_W1",
    "Hello, World - Windows style",
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    NULL,
    NULL,
    hInstance,
    NULL
  );
  ShowWindow(hwnd, nCmdShow);
  UpdateWindow(hwnd);
  while(GetMessage(&msg, NULL, NULL, NULL))
    DispatchMessage(&msg);
  return msg.wParam;
}

long FAR PASCAL WndProc(HWND hwnd, WORD message, WORD wParam, LONG lParam)
{
  switch (message)
  {
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProc(hwnd, message, wParam, lParam);
  }

  return NULL;
}
