// AuthDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EMSPrinter.h"
#include "AuthDlg.h"
#include "afxdialogex.h"


// CAuthDlg �Ի���

IMPLEMENT_DYNAMIC(CAuthDlg, CDialogEx)

CAuthDlg::CAuthDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAuthDlg::IDD, pParent)
{

}

CAuthDlg::~CAuthDlg()
{
}

void CAuthDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Key);
}


BEGIN_MESSAGE_MAP(CAuthDlg, CDialogEx)
END_MESSAGE_MAP()


// CAuthDlg ��Ϣ�������


void CAuthDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���

	CDialogEx::OnCancel();
}


void CAuthDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	m_Key.GetWindowText(key);
	CDialogEx::OnOK();
}
