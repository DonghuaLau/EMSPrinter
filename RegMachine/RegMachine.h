
// RegMachine.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRegMachineApp:
// �йش����ʵ�֣������ RegMachine.cpp
//

class CRegMachineApp : public CWinApp
{
public:
	CRegMachineApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRegMachineApp theApp;