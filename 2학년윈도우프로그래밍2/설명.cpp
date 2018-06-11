#include<Windows.h>
#include<tchar.h>
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow) {
	WNDCLASS wc;
	HWND hwnd;
	MSG msg;
	wc.style = CS_HREDRAW | CS_VREDRAW;//�����찡 ��µǴ� ����
	wc.cbClsExtra = 0;//Ŭ������ ���� ������ �޸� ũ��
	wc.cbWndExtra = 0;//�����츦 ���� ������ �޸� ũ��
	wc.hInstance = hInstance;//WinMain()�Լ��� ù ��° �ް������� �Ѿ�� ���� ���α׷� �ν��Ͻ� ���� �Ѱ��ش�.
	wc.lpfnWndProc = WndProc;//�޽��� ó���� ���� �Լ��� �̸��� �����Ѵ�.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//�⺻ Ŀ�������� �̿�ȴ�.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//�⺻ ������ ������ ���ȴ�.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//�������� ������ �����Ѵ�.
	wc.lpszMenuName = NULL;//�޴��� �̸��� ����.
	wc.lpszClassName = _T("WINDOWCLASS");//�������� Ŭ���� �̸��� ���ڿ� Ÿ������ ����. �����츦 ���� �� �� �̸��� ����ϹǷ� �� ����ؾ� �Ѵ�.
	RegisterClass(&wc);//Ŀ�ο� ������ ���
	hwnd = CreateWindow(_T("WINDOWCLASS"), _T("is me"), WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hInstance, NULL);
	/*�������� �⺻���� �������
	1.�������� Ŭ���� �̸��� �˷��ش� �����ڵ�� ��ȯ�Ͽ��� �ϱ� ������ _T��ũ�θ� �̿��Ѵ�.
	2.������� �������� Ÿ��Ʋ �ٿ� ��Ÿ�� �̸��̴�.
	3.���ǵ� ������ ��Ÿ�� �� ������� ������ �� ������ �ϴ� �������� Ÿ��Ʋ �ٿ� �ּ�ȭ �ִ�ȭ �ݱ� ��ư�� �ְ� ���콺 ������ ��ư�� ��������� �޴��� ��µǵ��� ���ִ� WS_OVERLAPPEDWINDOW �� ����Ͽ���.
	4.������ �����찡 ��� ��ġ�� ���ð����� x,y��
	5.�����Ǵ� �������� ���� �����̴�.
	6.���߿� �˷��شٴϱ� ��ġ�� �̰� �ܿ��.
	*/
	ShowWindow(hwnd, iCmdShow);//�����츦 ����Ѵ�.
	UpdateWindow(hwnd);//�����쿡 WM_PAINT�޼����� �����Ƿ� ������ ȭ�鿡 �⺻ ����� �ϵ��� �Ѵ�.
					   /*�޼��� ó�� ���
					   Ű���峪 ���콺���� �̺�Ʈ �߻�->�߻��� �̺�Ʈ�� OS�� ����->�̺�Ʈ �߻��� �˸� �̺�Ʈ�� �˸��� ����� �������� �޼����� ������ ����� ���Ѵ� ���� ������ �޼����� ���ʷ� ť�� ���δ�.
					   ->WinMain()�Լ��� �޼��� ť���� �� �տ� ������� �޼����� ������.->���� �޼����� �ؼ��Ͽ� ó�� �Լ��� ������->ó���ؾ� �� �޼����� ���� ������ �޼��� ť�� �����ǰ� �ݺ��ؼ� �ϳ��� ���ʴ�� ó���Ѵ�.
					   ->GetMessage�Լ����� �޼��� ť���� �޼����� ������.->���� �޼����� msg�Լ��� �����ϰ�TranslateMessage()�Լ��� �����Ѵ�.->DispatchMessage()�Լ��� �޼����� ó���ϴ� �Լ��� �޼����� ������
					   ->�޼��� ó���Լ� ������WndProc()�Լ��� �޼����� �ް� ó���Ѵ�->������ ȭ�鿡 ����Ѵ�.*/
	while (GetMessage(&msg, NULL, 0, 0)) {

		DispatchMessage(&msg);
	}
	return(int)msg.wParam;

}
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	/*HWND=������ ������ �ڵ� ���̴� WinMain()�Լ��� CreateWindow()�Լ��� �̿��Ͽ� �����Ѵ�.
	iMsg=���� ������UINTŸ���� �޼��� ��ȣ�̴�. �޼�����ȣ���� ���� ���������� ���α׷��Ӱ� �� �̺�Ʈ�� ���� ���ڸ� ����ϱ� ��Ʊ� ������ ��ũ�θ� �̿��� ����ϱ� ���� �����ߴ�.
	WPARAM,LPARAM=32��Ʈ ������ �޼����� ������ ���� ���� �ؼ��ϴ� ����� �ٸ���.*/
	switch (iMsg) {//�޼����� ������ ���� ó���ؾ� �ϹǷ� CASE�� ������. ������ �޼����� Ŀ���� ó���Ҽ��� �ֱ� ������ DefWindowProc�� �Ѱ��ش�.
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
	return DefWindowProc(hWnd, iMsg, wParam, lParam);//�����쿡�� �߻��ϴ� �޼��� �� ������ �޼��� ó�� �Լ����� ó������ ���� ���� �⺻ �޼��� ó�� �Լ����� ����ϵ��� �Ѵ�.
	 //�⺻ �޼��� ó�� �Լ� ���п� �����쿡�� �߻��ϴ� ��� �޼����� ó���� �� �ִ�.
}