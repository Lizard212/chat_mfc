// TabPageLogin.cpp : implementation file
//

#include "stdafx.h"
#include "MFCMyTabCtrl.h"
#include "TabPageLogin.h"
#include "afxdialogex.h"


// TabPageLogin dialog

IMPLEMENT_DYNAMIC(TabPageLogin, CDialogEx)

TabPageLogin::TabPageLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TABPAGE_LOGIN, pParent)
{

}

TabPageLogin::~TabPageLogin()
{
}

void TabPageLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TabPageLogin, CDialogEx)
END_MESSAGE_MAP()


// TabPageLogin message handlers
