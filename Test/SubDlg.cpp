// SubDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EMSPrinter.h"
#include "SubDlg.h"
#include "afxdialogex.h"


// SubDlg �Ի���

IMPLEMENT_DYNAMIC(SubDlg, CDialogEx)

SubDlg::SubDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SubDlg::IDD, pParent)
{

}

SubDlg::~SubDlg()
{
}

void SubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Text);
}


BEGIN_MESSAGE_MAP(SubDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &SubDlg::OnBnClickedButton1)
	ON_MESSAGE(CSTM_MSG, SubDlg::OnCstmMsg)
END_MESSAGE_MAP()


// SubDlg ��Ϣ�������


void SubDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//MessageBox(L"This is a Dialog");
	if(img.IsNull() == false){
		img.Destroy();
	}
	//img.Load(L"A4.jpg");
}

LRESULT SubDlg::OnCstmMsg(WPARAM wParam, LPARAM lParam)
{
	//MessageBox(L"Message frome parent dialog");
	m_Text.SetWindowTextW(L"�����ڷ���Ϣ������");
	return 0;
}