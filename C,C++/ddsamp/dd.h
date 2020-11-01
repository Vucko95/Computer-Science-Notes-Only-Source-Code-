/*--------------------------------------------------------------------------*/
#ifndef _DD_H_
#define _DD_H_
/*--------------------------------------------------------------------------*/
#include <ddraw.h>
/*--------------------------------------------------------------------------*/
// Variables
/*--------------------------------------------------------------------------*/
extern LPDIRECTDRAW        g_pDD;        // The DirectDraw object
extern LPDIRECTDRAWCLIPPER g_pClipper;   // Clipper for primary surface
extern LPDIRECTDRAWSURFACE g_pDDS;       // Primary surface
extern LPDIRECTDRAWSURFACE g_pDDSBack;   // Back surface
extern HWND                g_hWnd;       // To store the main windows handle
extern bool                g_bFullScreen; // Full-screen mode?

extern int                 g_iBpp;     // Remember the main surface bit depth
/*--------------------------------------------------------------------------*/
// Functions
/*--------------------------------------------------------------------------*/

//-- Housekeeping

// Initialize basic DirectDraw stuff
extern bool DDInit( HWND hWnd );
// Create surfaces
extern bool DDCreateSurfaces( bool bFullScreen);
// Destroy surfaces
extern void DDDestroySurfaces();
// Clean up DirectDraw stuff
extern void DDDone();
// Checks if the memory associated with surfaces is lost and restores if necessary.
extern void CheckSurfaces();


//-- Drawing

// PutPixel routine for a DirectDraw surface
extern void DDPutPixel( LPDIRECTDRAWSURFACE pDDS, int x, int y, int r, int g, int b );
// Create color from RGB triple
extern unsigned int CreateRGB( int r, int g, int b );
// Clear a surface area with black
extern void DDClear( LPDIRECTDRAWSURFACE pDDS, int x1, int y1, int x2, int y2 );
// Double buffering flip
extern void DDFlip();

//--- Error checking stuff
extern bool  DDFailedCheck(HRESULT hr, char *szMessage);
extern char *DDErrorString(HRESULT hr);

/*--------------------------------------------------------------------------*/
#endif
/*--------------------------------------------------------------------------*/
