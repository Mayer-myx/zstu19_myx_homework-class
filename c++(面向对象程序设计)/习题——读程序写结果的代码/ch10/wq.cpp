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


//保存屏幕客户区的宽和高的变量
	int xClient,yClient;

//在窗口中产生随机大小随机颜色的矩形区域
void DrawRectangle(HWND hwnd)
{
	HBRUSH hBrush;
	HDC hdc;

	//(xLeft,yTop)，(xRight,yBotton)保存矩形图形的左上角座标他和右下角座标
	//nRed,nGreen,nBlue 保存3基色
	//rand()是VC++的随机函数，产生一个随机整数

	int xLeft,xRight,yTop,yBotton,nRed,nGreen,nBlue;
	xLeft=rand() % xClient; 	yTop=rand() % yClient;
	xRight=rand() % xClient;    yBotton=rand() % yClient;
	nRed=rand() & 255;          nGreen=rand() & 255;	nBlue=rand() & 255;			
	hdc=GetDC(hwnd);	  //获取当前窗口的输出设备环境
	hBrush=CreateSolidBrush(RGB(nRed,nGreen,nBlue)); //创建画图的画笔
	SelectObject(hdc,hBrush);  //将创建的画笔指定给当前窗口的设备

	//利用创建的彩色画笔，在设备上绘制一个矩形
	Rectangle(hdc,min(xLeft,xRight),min(yTop,yBotton),max(xLeft,xRight),max(yTop,yBotton));
	ReleaseDC(hwnd,hdc);//释放设备环境
	DeleteObject(hBrush);//释放画笔

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	//x,y用于保存鼠标点击的屏幕座标，LUP是鼠标左键按下与释放的开关，在释放鼠标左键时，创建彩色的矩形
	static int x=10,y=10;
	static BOOL LUP=FALSE;
	switch (message) 
	{
		
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			RECT rt;
			GetClientRect(hWnd, &rt);	
			if (LUP)			//如果按下的鼠标左键释放了，就在屏幕上画一随机的矩形
			{
				DrawRectangle(hWnd);
				LUP=FALSE;
			}
			EndPaint(hWnd, &ps);
			break;
		case WM_LBUTTONDOWN:
			x=LOWORD(lParam);	y=HIWORD(lParam);
			break;
		case WM_LBUTTONUP://释放鼠标产生的消息，通过LUP设置，在屏幕上画采色的矩形
			LUP=TRUE;
			InvalidateRect(hWnd,NULL,TRUE);
			break;

		case WM_RBUTTONDOWN:
			hdc=GetDC(hWnd);
			x=LOWORD(lParam);	y=HIWORD(lParam);
			TextOut(hdc,x,y,"其实消息处理很简单！",20);
 		    break;
		case WM_SIZE:     //窗口大小变时产生此消息，屏幕的长和宽保存在lParam附加消息中
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
