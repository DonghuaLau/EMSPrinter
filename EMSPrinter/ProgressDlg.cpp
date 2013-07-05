// PregressDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EMSPrinter.h"
#include "ProgressDlg.h"
#include "afxdialogex.h"


// CPregressDlg �Ի���

IMPLEMENT_DYNAMIC(CPregressDlg, CDialogEx)

CPregressDlg::CPregressDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPregressDlg::IDD, pParent)
{

}

CPregressDlg::~CPregressDlg()
{
}

void CPregressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress);
	DDX_Control(pDX, IDC_STATIC_TEXT, m_Text);
}


BEGIN_MESSAGE_MAP(CPregressDlg, CDialogEx)
END_MESSAGE_MAP()


// CPregressDlg ��Ϣ�������

int CPregressDlg::TheWaitThread(CWinThread *hThread, int *flag)
{
	m_hThread = hThread;
	m_ThreadFlag = flag;
	return 0;
}

int CPregressDlg::WaitThreadProc(void *pUser)
{
	CPregressDlg *dlg = (CPregressDlg*)pUser;
	unsigned long retw = 0;

	//while(1){
	//	//if(dlg->m_hThread) retw = WaitForSingleObject(dlg->m_hThread, INFINITE);//1000000);
	//	//else retw = WAIT_FAILED;
	//	retw = WaitForSingleObject(dlg->m_hThread, INFINITE);//1000000);
	//	if(retw == WAIT_OBJECT_0){
	//		dlg->OnOK();
	//		dlg->m_Text.SetWindowText(L"�������");
	//		break;
	//	}else if(retw == WAIT_FAILED){
	//		//dlg->OnCancel();	
	//		retw = GetLastError();
	//		dlg->m_Text.SetWindowText(L"����δ���");
	//	}else{
	//		//continue;
	//	}
	//}

	int n = 0;
	dlg->m_Progress.SetRange(1, 100);

	while(1){
		if(*dlg->m_ThreadFlag >= 0){ 
			CString msg;
			msg.Format(L"�ɹ�����%d������", *dlg->m_ThreadFlag);
			dlg->m_Text.SetWindowText(msg);
			dlg->SetWindowText(L"���");
			dlg->m_Progress.SetPos(100);
			dlg->GetDlgItem(IDOK)->EnableWindow(TRUE);
			break; 
		}else if(*dlg->m_ThreadFlag == -2){
			break;
		}else{
			n = (n+2) % 100;
			dlg->m_Progress.SetPos((++n) % 100);
		}
		Sleep(100);
	}

	return 0;
}

BOOL CPregressDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_Text.SetWindowText(L"���ڵ�������...");
	GetDlgItem(IDOK)->EnableWindow(FALSE);
	m_hThreadSelf = AfxBeginThread((AFX_THREADPROC)WaitThreadProc, this);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CPregressDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
	//Sleep(2000);
	//WaitForSingleObject(m_hThreadSelf, INFINITE);
	CDialogEx::OnCancel();
}
