
// EMSPrinter.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CEMSPrinterApp:
// �йش����ʵ�֣������ EMSPrinter.cpp
//

class CEMSPrinterApp : public CWinApp
{
public:
	CEMSPrinterApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CEMSPrinterApp theApp;