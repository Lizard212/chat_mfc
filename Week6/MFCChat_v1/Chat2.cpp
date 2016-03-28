// Chat2.cpp : implementation file
//

#include "stdafx.h"
#include "MFCChat_v1.h"
#include "Chat2.h"
#include "afxdialogex.h"
#include"Test_Dlg.h"

// Chat2 dialog

IMPLEMENT_DYNAMIC(Chat2, CDialogEx)

Chat2::Chat2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHAT, pParent)
{

}

Chat2::~Chat2()
{
}

void Chat2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_message2);
	DDX_Control(pDX, IDC_LIST_MESSAGE2, m_list_message2);
}


BEGIN_MESSAGE_MAP(Chat2, CDialogEx)
	ON_MESSAGE(VM_RESULT_NOTIFY, &Chat2::GetResult)
	ON_MESSAGE(VM_RESULT_NOTITY1, &Test_Dlg::GetResult)
	ON_BN_CLICKED(IDC_BUTTON_SEND2, &Chat2::OnBnClickedButtonSend2)
END_MESSAGE_MAP()


// Chat2 message handlers


LRESULT Chat2::GetResult(WPARAM w, LPARAM l)
{
	UpdateData(TRUE);

	m_list_message2.AddString((LPCTSTR)w);

	return LRESULT();
}

void Chat2::OnBnClickedButtonSend2()
{
	CString s;
	m_message2.GetWindowTextW(s);
	m_list_message2.AddString(s);
	::SendMessage(hwnd_chat1, VM_RESULT_NOTITY1, (WPARAM)(LPCTSTR)s, NULL);
	
}
