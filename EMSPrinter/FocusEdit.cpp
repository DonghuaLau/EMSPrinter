// FocusEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EMSPrinter.h"
#include "FocusEdit.h"


// CFocusEdit

IMPLEMENT_DYNAMIC(CFocusEdit, CEdit)

CFocusEdit::CFocusEdit()
{

}

CFocusEdit::~CFocusEdit()
{
}


BEGIN_MESSAGE_MAP(CFocusEdit, CEdit)
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()



// CFocusEdit ��Ϣ�������




void CFocusEdit::OnSetFocus(CWnd* pOldWnd)
{
	CEdit::OnSetFocus(pOldWnd);

	// TODO: �ڴ˴������Ϣ����������
	CEdit::PostMessage(EM_SETSEL,0,GetWindowTextLength());

}
