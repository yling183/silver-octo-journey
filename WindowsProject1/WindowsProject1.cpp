#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);        //��������������Ϣ�ĺ���

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("MyWindow");
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;        //����һ�����������

    //����Ϊ���������wndclass������
    wndclass.style = CS_HREDRAW | CS_VREDRAW;                         //������ʽ
    wndclass.lpszClassName = szAppName;                               //��������
    wndclass.lpszMenuName = NULL;                                     //���ڲ˵�:��
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);    //���ڱ�����ɫ
    wndclass.lpfnWndProc = WndProc;                                   //���ڴ�����
    wndclass.cbWndExtra = 0;                                          //����ʵ����չ:��
    wndclass.cbClsExtra = 0;                                          //��������չ:��
    wndclass.hInstance = hInstance;                                   //����ʵ�����
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);               //������С��ͼ��:ʹ��ȱʡͼ��
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);                 //���ڲ��ü�ͷ���

    if (!RegisterClass(&wndclass))
    {    //ע�ᴰ����, ���ע��ʧ�ܵ���������ʾ
        MessageBox(NULL, TEXT("����ע��ʧ��"), TEXT("����"), MB_OK | MB_ICONERROR);
        return 0;
    }

    hwnd = CreateWindow(               //��������
        szAppName,                     //��������
        TEXT("�ҵĵ�һ��Windows����"),   //���ڱ���
        WS_OVERLAPPEDWINDOW,           //���ڵķ��
        CW_USEDEFAULT,                 //���ڳ�ʼ��ʾλ��x:ʹ��ȱʡֵ
        CW_USEDEFAULT,                 //���ڳ�ʼ��ʾλ��y:ʹ��ȱʡֵ
        CW_USEDEFAULT,                 //���ڵĿ��:ʹ��ȱʡֵ
        CW_USEDEFAULT,                 //���ڵĸ߶�:ʹ��ȱʡֵ
        NULL,                          //������:��
        NULL,                          //�Ӳ˵�:��
        hInstance,                     //�ô���Ӧ�ó����ʵ����� 
        NULL
    );

    ShowWindow(hwnd, iCmdShow);        //��ʾ����
    UpdateWindow(hwnd);                //���´���

    while (GetMessage(&msg, NULL, 0, 0))        //����Ϣ�����л�ȡ��Ϣ
    {
        TranslateMessage(&msg);                 //���������Ϣת��Ϊ�ַ���Ϣ
        DispatchMessage(&msg);                  //�ַ����ص�����(���̺���)
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;                //�豸�������
    PAINTSTRUCT ps;         //���ƽṹ
    RECT rect;               //���νṹ

    switch (message)        //����õ�����Ϣ
    {
    case WM_PAINT:           //������������Чʱ��������Ϣ
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);
        DrawText(hdc, TEXT("Hello World"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);  //����
        EndPaint(hwnd, &ps);
        return 0;
    case WM_DESTROY:         //�����ڹر�ʱ����Ϣ
        MessageBox(hwnd, TEXT("�رճ���!"), TEXT("����"), MB_OK | MB_YESNOCANCEL);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);        //DefWindowProc���������Զ������Ϣ������û�д�������Ϣ
}

