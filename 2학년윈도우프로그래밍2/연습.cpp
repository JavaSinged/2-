#include<Windows.h>
#include<tchar.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstacne, LPSTR lpszCmdline, int iCmdShow) {
	WNDCLASS wc;
	HWND hwnd;
	MSG msg;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = _T("클래스 이름");
	RegisterClass(&wc);
	hwnd = CreateWindow(_T("클래스 이름"), _T("타이틀 이름"), WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL,0,0))
	{
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}