
// MFC��WinInetʾ��1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC��WinInetʾ��1App: 
// �йش����ʵ�֣������ MFC��WinInetʾ��1.cpp
//

class CMFC��WinInetʾ��1App : public CWinApp
{
public:
	CMFC��WinInetʾ��1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC��WinInetʾ��1App theApp;