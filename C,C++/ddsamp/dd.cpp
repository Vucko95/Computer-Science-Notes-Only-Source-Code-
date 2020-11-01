/*--------------------------------------------------------------------------*/
#include "dd.h"
#include <ddraw.h>
#include <stdio.h>
/*--------------------------------------------------------------------------*/
LPDIRECTDRAW        g_pDD          = NULL;  // The DirectDraw object
LPDIRECTDRAWCLIPPER g_pClipper     = NULL;  // Clipper for primary surface
LPDIRECTDRAWSURFACE g_pDDS         = NULL;  // Primary surface
LPDIRECTDRAWSURFACE g_pDDSBack     = NULL;  // Back surface
HWND                g_hWnd         = NULL;  // To store the main windows handle
bool                g_bFullScreen  = false; // Full-screen mode?

int                 g_iBpp         = 0;     // Remember the main surface bit depth
/*--------------------------------------------------------------------------*/
bool DDFailedCheck(HRESULT hr, char *szMessage)
{
	if (FAILED(hr))
	{
		char buf[1024];
		sprintf( buf, "%s (%s)\n", szMessage, DDErrorString(hr) );
		OutputDebugString( buf );
		return true;
	}
	return false;
}
/*--------------------------------------------------------------------------*/
// Initialize DirectDraw stuff
bool DDInit( HWND hWnd )
{
	HRESULT hr;
	
	g_hWnd = hWnd;
	
	// TODO: Enumerate devices here, get latest interfaces etc.
	
	// Initialize DirectDraw
	hr = DirectDrawCreate( NULL, &g_pDD, NULL );
	if (DDFailedCheck(hr, "DirectDrawCreate failed" ))
		return false;
	
	return true;
}
/*--------------------------------------------------------------------------*/
// Create surfaces
bool DDCreateSurfaces( bool bFullScreen)
{
	HRESULT hr; // Holds return values for DirectX function calls
	
	g_bFullScreen = bFullScreen;
	
	// If we want to be in full-screen mode
	if (g_bFullScreen)
	{
		// Set the "cooperative level" so we can use full-screen mode
		hr = g_pDD->SetCooperativeLevel(g_hWnd, DDSCL_EXCLUSIVE|DDSCL_FULLSCREEN|DDSCL_NOWINDOWCHANGES);
		if (DDFailedCheck(hr, "SetCooperativeLevel"))
			return false;
		
		// Set 640x480x256 full-screen mode
		hr = g_pDD->SetDisplayMode(640, 480, 8);
		if (DDFailedCheck(hr, "SetDisplayMode" ))
			return false;
	}
	else
	{
		// Set DDSCL_NORMAL to use windowed mode
		hr = g_pDD->SetCooperativeLevel(g_hWnd, DDSCL_NORMAL);
		if (DDFailedCheck(hr, "SetCooperativeLevel windowed" ))
			return false;
	}
	
	DDSURFACEDESC ddsd; // A structure to describe the surfaces we want
	// Clear all members of the structure to 0
	memset(&ddsd, 0, sizeof(ddsd));
	// The first parameter of the structure must contain the size of the structure
	ddsd.dwSize = sizeof(ddsd);
	
	if (g_bFullScreen)
	{
		// Screw the full-screen mode (for now) (FIXME)
	}
	else
	{
		
		//-- Create the primary surface
		
		// The dwFlags paramater tell DirectDraw which DDSURFACEDESC
		// fields will contain valid values
		ddsd.dwFlags = DDSD_CAPS;
		ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
		
		hr = g_pDD->CreateSurface(&ddsd, &g_pDDS, NULL);
		if (DDFailedCheck(hr, "Create primary surface"))
			return false;
		
		//-- Create the back buffer
		
		ddsd.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;
		// Make our off-screen surface 320x240
		ddsd.dwWidth = 320;
		ddsd.dwHeight = 240;
		// Create an offscreen surface
		ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
		
		hr = g_pDD->CreateSurface(&ddsd, &g_pDDSBack, NULL);
		if (DDFailedCheck(hr, "Create back surface"))
			return false;
		
	}
	
	
	//-- Create a clipper for the primary surface in windowed mode
	if (!g_bFullScreen)
	{
		
		// Create the clipper using the DirectDraw object
		hr = g_pDD->CreateClipper(0, &g_pClipper, NULL);
		if (DDFailedCheck(hr, "Create clipper"))
			return false;
		
		// Assign your window's HWND to the clipper
		hr = g_pClipper->SetHWnd(0, g_hWnd);
		if (DDFailedCheck(hr, "Assign hWnd to clipper"))
			return false;
		
		// Attach the clipper to the primary surface
		hr = g_pDDS->SetClipper(g_pClipper);
		if (DDFailedCheck(hr, "Set clipper"))
			return false;
	}
	
	
	//-- Lock back buffer to retrieve surface information
	if (g_pDDSBack)
	{
		hr= g_pDDSBack->Lock( NULL, &ddsd, DDLOCK_WAIT, NULL );
		if (DDFailedCheck(hr, "Lock back buffer failed" ))
			return false;
		
		// Store bit depth of surface
		g_iBpp = ddsd.ddpfPixelFormat.dwRGBBitCount;
		
		// Unlock surface
		hr = g_pDDSBack->Unlock( NULL );
		if (DDFailedCheck(hr, "Unlock back buffer failed" ))
			return false;
	}
	
	return true;
}
/*--------------------------------------------------------------------------*/
// Destroy surfaces
void DDDestroySurfaces()
{
}
/*--------------------------------------------------------------------------*/
// Clean up DirectDraw stuff
void DDDone()
{
	if (g_pDD != NULL)
	{
		g_pDD->Release();
		g_pDD = NULL;
	}
}
/*--------------------------------------------------------------------------*/
// PutPixel routine for a DirectDraw surface
void DDPutPixel( LPDIRECTDRAWSURFACE pDDS, int x, int y, int r, int g, int b )
{
	HRESULT hr;
	DDBLTFX ddbfx;
	RECT    rcDest;
	
	// Safety net
	if (pDDS == NULL)
		return;
	
	// Initialize the DDBLTFX structure with the pixel color
	ddbfx.dwSize = sizeof( ddbfx );
	ddbfx.dwFillColor = (DWORD)CreateRGB( r, g, b );
	
	// Prepare the destination rectangle as a 1x1 (1 pixel) rectangle
	SetRect( &rcDest, x, y, x+1, y+1 );
	
	// Blit 1x1 rectangle using solid color op
	hr = pDDS->Blt( &rcDest, NULL, NULL, DDBLT_WAIT | DDBLT_COLORFILL, &ddbfx );
	DDFailedCheck(hr, "Blt failure");
}
/*--------------------------------------------------------------------------*/
// Create color from RGB triple
unsigned int CreateRGB( int r, int g, int b )
{
	switch (g_iBpp)
	{
	case 8:
		// Here you should do a palette lookup to find the closes match.
		// I'm not going to bother with that. Many modern games no
		// longer support 256-color modes, and neither should you :)
		return 0;
	case 16:
		// Break down r,g,b into 5-6-5 format.
		return ((r/8)<<11) | ((g/4)<<5) | (b/8);
	case 24:
	case 32:
		return (r<<16) | (g<<8) | (b);
	}
	return 0;
}
/*--------------------------------------------------------------------------*/
char *DDErrorString(HRESULT hr)
{
	switch (hr)
	{
	case DDERR_ALREADYINITIALIZED:           return "DDERR_ALREADYINITIALIZED";
	case DDERR_CANNOTATTACHSURFACE:          return "DDERR_CANNOTATTACHSURFACE";
	case DDERR_CANNOTDETACHSURFACE:          return "DDERR_CANNOTDETACHSURFACE";
	case DDERR_CURRENTLYNOTAVAIL:            return "DDERR_CURRENTLYNOTAVAIL";
	case DDERR_EXCEPTION:                    return "DDERR_EXCEPTION";
	case DDERR_GENERIC:                      return "DDERR_GENERIC";
	case DDERR_HEIGHTALIGN:                  return "DDERR_HEIGHTALIGN";
	case DDERR_INCOMPATIBLEPRIMARY:          return "DDERR_INCOMPATIBLEPRIMARY";
	case DDERR_INVALIDCAPS:                  return "DDERR_INVALIDCAPS";
	case DDERR_INVALIDCLIPLIST:              return "DDERR_INVALIDCLIPLIST";
	case DDERR_INVALIDMODE:                  return "DDERR_INVALIDMODE";
	case DDERR_INVALIDOBJECT:                return "DDERR_INVALIDOBJECT";
	case DDERR_INVALIDPARAMS:                return "DDERR_INVALIDPARAMS";
	case DDERR_INVALIDPIXELFORMAT:           return "DDERR_INVALIDPIXELFORMAT";
	case DDERR_INVALIDRECT:                  return "DDERR_INVALIDRECT";
	case DDERR_LOCKEDSURFACES:               return "DDERR_LOCKEDSURFACES";
	case DDERR_NO3D:                         return "DDERR_NO3D";
	case DDERR_NOALPHAHW:                    return "DDERR_NOALPHAHW";
	case DDERR_NOCLIPLIST:                   return "DDERR_NOCLIPLIST";
	case DDERR_NOCOLORCONVHW:                return "DDERR_NOCOLORCONVHW";
	case DDERR_NOCOOPERATIVELEVELSET:        return "DDERR_NOCOOPERATIVELEVELSET";
	case DDERR_NOCOLORKEY:                   return "DDERR_NOCOLORKEY";
	case DDERR_NOCOLORKEYHW:                 return "DDERR_NOCOLORKEYHW";
	case DDERR_NODIRECTDRAWSUPPORT:          return "DDERR_NODIRECTDRAWSUPPORT";
	case DDERR_NOEXCLUSIVEMODE:              return "DDERR_NOEXCLUSIVEMODE";
	case DDERR_NOFLIPHW:                     return "DDERR_NOFLIPHW";
	case DDERR_NOGDI:                        return "DDERR_NOGDI";
	case DDERR_NOMIRRORHW:                   return "DDERR_NOMIRRORHW";
	case DDERR_NOTFOUND:                     return "DDERR_NOTFOUND";
	case DDERR_NOOVERLAYHW:                  return "DDERR_NOOVERLAYHW";
	case DDERR_NORASTEROPHW:                 return "DDERR_NORASTEROPHW";
	case DDERR_NOROTATIONHW:                 return "DDERR_NOROTATIONHW";
	case DDERR_NOSTRETCHHW:                  return "DDERR_NOSTRETCHHW";
	case DDERR_NOT4BITCOLOR:                 return "DDERR_NOT4BITCOLOR";
	case DDERR_NOT4BITCOLORINDEX:            return "DDERR_NOT4BITCOLORINDEX";
	case DDERR_NOT8BITCOLOR:                 return "DDERR_NOT8BITCOLOR";
	case DDERR_NOTEXTUREHW:                  return "DDERR_NOTEXTUREHW";
	case DDERR_NOVSYNCHW:                    return "DDERR_NOVSYNCHW";
	case DDERR_NOZBUFFERHW:                  return "DDERR_NOZBUFFERHW";
	case DDERR_NOZOVERLAYHW:                 return "DDERR_NOZOVERLAYHW";
	case DDERR_OUTOFCAPS:                    return "DDERR_OUTOFCAPS";
	case DDERR_OUTOFMEMORY:                  return "DDERR_OUTOFMEMORY";
	case DDERR_OUTOFVIDEOMEMORY:             return "DDERR_OUTOFVIDEOMEMORY";
	case DDERR_OVERLAYCANTCLIP:              return "DDERR_OVERLAYCANTCLIP";
	case DDERR_OVERLAYCOLORKEYONLYONEACTIVE: return "DDERR_OVERLAYCOLORKEYONLYONEACTIVE";
	case DDERR_PALETTEBUSY:                  return "DDERR_PALETTEBUSY";
	case DDERR_COLORKEYNOTSET:               return "DDERR_COLORKEYNOTSET";
	case DDERR_SURFACEALREADYATTACHED:       return "DDERR_SURFACEALREADYATTACHED";
	case DDERR_SURFACEALREADYDEPENDENT:      return "DDERR_SURFACEALREADYDEPENDENT";
	case DDERR_SURFACEBUSY:                  return "DDERR_SURFACEBUSY";
	case DDERR_CANTLOCKSURFACE:              return "DDERR_CANTLOCKSURFACE";
	case DDERR_SURFACEISOBSCURED:            return "DDERR_SURFACEISOBSCURED";
	case DDERR_SURFACELOST:                  return "DDERR_SURFACELOST";
	case DDERR_SURFACENOTATTACHED:           return "DDERR_SURFACENOTATTACHED";
	case DDERR_TOOBIGHEIGHT:                 return "DDERR_TOOBIGHEIGHT";
	case DDERR_TOOBIGSIZE:                   return "DDERR_TOOBIGSIZE";
	case DDERR_TOOBIGWIDTH:                  return "DDERR_TOOBIGWIDTH";
	case DDERR_UNSUPPORTED:                  return "DDERR_UNSUPPORTED";
	case DDERR_UNSUPPORTEDFORMAT:            return "DDERR_UNSUPPORTEDFORMAT";
	case DDERR_UNSUPPORTEDMASK:              return "DDERR_UNSUPPORTEDMASK";
	case DDERR_VERTICALBLANKINPROGRESS:      return "DDERR_VERTICALBLANKINPROGRESS";
	case DDERR_WASSTILLDRAWING:              return "DDERR_WASSTILLDRAWING";
	case DDERR_XALIGN:                       return "DDERR_XALIGN";
	case DDERR_INVALIDDIRECTDRAWGUID:        return "DDERR_INVALIDDIRECTDRAWGUID";
	case DDERR_DIRECTDRAWALREADYCREATED:     return "DDERR_DIRECTDRAWALREADYCREATED";
	case DDERR_NODIRECTDRAWHW:               return "DDERR_NODIRECTDRAWHW";
	case DDERR_PRIMARYSURFACEALREADYEXISTS:  return "DDERR_PRIMARYSURFACEALREADYEXISTS";
	case DDERR_NOEMULATION:                  return "DDERR_NOEMULATION";
	case DDERR_REGIONTOOSMALL:               return "DDERR_REGIONTOOSMALL";
	case DDERR_CLIPPERISUSINGHWND:           return "DDERR_CLIPPERISUSINGHWND";
	case DDERR_NOCLIPPERATTACHED:            return "DDERR_NOCLIPPERATTACHED";
	case DDERR_NOHWND:                       return "DDERR_NOHWND";
	case DDERR_HWNDSUBCLASSED:               return "DDERR_HWNDSUBCLASSED";
	case DDERR_HWNDALREADYSET:               return "DDERR_HWNDALREADYSET";
	case DDERR_NOPALETTEATTACHED:            return "DDERR_NOPALETTEATTACHED";
	case DDERR_NOPALETTEHW:                  return "DDERR_NOPALETTEHW";
	case DDERR_BLTFASTCANTCLIP:              return "DDERR_BLTFASTCANTCLIP";
	case DDERR_NOBLTHW:                      return "DDERR_NOBLTHW";
	case DDERR_NODDROPSHW:                   return "DDERR_NODDROPSHW";
	case DDERR_OVERLAYNOTVISIBLE:            return "DDERR_OVERLAYNOTVISIBLE";
	case DDERR_NOOVERLAYDEST:                return "DDERR_NOOVERLAYDEST";
	case DDERR_INVALIDPOSITION:              return "DDERR_INVALIDPOSITION";
	case DDERR_NOTAOVERLAYSURFACE:           return "DDERR_NOTAOVERLAYSURFACE";
	case DDERR_EXCLUSIVEMODEALREADYSET:      return "DDERR_EXCLUSIVEMODEALREADYSET";
	case DDERR_NOTFLIPPABLE:                 return "DDERR_NOTFLIPPABLE";
	case DDERR_CANTDUPLICATE:                return "DDERR_CANTDUPLICATE";
	case DDERR_NOTLOCKED:                    return "DDERR_NOTLOCKED";
	case DDERR_CANTCREATEDC:                 return "DDERR_CANTCREATEDC";
	case DDERR_NODC:                         return "DDERR_NODC";
	case DDERR_WRONGMODE:                    return "DDERR_WRONGMODE";
	case DDERR_IMPLICITLYCREATED:            return "DDERR_IMPLICITLYCREATED";
	case DDERR_NOTPALETTIZED:                return "DDERR_NOTPALETTIZED";
	case DDERR_UNSUPPORTEDMODE:              return "DDERR_UNSUPPORTEDMODE";
	case DDERR_NOMIPMAPHW:                   return "DDERR_NOMIPMAPHW";
	case DDERR_INVALIDSURFACETYPE:           return "DDERR_INVALIDSURFACETYPE";
	case DDERR_DCALREADYCREATED:             return "DDERR_DCALREADYCREATED";
	case DDERR_CANTPAGELOCK:                 return "DDERR_CANTPAGELOCK";
	case DDERR_CANTPAGEUNLOCK:               return "DDERR_CANTPAGEUNLOCK";
	case DDERR_NOTPAGELOCKED:                return "DDERR_NOTPAGELOCKED";
	case DDERR_NOTINITIALIZED:               return "DDERR_NOTINITIALIZED";
	}
	return "Unknown Error";
}
/*--------------------------------------------------------------------------*/
// Checks if the memory associated with surfaces is lost and restores if necessary.
void CheckSurfaces()
{
	// Check the primary surface
	if (g_pDDS)
	{
		if (g_pDDS->IsLost() == DDERR_SURFACELOST)
			g_pDDS->Restore();
	}
	// Check the back buffer
	if (g_pDDSBack)
	{
		if (g_pDDSBack->IsLost() == DDERR_SURFACELOST)
			g_pDDSBack->Restore();
	}
}
/*--------------------------------------------------------------------------*/
// Double buffering flip
void DDFlip()
{
	HRESULT hr;
	
	// if we're windowed do the blit, else just Flip
	if (!g_bFullScreen)
	{
		RECT    rcSrc;  // source blit rectangle
		RECT    rcDest; // destination blit rectangle
		POINT   p;
		
		// find out where on the primary surface our window lives
		p.x = 0; p.y = 0;
		::ClientToScreen(g_hWnd, &p);
		::GetClientRect(g_hWnd, &rcDest);
		OffsetRect(&rcDest, p.x, p.y);
		SetRect(&rcSrc, 0, 0, 320, 240);
		hr = g_pDDS->Blt(&rcDest, g_pDDSBack, &rcSrc, DDBLT_WAIT, NULL);
	}
	else
	{
		hr = g_pDDS->Flip(NULL, DDFLIP_WAIT);
	}
}
/*--------------------------------------------------------------------------*/
// Clear a surface area with black
void DDClear( LPDIRECTDRAWSURFACE pDDS, int x1, int y1, int x2, int y2 )
{
	HRESULT hr;
	DDBLTFX ddbfx;
	RECT    rcDest;
	
	// Safety net
	if (pDDS == NULL)
		return;
	
	// Initialize the DDBLTFX structure with the pixel color
	ddbfx.dwSize = sizeof( ddbfx );
	ddbfx.dwFillColor = (DWORD)CreateRGB( 0, 0, 0 );
	
	SetRect( &rcDest, x1, y1, x2, y2 );
	
	// Blit 1x1 rectangle using solid color op
	hr = pDDS->Blt( &rcDest, NULL, NULL, DDBLT_WAIT | DDBLT_COLORFILL, &ddbfx );
	DDFailedCheck(hr, "Blt failure");
}
/*--------------------------------------------------------------------------*/
