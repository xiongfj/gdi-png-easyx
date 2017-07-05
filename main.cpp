#include "graphics.h"
#include <conio.h>

// gdi+ ����
#include <comdef.h>
#ifndef ULONG_PTR
#define ULONG_PTR unsigned long*
#include "Includes/GdiPlus.h"
#include "Includes/GdiPlusInit.h"
#pragma comment(lib, "Lib/gdiplus.lib")
using namespace Gdiplus;
#endif

#pragma comment(lib,"Msimg32.lib")


void main()
{
	// gdi+ ��ʼ��
	GdiplusStartupInput		m_Gdistart; 
	ULONG_PTR				m_GdiplusToken;
	GdiplusStartup( &m_GdiplusToken, &m_Gdistart, NULL );

	// ��ʾ���ڡ�����
	initgraph( 400, 400 );
	loadimage( NULL, "1player.jpg", 400, 400 );			// ��ʾһ�ű���ͼ
	HDC hdc = GetImageHDC();							// ��ȡ������ hdc
	Graphics* graphics = Graphics::FromHDC( hdc );		// ������� hdc �� graphics �������ڵ��ø��ֻ�ͼ����

	// ���ر��� png
	Image* image = Image::FromFile( L"test.png" );		// L -> GDI+ ֻ֧�� UNICODE ����
	graphics->DrawImage( image, 230, 30, 100, 100 );	// �� image ���Ƶ�������
	FlushBatchDraw();									// ��ʾ��ͼ���
	getch();

	// �ͷ� gdi+ ��Դ
	if ( image != NULL )
		delete image;
	if ( graphics != NULL )
		delete graphics;
	GdiplusShutdown( m_GdiplusToken );
	closegraph();
}