#include<Windows.h>
#include<tchar.h>
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 255));
	wc.hCursor = LoadCursor(NULL, IDC_HAND);
	wc.hIcon = LoadIcon(NULL, IDI_HAND);
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = L"ClassName";
	wc.lpszMenuName = NULL;
	RegisterClass(&wc);
	HWND hWnd = CreateWindow(L"ClassName", L"Hello World", WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hInstance, NULL);
	ShowWindow(hWnd, iCmdShow);
	UpdateWindow(hWnd);
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;

	switch (iMsg) {
	case WM_CREATE:break;
	case WM_CHAR:
		hdc = GetDC(hWnd);
		TextOut(hdc, 100, 100, L"일어나~일어나~다시 한번 해보는 거야~",wcslen(L"일어나~일어나~다시 한번 해보는 거야~"));
		ReleaseDC(hWnd, hdc);
		break;
	case WM_DESTROY:PostQuitMessage(0); break;
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}