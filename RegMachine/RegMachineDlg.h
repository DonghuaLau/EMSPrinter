
// RegMachineDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CRegMachineDlg �Ի���
class CRegMachineDlg : public CDialogEx
{
// ����
public:
	CRegMachineDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_REGMACHINE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnGenerateKey();
	CEdit m_Key;
	CEdit m_MAC;
};
