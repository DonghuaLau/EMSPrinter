
// EMSPrinterDlg.h : ͷ�ļ�
//

#pragma once
#include "SubDlg.h"

#include "../printcom/printcom.h"

// CEMSPrinterDlg �Ի���
class CEMSPrinterDlg : public CDialogEx
{
// ����
public:
	CEMSPrinterDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EMSPRINTER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


	SubDlg *m_dlg;

	CPrinter m_Printer;

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
	afx_msg void OnBnClickedButton1();

	BOOL PrintPic(CString strFileName,int iCopies,CString strPrintName);

	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
