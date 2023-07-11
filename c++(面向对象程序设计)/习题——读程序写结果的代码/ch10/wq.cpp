// wq.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
#define MAX_LOADSTRING 100

HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
int   WINAPI   WinMain (
				HINSTANCE hInstance, 
				HINSTANCE hPrevInstance,
				PSTR szCmdLine, 
				int iCmdShow)
{
     static TCHAR szAppName[] = TEXT ("HelloWin") ;
     HWND         hwnd ;
     MSG          msg ;
     WNDCLASS     wndclass ;
	 wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = NULL ;
     wndclass.lpszClassName = szAppName ;

     if (!RegisterClass (&wndclass))
     {
          MessageBox (NULL, TEXT ("This program requires Windows NT!"), szAppName, MB_ICONERROR) ;
          return 0 ;
     }

hwnd = CreateWindow (
			szAppName,                  // window class name
                          TEXT ("The Hello Program"), // window caption
                          WS_OVERLAPPEDWINDOW,  // window style
                          CW_USEDEFAULT,              // initial x position
                          CW_USEDEFAULT,              // initial y position
                          CW_USEDEFAULT,              // initial x size
                          CW_USEDEFAULT,              // initial y size
                          NULL,                       // parent window handle
                          NULL,                       // window menu handle
                          hInstance,                  // program instance handle
                          NULL) ;                     // creation parameters
     
     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;

while (GetMessage (&msg, NULL, 0, 0))
     {
          TranslateMessage (&msg) ;
          DispatchMessage (&msg) ;
     }
     return msg.wParam ;
}


//������Ļ�ͻ����Ŀ�͸ߵı���
	int xClient,yClient;

//�ڴ����в��������С�����ɫ�ľ�������
void DrawRectangle(HWND hwnd)
{
	HBRUSH hBrush;
	HDC hdc;

	//(xLeft,yTop)��(xRight,yBotton)�������ͼ�ε����Ͻ������������½�����
	//nRed,nGreen,nBlue ����3��ɫ
	//rand()��VC++���������������һ���������

	int xLeft,xRight,yTop,yBotton,nRed,nGreen,nBlue;
	xLeft=rand() % xClient; 	yTop=rand() % yClient;
	xRight=rand() % xClient;    yBotton=rand() % yClient;
	nRed=rand() & 255;          nGreen=rand() & 255;	nBlue=rand() & 255;			
	hdc=GetDC(hwnd);	  //��ȡ��ǰ���ڵ�����豸����
	hBrush=CreateSolidBrush(RGB(nRed,nGreen,nBlue)); //������ͼ�Ļ���
	SelectObject(hdc,hBrush);  //�������Ļ���ָ������ǰ���ڵ��豸

	//���ô����Ĳ�ɫ���ʣ����豸�ϻ���һ������
	Rectangle(hdc,min(xLeft,xRight),min(yTop,yBotton),max(xLeft,xRight),max(yTop,yBotton));
	ReleaseDC(hwnd,hdc);//�ͷ��豸����
	DeleteObject(hBrush);//�ͷŻ���

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	//x,y���ڱ������������Ļ���꣬LUP���������������ͷŵĿ��أ����ͷ�������ʱ��������ɫ�ľ���
	static int x=10,y=10;
	static BOOL LUP=FALSE;
	switch (message) 
	{
		
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			RECT rt;
			GetClientRect(hWnd, &rt);	
			if (LUP)			//������µ��������ͷ��ˣ�������Ļ�ϻ�һ����ľ���
			{
				DrawRectangle(hWnd);
				LUP=FALSE;
			}
			EndPaint(hWnd, &ps);
			break;
		case WM_LBUTTONDOWN:
			x=LOWORD(lParam);	y=HIWORD(lParam);
			break;
		case WM_LBUTTONUP://�ͷ�����������Ϣ��ͨ��LUP���ã�����Ļ�ϻ���ɫ�ľ���
			LUP=TRUE;
			InvalidateRect(hWnd,NULL,TRUE);
			break;

		case WM_RBUTTONDOWN:
			hdc=GetDC(hWnd);
			x=LOWORD(lParam);	y=HIWORD(lParam);
			TextOut(hdc,x,y,"��ʵ��Ϣ����ܼ򵥣�",20);
 		    break;
		case WM_SIZE:     //���ڴ�С��ʱ��������Ϣ����Ļ�ĳ��Ϳ�����lParam������Ϣ��
			xClient=LOWORD(lParam);
			yClient=HIWORD(lParam);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	  default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}
