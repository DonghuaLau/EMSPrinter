
// RegMachineDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RegMachine.h"
#include "RegMachineDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <cstring>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//
 // CStringA to CStringW
 //
 CStringW CStrA2CStrW(const CStringA &cstrSrcA)
 {
     int len = MultiByteToWideChar(CP_ACP, 0, LPCSTR(cstrSrcA), -1, NULL, 0);
     wchar_t *wstr = new wchar_t[len];
     memset(wstr, 0, len*sizeof(wchar_t));
     MultiByteToWideChar(CP_ACP, 0, LPCSTR(cstrSrcA), -1, wstr, len);
     CStringW cstrDestW = wstr;
     delete[] wstr;
 
     return cstrDestW;
 }
 
 //
 // CStringW to CStringA
 //
 CStringA CStrW2CStrA(const CStringW &cstrSrcW)
 {
     int len = WideCharToMultiByte(CP_ACP, 0, LPCWSTR(cstrSrcW), -1, NULL, 0, NULL, NULL);
     char *str = new char[len];
     memset(str, 0, len);
     WideCharToMultiByte(CP_ACP, 0, LPCWSTR(cstrSrcW), -1, str, len, NULL, NULL);
     CStringA cstrDestA = str;
     delete[] str;
 
     return cstrDestA;
 }

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRegMachineDlg �Ի���




CRegMachineDlg::CRegMachineDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRegMachineDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRegMachineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Key);
	DDX_Control(pDX, IDC_EDIT2, m_MAC);
}

BEGIN_MESSAGE_MAP(CRegMachineDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRegMachineDlg::OnGenerateKey)
END_MESSAGE_MAP()


// CRegMachineDlg ��Ϣ�������

BOOL CRegMachineDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetWindowText(L"ע����������");
	//m_Key.SetFocus();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CRegMachineDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRegMachineDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRegMachineDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRegMachineDlg::OnGenerateKey()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStringW strW;
	CStringA strA;
	string mac;
	CString key;
	
	int A = 0, B = 0;
	unsigned char nMac[6] = {0}, tMac[6] = {0};
	int m = 0;

	m_MAC.GetWindowText(strW);
	strA = CStrW2CStrA(strW);
	mac = strA;

	//int nsize = mac.size();
	for(int i = 0; i <  mac.size(); i++){
		if(mac[i] == '-' || mac[i] == ':'){
			mac.erase(mac.begin() + i);
		}
	}
	int nsize = mac.size();
	if(nsize != 12){
		 MessageBox(L"��ЧMAC", L"����");
		 return ;
	}
	int j = 0;
	for(int i = 0; i < nsize; i++){
		if(i%2 == 0){
			if(mac[i] >= '0' && mac[i] <= '9')
				nMac[j] = (mac[i] - '0') * 16;
			else if(mac[i] >= 'a' && mac[i] <= 'f')
				nMac[j] = (mac[i] - 'a' + 10) * 16;
			else if(mac[i] >= 'A' && mac[i] <= 'F')
				nMac[j] = (mac[i] - 'A' + 10) * 16;
			else MessageBox(L"��ЧMAC", L"����");
		}else{
			if(mac[i] >= '0' && mac[i] <= '9')
				nMac[j] += mac[i] - '0';
			else if(mac[i] >= 'a' && mac[i] <= 'f')
				nMac[j] += mac[i] - 'a' + 10;
			else if(mac[i] >= 'A' && mac[i] <= 'F')
				nMac[j] += mac[i] - 'A' + 10;
			else MessageBox(L"��ЧMAC", L"����");
			j++;
		}
	}

	strA = "";
	for(int i = 0; i < 6; i++){
		A += nMac[i];
	}
	A *= 5;

	for(int i = 0; i < 6; i++){
		tMac[i] = ~nMac[i];
	}

	nMac[0] = tMac[4];
	nMac[1] = tMac[2];
	nMac[2] = tMac[5];
	nMac[3] = tMac[1];
	nMac[4] = tMac[3];
	nMac[5] = tMac[0];

	strA.Format("%02X%02X-%04X%02X%02X", nMac[2],nMac[3], A, nMac[4],nMac[5]);

	m_Key.SetWindowText(CStrA2CStrW(strA));
}
