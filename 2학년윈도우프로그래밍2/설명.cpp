#include<Windows.h>
#include<tchar.h>
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow) {
	WNDCLASS wc;
	HWND hwnd;
	MSG msg;
	wc.style = CS_HREDRAW | CS_VREDRAW;//윈도우가 출력되는 형태
	wc.cbClsExtra = 0;//클래스를 위한 여분의 메모리 크기
	wc.cbWndExtra = 0;//윈도우를 위한 여분의 메모리 크기
	wc.hInstance = hInstance;//WinMain()함수에 첫 번째 메개변수로 넘어온 응용 프로그램 인스턴스 값을 넘겨준다.
	wc.lpfnWndProc = WndProc;//메시지 처리에 사용될 함수의 이름을 기제한다.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//기본 커서설정에 이용된다.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//기본 아이콘 설정에 사용된다.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//윈도우의 배경색을 지정한다.
	wc.lpszMenuName = NULL;//메뉴의 이름을 쓴다.
	wc.lpszClassName = _T("WINDOWCLASS");//윈도우의 클래스 이름을 문자영 타입으로 쓴다. 윈도우를 만들 때 이 이름을 사용하므로 꼭 기억해야 한다.
	RegisterClass(&wc);//커널에 윈도우 등록
	hwnd = CreateWindow(_T("WINDOWCLASS"), _T("is me"), WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hInstance, NULL);
	/*윈도우의 기본적인 설정들로
	1.윈도우의 클래스 이름을 알려준다 유니코드로 변환하여야 하기 때문에 _T메크로를 이용한다.
	2.만들어질 윈도우의 타이틀 바에 나타낼 이름이다.
	3.정의된 윈도우 스타일 값 가운데에서 선택할 수 있지만 일단 기초적인 타이틀 바에 최소화 최대화 닫기 버튼이 있고 마우스 오른쪽 버튼을 눌렀을경우 메뉴가 출력되도록 되있는 WS_OVERLAPPEDWINDOW 를 사용하였다.
	4.생성된 윈도우가 어느 위치에 나올것인지 x,y축
	5.생성되는 윈도우의 폭과 높이이다.
	6.나중에 알려준다니까 닥치고 이건 외운다.
	*/
	ShowWindow(hwnd, iCmdShow);//윈도우를 출력한다.
	UpdateWindow(hwnd);//윈도우에 WM_PAINT메세지를 보내므로 윈도우 화면에 기본 출력을 하도록 한다.
					   /*메세지 처리 방법
					   키보드나 마우스에서 이벤트 발생->발생한 이벤트를 OS가 감지->이벤트 발생을 알림 이벤트를 알리는 방법중 정수값인 메세지를 보내는 방식을 텍한다 이후 보내온 메세지가 차례로 큐에 쌓인다.
					   ->WinMain()함수가 메세지 큐에서 맨 앞에 대기중인 메세지를 꺼낸다.->꺼낸 메세지를 해석하여 처리 함수로 보낸다->처리해야 할 메세지가 많기 때문에 메세지 큐에 보관되고 반복해서 하나씩 차례대로 처리한다.
					   ->GetMessage함수에서 메세지 큐에서 메세지를 꺼낸다.->꺼낸 메세지는 msg함수에 저장하고TranslateMessage()함수로 변형한다.->DispatchMessage()함수는 메세지를 처리하는 함수에 메세지를 보낸다
					   ->메세지 처리함수 지금은WndProc()함수가 메세지를 받고 처리한다->윈도우 화면에 출력한다.*/
	while (GetMessage(&msg, NULL, 0, 0)) {

		DispatchMessage(&msg);
	}
	return(int)msg.wParam;

}
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	/*HWND=생성된 윈도우 핸들 값이다 WinMain()함수의 CreateWindow()함수를 이용하여 생성한다.
	iMsg=양의 정수인UINT타입의 메세지 번호이다. 메세지번호값은 양의 정수이지만 프로그래머가 각 이벤트에 따를 숫자를 기억하기 어렵기 때문에 메크로를 이용해 기억하기 쉽게 정의했다.
	WPARAM,LPARAM=32비트 값으로 메세지의 종류에 따라 값을 해석하는 방법이 다르다.*/
	switch (iMsg) {//메세지의 종류에 따라 처리해야 하므로 CASE로 나눈다. 나머지 메세지는 커널이 처리할수도 있기 때문에 DefWindowProc로 넘겨준다.
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);//윈도우에서 발생하는 메세지 중 윈도우 메세지 처리 함수에서 처리하지 않은 것을 기본 메세지 처리 함수에서 담당하도록 한다.
	 //기본 메세지 처리 함수 덕분에 윈도우에서 발생하는 모든 메세지를 처리할 수 있다.
}