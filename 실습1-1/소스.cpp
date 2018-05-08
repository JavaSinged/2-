#include<Windows.h>
#include<tchar.h>
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM IParam);
 int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevlnst, LPSTR lpszCmdLine, int nCmdShow) {
	 //윈도우 클래스 생성
	 WNDCLASS wc;
	 wc.cbClsExtra = 0; //클래스의 여분 공간
	 wc.cbWndExtra = 0;
	 wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	 wc.hCursor = LoadCursor(NULL, IDC_HAND);
	 wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	 wc.hInstance = hInst;
	 wc.lpfnWndProc = WndProc;
	 wc.lpszClassName = _T("ClassName");
	 wc.lpszMenuName = NULL;
	 wc.style = CS_HREDRAW | CS_VREDRAW;

	//윈도우 클래스 등록
	 RegisterClass(&wc); //주소값으로 등록
	 HWND hWnd = CreateWindow(
		 //클래스 이름, 타이틀 이름, 윈도우 스타일
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
LRESULT CALLBACK WndProc(HWND hWnd,UINT iMsg, WPARAM wParam, LPARAM IParam) { //<-외우자
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