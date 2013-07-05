
// EMSPrinterDlg.h : ͷ�ļ�
//

#pragma once
#include "EMSBill.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "../printcom/printcom.h"
#include "AuthDlg.h"
#include "ProgressDlg.h"


#define MAX_LIST 20
typedef struct _Info_Item{
	char item[7][256];
}Info_Item, *pInfo_Item;

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

private:
	CStringW m_CondW;
	CStringA m_CondA;
	string m_Cond;

	CEMSBill *m_EmsBill;	
	CPrinter m_Printer;	
	CAuthDlg m_Auth;
	vector<pInfo_Item> m_ListItems;
	CPregressDlg m_Progress;	

	int InitMainDlg();
	int CreateSubDlg(int flag);
	int Search(string condition, void *pUser);

	int Authenticate();
	int GenerateKey(BYTE mac[8], CString &key);
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
	
	CInfoDB m_InfoDB;
	CComboBox m_Type;
	CListCtrl m_InfoList;
	int m_InfoListRows;
	CEdit m_SearchStr;
	CStringA m_Filepath;
	int m_ThreadFlag;

	static int ImportInfoProc(void *pUser);
	static int QueryCallback(void *pUser, int argc, char **argv, char **azColName);
	static int SaveCallback(void *pUser, int argc, char **argv, char **azColName);

	int InsertListItem(int argc, char **argv, char **azColName);
	afx_msg void OnSearchRealtime();
	afx_msg void OnSave();
	afx_msg void OnDelete();
	afx_msg void OnPrint();
	virtual void OnCancel();
	afx_msg void OnImportInfo();	
	afx_msg void OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void On32775();
	afx_msg void OnExportInfo();
	afx_msg void OnSetIndex();
	afx_msg void OnClose();
};
