#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CPregressDlg �Ի���

class CPregressDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPregressDlg)

public:
	CPregressDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPregressDlg();

// �Ի�������
	enum { IDD = IDD_DLG_PROGRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	
	
public:
	CWinThread *m_hThread;
	CWinThread *m_hThreadSelf;
	int TheWaitThread(CWinThread *hThread, int *flag);
	static int WaitThreadProc(void *pUser);
	virtual BOOL OnInitDialog();
	CStatic m_Text;
	CProgressCtrl m_Progress;
	int *m_ThreadFlag;
	virtual void OnCancel();
};
