#include "graphics.h"
#include <conio.h>

// gdi+ 条件
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
	// gdi+ 初始化
	GdiplusStartupInput		m_Gdistart; 
	ULONG_PTR				m_GdiplusToken;
	GdiplusStartup( &m_GdiplusToken, &m_Gdistart, NULL );

	// 显示窗口、背景
	initgraph( 400, 400 );
	loadimage( NULL, "1player.jpg", 400, 400 );			// 显示一张背景图
	HDC hdc = GetImageHDC();							// 获取主窗口 hdc
	Graphics* graphics = Graphics::FromHDC( hdc );		// 定义关联 hdc 的 graphics 对象，用于调用各种绘图函数

	// 加载本地 png
	Image* image = Image::FromFile( L"test.png" );		// L -> GDI+ 只支持 UNICODE 编码
	graphics->DrawImage( image, 230, 30, 100, 100 );	// 将 image 绘制到主窗口
	FlushBatchDraw();									// 显示绘图结果
	getch();

	// 释放 gdi+ 资源
	if ( image != NULL )
		delete image;
	if ( graphics != NULL )
		delete graphics;
	GdiplusShutdown( m_GdiplusToken );
	closegraph();
}