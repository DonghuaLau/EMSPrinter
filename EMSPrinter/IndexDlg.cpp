// IndexDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EMSPrinter.h"
#include "IndexDlg.h"
#include "afxdialogex.h"


// CIndexDlg �Ի���

IMPLEMENT_DYNAMIC(CIndexDlg, CDialogEx)

CIndexDlg::CIndexDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIndexDlg::IDD, pParent)
{

}

CIndexDlg::~CIndexDlg()
{
}

void CIndexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMPANY_INFO, m_CompanyInfo);
	DDX_Control(pDX, IDC_EDIT1, m_FindKey);
}


BEGIN_MESSAGE_MAP(CIndexDlg, CDialogEx)
END_MESSAGE_MAP()


// CIndexDlg ��Ϣ�������


void CIndexDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	CString str;
	CStringA strA;

	m_CompanyInfo.GetWindowText(str);
	m_Company = CStrW2CStrA(str);
	m_FindKey.GetWindowText(str);
	m_Index = CStrW2CStrA(str);
	CDialogEx::OnOK();
}


void CIndexDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���	

	CDialogEx::OnCancel();
}


BOOL CIndexDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	CString str;
	CStringA strA;

	SetWindowText(L"��������");

	CFont editfont;
	editfont.CreateFont(20, 0 ,0 , 0,
				FW_NORMAL,	FALSE, FALSE, FALSE, GB2312_CHARSET/*ANSI_CHARSET*/,
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
				DEFAULT_PITCH | FF_MODERN , L"����");
	m_FindKey.SetFont(&editfont);       

	strA.Format("%s", m_Company.c_str());
	str = L"��˾���ƣ�";
	str += CStrA2CStrW(strA);
	m_CompanyInfo.SetWindowText(str);
	strA.Format("%s", m_Index.c_str());
	m_FindKey.SetWindowText(CStrA2CStrW(strA));


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
