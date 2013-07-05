#pragma once
#include "afxwin.h"
#include "common.h"
#include <string>
using namespace std;

// CIndexDlg �Ի���

class CIndexDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CIndexDlg)

public:
	CIndexDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CIndexDlg();

// �Ի�������
	enum { IDD = IDD_DLG_INDEX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_CompanyInfo;
	CEdit m_FindKey;
	string m_Company;
	string m_Index;

public:
	void SetCompanyAndIndex(string company, string index)
	{
		m_Company = company;
		m_Index = index;
	}
	string GetIndex(){ return m_Index; };
	
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
};
