
// EMSPrinterDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EMSPrinter.h"
#include "EMSPrinterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(lib, "printcom.lib")

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


// CEMSPrinterDlg �Ի���




CEMSPrinterDlg::CEMSPrinterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEMSPrinterDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEMSPrinterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEMSPrinterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CEMSPrinterDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CEMSPrinterDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CEMSPrinterDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CEMSPrinterDlg ��Ϣ�������

BOOL CEMSPrinterDlg::OnInitDialog()
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

	
	//m_dlg.Create(L"dlg");
	//m_dlg.SetParent(this);
	//m_dlg.SetWindowPos(this, 20, 20, 100, 100, SWP_SHOWWINDOW );
	//m_dlg.ShowWindow(SW_SHOW);
	m_dlg = new SubDlg(this);
	m_dlg->Create(IDD_DIALOG1);
	m_dlg->SetParent(this);
	m_dlg->ShowWindow(SW_SHOW);
	CRect rect;
	m_dlg->GetWindowRect(&rect);
	m_dlg->MoveWindow(120, 60, rect.right - rect.left, rect.bottom - rect.top);
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CEMSPrinterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEMSPrinterDlg::OnPaint()
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
HCURSOR CEMSPrinterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CEMSPrinterDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// get the default printer
	CPrintDialog dlg(FALSE);
	//dlg.GetDefaults();

	CImage img;
	int ret = img.Load(L"A4.jpg");
	//CString msg;
	//msg.Format(L"Load ret = %d", ret);
	//MessageBox(msg);

	dlg.DoModal();
	//CPrintDialog::m_pd
	// is a default printer set up?
	HDC hdcPrinter = dlg.GetPrinterDC();
	
	//int W = GetDeviceCaps(hdcPrinter,PHYSICALWIDTH);
	//int H = GetDeviceCaps(hdcPrinter,PHYSICALHEIGHT);
	//int X = GetDeviceCaps(hdcPrinter, LOGPIXELSX);
	//int Y = GetDeviceCaps(hdcPrinter, LOGPIXELSY);
	//CString msg;
	//msg.Format(L"Page size(%d, %d), DC size(%d, %d)", W, H, X, Y);
	//MessageBox(msg);
	////MessageBox(dlg.GetDriverName() + L"  " + dlg.GetPortName() + L"  " + dlg.GetDeviceName());
	//return;

	if (hdcPrinter == NULL)
	{
	   MessageBox(_T("Buy a printer!"));
	}
	else
	{
	   // create a CDC and attach it to the default printer
	   CDC dcPrinter;
	   dcPrinter.Attach(hdcPrinter);
	   dcPrinter.SetBkMode(TRANSPARENT); 
	   // call StartDoc() to begin printing
	   DOCINFO docinfo;
	   memset(&docinfo, 0, sizeof(docinfo));
	   docinfo.cbSize = sizeof(docinfo);
	   docinfo.lpszDocName = _T("CDC::StartDoc() Code Fragment");
	   
	   // if it fails, complain and exit gracefully
	   if (dcPrinter.StartDoc(&docinfo) < 0)
	   {
		  MessageBox(_T("Printer wouldn't initalize"));
	   }
	   else
	   {
		  // start a page
		  if (dcPrinter.StartPage() < 0)
		  {
			 MessageBox(_T("Could not start page"));
			 dcPrinter.AbortDoc();
		  }
		  else
		  {
			 // actually do some printing
			 CGdiObject* pOldFont = dcPrinter.SelectStockObject(SYSTEM_FONT);

			 CFont pNewFont;
			 pNewFont.CreateFont(30, 0 ,0 , 0,
				FW_EXTRALIGHT/*FW_NORMAL*/,	FALSE, FALSE, FALSE, GB2312_CHARSET/*ANSI_CHARSET*/,
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
				DEFAULT_PITCH | FF_MODERN , _T("����"));
			 dcPrinter.SelectObject(pNewFont);
			 
			 

			 #define RATE (180 / 25.4/* 2.0*/)
			 double rate = 1.2;// 2.0;
			 int width = (int)(img.GetWidth() * rate), height = (int)(img.GetHeight() * rate);
			 img.StretchBlt(dcPrinter,0,0, width, height);

			 //dcPrinter.TextOut(0, 0, _T("Hello World!"), 12);

			 double x = RATE * 17, y = RATE * 27;
			 dcPrinter.TextOut((int)x, (int)y, L"����", wcslen(L"����"));

			 x = RATE * 22, y = RATE * 33;
			 dcPrinter.TextOut((int)x, (int)y, L"ͬ���ɷ����޹�˾", wcslen(L"ͬ���ɷ����޹�˾"));

			 x = RATE * 80, y = RATE * 33;
			 dcPrinter.TextOut((int)x, (int)y, L"8537", wcslen(L"8537"));

			 x = RATE * 16, y = RATE * 39;
			 dcPrinter.TextOut((int)x, (int)y, L"�����к�������ׯ·1���廪ͬ���Ƽ��㳡", wcslen(L"�����к�������ׯ·1���廪ͬ���Ƽ��㳡"));

			 x = RATE * 74, y = RATE * 48;
			 dcPrinter.TextOut((int)x, (int)y, L"1 0 0 0 8 3", wcslen(L"1 0 0 0 8 3"));

			 //ʱ��
			 x = RATE * 156, y = RATE * 59;
			 dcPrinter.TextOut((int)x, (int)y, L"2013  02  22", wcslen(L"2013  02  22"));

			 x = RATE * 17, y = RATE * 57;
			 dcPrinter.TextOut((int)x, (int)y, L"��Ϣ����", wcslen(L"��Ϣ����"));

			 x = RATE * 61, y = RATE * 57;
			 dcPrinter.TextOut((int)x, (int)y, L"010-83188508", wcslen(L"010-83188508"));

			 x = RATE * 21, y = RATE * 64;
			 dcPrinter.TextOut((int)x, (int)y, L"�������ҵ����", wcslen(L"�������ҵ����"));

			 x = RATE * 16, y = RATE * 69;
			 dcPrinter.TextOut((int)x, (int)y, L"�����к�������ׯ·1���廪ͬ���Ƽ��㳡", wcslen(L"�����к�������ׯ·1���廪ͬ���Ƽ��㳡"));

			 x = RATE * 20, y = RATE * 85;
			 dcPrinter.TextOut((int)x, (int)y, L"Beijing", wcslen(L"Beijing"));

			 x = RATE * 74, y = RATE * 85;
			 dcPrinter.TextOut((int)x, (int)y, L"1 0 0 0 8 3", wcslen(L"1 0 0 0 8 3"));

			 x = RATE * 21, y = RATE * 103;
			 dcPrinter.TextOut((int)x, (int)y, L"���ԡ�����", wcslen(L"���ԡ�����"));
			 
			 
			 dcPrinter.EndPage();
			 dcPrinter.EndDoc();
			 dcPrinter.SelectObject(pOldFont);
			 pNewFont.DeleteObject();

			 

			 MessageBox(_T("Print finished"));
		  }
	   }
	}
}


void CEMSPrinterDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hwnd = m_dlg->m_hWnd;
	::SendMessage(hwnd,CSTM_MSG, 8, 9);
}


void CEMSPrinterDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	m_Printer.SetBackground(L"A4.jpg");

	int x, y;
	CString font, text;
	int fontsize;

	x = 17, y = 27;
	fontsize = 50;
	font = L"����";
	text = L"����";
	m_Printer.InsertItem(x,y,fontsize, font, text);

	x = 22, y = 33;
	fontsize = 50;
	font = L"����";
	text = L"ͬ���ɷ����޹�˾";
	m_Printer.InsertItem(x,y,fontsize, font, text);

	x = 80, y = 33;
	fontsize = 50;
	font = L"����";
	text = L"8537";
	m_Printer.InsertItem(x,y,fontsize, font, text);

	x = 16, y = 39;
	fontsize = 50;
	font = L"����";
	text = L"�����к�������ׯ·1���廪ͬ���Ƽ��㳡";
	m_Printer.InsertItem(x,y,fontsize, font, text);

	x = 74, y = 48;
	fontsize = 50;
	font = L"����";
	text = L"1 0 0 0 8 3";
	m_Printer.InsertItem(x,y,fontsize, font, text);

	//ʱ��
	x = 156, y = 60;
	fontsize = 50;
	font = L"����";
	text = L"2013  02  22";
	m_Printer.InsertItem(x,y,fontsize, font, text);

	x = 17, y = 57;
	fontsize = 50;
	font = L"����";
	text = L"��Ϣ����";
	m_Printer.InsertItem(x,y,fontsize, font, text);

	x = 61, y = 57;
	fontsize = 50;
	font = L"����";
	text = L"010-83188508";
	m_Printer.InsertItem(x,y,fontsize, font, text);

	x = 21, y = 64;
	fontsize = 50;
	font = L"����";
	text = L"�������ҵ����";
	m_Printer.InsertItem(x,y,fontsize, font, text);

	x = 16, y = 69;
	fontsize = 50;
	font = L"����";
	text = L"�����к�������ׯ·1���廪ͬ���Ƽ��㳡";
	m_Printer.InsertItem(x,y,fontsize, font, text);

	x = 20, y = 85;
	fontsize = 50;
	font = L"����";
	text = L"Beijing";
	m_Printer.InsertItem(x,y,fontsize, font, text);

	x = 74, y = 85;
	fontsize = 50;
	font = L"����";
	text = L"1 0 0 0 8 3";
	m_Printer.InsertItem(x,y,fontsize, font, text);

	x = 21, y = 104;
	fontsize = 50;
	font = L"����";
	text =L"���ԡ�����";
	m_Printer.InsertItem(x,y,fontsize, font, text);

	int ret = m_Printer.DoPrint();
	CString msg;
	msg.Format(L"ret = %d", ret);
	MessageBox(msg);
}
