#define UNICDOE

#pragma comment(linker, "/opt:nowin98")
#include <shlobj.h>
#include <windows.h>

int WINAPI WinMain(HINSTANCE hinst,HINSTANCE hPreInst,
				   LPSTR pCmdLine,int nCmdShow)
{
	TCHAR szPath[_MAX_PATH];
	LPITEMIDLIST pidl;
	IMalloc *pMalloc;
	SHGetMalloc(&pMalloc);
	if( SUCCEEDED(SHGetSpecialFolderLocation(NULL,CSIDL_DESKTOPDIRECTORY,&pidl)) )
	{ 
		SHGetPathFromIDList(pidl,szPath);
		pMalloc->Free(pidl);
	}
	pMalloc->Release();
	MessageBox(NULL,szPath,TEXT("デスクトップのパス"),MB_OK);
	return 0;
}


