/*---------------------------------------------------------------
Program Name:  ddsamp : DirectDraw sample
Programmer:    David Joffe
Date:          98/04/18
URL:           http://www.geocities.com/SoHo/Lofts/2018/

  Description:
  Simple DirectDraw sample application
  Licensing:
  This source code and all documents provided with it are
  provided as is, with NO warranty and no guarantees. If it
  does any damage, the responsibility is yours. There are
  no restrictions on what you may do with this code; but
  the moment you modify it I become completely
  disaffiliated with this program.
  Limitations
  This program does not handle on-the-fly screen depth changing
  Probably many other limitations that a real game shouldn't
  have.
---------------------------------------------------------------*/
#define STRICT
#define WIN32_LEAN_AND_MEAN
/*--------------------------------------------------------------------------*/
#include <windows.h>
#include <windowsx.h>
#include "dd.h"
#include "resource.h"
/*--------------------------------------------------------------------------*/
// Function declarations
LRESULT CALLBACK WndProc( HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam );
BOOL             Register( HINSTANCE hInst );
HWND             Create( int nCmdShow, int w, int h );

// Message handlers
void OnDestroy(HWND hwnd);
void OnCommand(HWND hWnd, int iID, HWND hwndCtl, UINT uNotifyCode);
void OnPaint(HWND hwnd);

void HeartBeat();

// Globals
static char      g_szAppName[] = "DDSamp";
static HWND      g_hwndMain;
static HINSTANCE g_hInstance;
       bool      g_bRunning;
/*--------------------------------------------------------------------------*/
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MSG  Msg;
	
	g_hInstance = hInstance;
	
	if (!hPrevInstance) {
		if (!Register( g_hInstance ))
			return FALSE;
	}
	
	// Create the main window
	g_hwndMain = Create( nCmdShow, 320, 240 );
	if (!g_hwndMain)
		return FALSE;  
	
	// Initialize DirectDraw
	if (!DDInit( g_hwndMain ))
	{
		MessageBox( g_hwndMain, "Failed to initialize DirectDraw", "Error", MB_OK );
		return 0;
	}
	
	// Create DirectDraw surfaces
	if (!DDCreateSurfaces( false ))
	{
		MessageBox( g_hwndMain, "Failed to create surfaces", "Error", MB_OK );
		return 0;
	}
	
	// Invalidate window area so that it gets redrawn first time round
	InvalidateRect( g_hwndMain, NULL, TRUE );

	// Main loop
	g_bRunning = true;
	while (g_bRunning)
	{
		while (PeekMessage(&Msg, g_hwndMain, 0, 0, PM_NOREMOVE))
		{
			BOOL bGetResult = GetMessage(&Msg, NULL, 0, 0);
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
			if (bGetResult==0)
				g_bRunning = false;
		}
		if (g_bRunning)
		{
			CheckSurfaces();
			HeartBeat();
		}
	}
	
	// Clean up DirectDraw stuff
	DDDone();
	
	return Msg.wParam;
}
/*--------------------------------------------------------------------------*/
//
// Register the window class
//
BOOL Register(HINSTANCE hInst)
{
	WNDCLASS WndClass;
	
	WndClass.style         = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc   = WndProc;
	WndClass.cbClsExtra    = 0;
	WndClass.cbWndExtra    = 0;
	WndClass.hInstance     = hInst;
	WndClass.hIcon         = LoadIcon(hInst, MAKEINTRESOURCE(IDI_DDICON));
	WndClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	WndClass.lpszMenuName  = NULL/*MAKEINTRESOURCE(IDR_MENU)*/;
	WndClass.lpszClassName = g_szAppName;
	
	return RegisterClass (&WndClass);
}
/*--------------------------------------------------------------------------*/
//
// Create the window
//
HWND Create( int nCmdShow, int w, int h )
{
	RECT rc;
	
	// Calculate size of window based on desired client window size
	rc.left = 0;
	rc.top = 0;
	rc.right = w;
	rc.bottom = h;
	AdjustWindowRect( &rc, WS_OVERLAPPEDWINDOW, FALSE );
	
	HWND hwnd = CreateWindow(g_szAppName, g_szAppName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right-rc.left, rc.bottom-rc.top,
		NULL, NULL, g_hInstance, NULL);
	
	if (hwnd == NULL)
		return hwnd;
	
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	
	return hwnd;
}
/*--------------------------------------------------------------------------*/
// The Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{
		HANDLE_MSG(hwnd, WM_DESTROY, OnDestroy);
		HANDLE_MSG(hwnd, WM_PAINT, OnPaint);
		HANDLE_MSG(hwnd, WM_COMMAND, OnCommand);
	}
	return DefWindowProc(hwnd, Message, wParam, lParam);
}
/*--------------------------------------------------------------------------*/
// Command message handler
void OnCommand(HWND hWnd, int iID, HWND hwndCtl, UINT uNotifyCode)
{
	//switch (iID)
	//{
	//case IDM_QUIT:
	//	OnDestroy(hWnd);
	//	break;
	//}
}
/*--------------------------------------------------------------------------*/
// Handle WM_DESTROY
void OnDestroy(HWND )
{
	g_bRunning = false;
	PostQuitMessage(0);
}
/*--------------------------------------------------------------------------*/
// Window painting function
void OnPaint(HWND hwnd)
{
	// Draw a weird looking color square
/*	int r, g;
	for ( r=0; r<64; r++ )
	{
		for ( g=0; g<64; g++ )
		{
			DDPutPixel( g_pDDS, 4+g, 4+r, r*4, g*4, (63-g)*4 );
		}
	}*/
	
	// Let Windows know we've redrawn the Window - since we've bypassed
	// the GDI, Windows can't figure that out by itself.
	ValidateRect( hwnd, NULL );
	
	// Over here we could do some normal GDI drawing
//	PAINTSTRUCT ps;
//	HDC hdc;
//	HDC hdc = BeginPaint(hwnd, &ps);
//	if (hdc)
//	{
//	}
//	EndPaint(hwnd, &ps);
}
/*--------------------------------------------------------------------------*/
void HeartBeat()
{
	// Check for lost surfaces
	CheckSurfaces();
	
	// Clear the back buffer
	DDClear( g_pDDSBack, 0, 0, 320, 240 );
	
	static int iFoo = 0;
	// Draw a weird looking color square
	for ( int r=0; r<64; r++ )
	{
		for ( int g=0; g<64; g++ )
		{
			DDPutPixel( g_pDDSBack, g, r, (r*2+iFoo)%256, (g+iFoo)%256, (63-g)*4 );
		}
	}
	iFoo++;
	
	// Blit the back buffer to the front buffer
	DDFlip();
}
/*--------------------------------------------------------------------------*/
