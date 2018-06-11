#include<Windows.h>
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = CreateSolidBrush(RGB(255, 0, 0));
	wc.hCursor = LoadCursor(NULL, IDC_HAND);
	wc.hIcon = LoadIcon(NULL, IDI_HAND);
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = L"ClassName";
	wc.lpszMenuName = NULL;
	RegisterClass(&wc);
	HWND hWnd = CreateWindow(L"ClassName", L"윈도우 하기 싫어", WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hInstance,NULL);
	ShowWindow(hWnd,iCmdShow);
	UpdateWindow(hWnd);
	MSG msg;
	while (GetMessage(&msg,NULL,0,0))
	{
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	switch (iMsg) {
	case WM_CREATE:break;
	case WM_PAINT:hdc = BeginPaint(hWnd, &ps); break;
	case WM_DESTROY:PostQuitMessage(0); break;
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}