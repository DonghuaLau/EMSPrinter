#pragma once
#include "afxwin.h"


// CAuthDlg �Ի���

class CAuthDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAuthDlg)

public:
	CAuthDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAuthDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_KEY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Key;
	CString key;
	virtual void OnCancel();
	virtual void OnOK();
};
