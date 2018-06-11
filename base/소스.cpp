#include<Windows.h>
#include<tchar.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//���� �κ�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	//1. ������ Ŭ���� ����
	WNDCLASS wndclass;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = (WNDPROC)WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = _T("ClassName");
	//wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	//2. ������ Ŭ���� ���
	RegisterClass(&wndclass);
	//3. ������ ����
	HWND hwnd = CreateWindow(_T("ClassName"), _T("���� �׸��ϰ� �ʹ�"),
		WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	//4. �޼��� ó��
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}

}

//�޼��� ó���κ�
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) { //window == wnd // LRESULT == �ڷ��� ������
																			   /*
																			   5. �޼��� ó�� �Լ�*/
	HDC hdc;
	PAINTSTRUCT ps;
	switch (iMsg)
	{
	case WM_CREATE: break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		Ellipse(hdc, 0, 0, 800, 600);
		EndPaint(hwnd, &ps); break;
	case WM_DESTROY: PostQuitMessage(0); break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}