#pragma once
#include "afxwin.h"


// SubDlg �Ի���

class SubDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SubDlg)

public:
	SubDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SubDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

	CImage img;

public:
	CEdit m_Text;
	afx_msg void OnBnClickedButton1();
	afx_msg LRESULT OnCstmMsg(WPARAM wParam, LPARAM lParam);
};
