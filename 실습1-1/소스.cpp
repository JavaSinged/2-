#include<Windows.h>
#include<tchar.h>
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM IParam);
 int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevlnst, LPSTR lpszCmdLine, int nCmdShow) {
	 //������ Ŭ���� ����
	 WNDCLASS wc;
	 wc.cbClsExtra = 0; //Ŭ������ ���� ����
	 wc.cbWndExtra = 0;
	 wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	 wc.hCursor = LoadCursor(NULL, IDC_HAND);
	 wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	 wc.hInstance = hInst;
	 wc.lpfnWndProc = WndProc;
	 wc.lpszClassName = _T("ClassName");
	 wc.lpszMenuName = NULL;
	 wc.style = CS_HREDRAW | CS_VREDRAW;

	//������ Ŭ���� ���
	 RegisterClass(&wc); //�ּҰ����� ���
	 HWND hWnd = CreateWindow(
		 //Ŭ���� �̸�, Ÿ��Ʋ �̸�, ������ ��Ÿ��
		 _T("ClassName"), _T("TitleName"), WS_OVERLAPPEDWINDOW,
		 100, 100, 800, 600,
		 NULL, NULL, hInst, NULL);
	 ShowWindow(hWnd, nCmdShow);
	 UpdateWindow(hWnd);
	 MSG msg;
	 while (GetMessage(&msg, NULL, 0, 0)) {
		 DispatchMessage(&msg);
	 }

	 return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hWnd,UINT iMsg, WPARAM wParam, LPARAM IParam) { //<-�ܿ���
	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd,iMsg,wParam,IParam);
}