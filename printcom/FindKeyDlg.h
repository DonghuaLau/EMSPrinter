#pragma once
#include "afxwin.h"

#pragma once


// CFindKeyDlg �Ի���

class CFindKeyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFindKeyDlg)

public:
	CFindKeyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFindKeyDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_FIND_KEY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_Tip;
	CEdit m_Key;
};
