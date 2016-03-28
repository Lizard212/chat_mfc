// ProTabPageLogin.cpp : implementation file
//

#include "stdafx.h"
#include "MFCMyTabCtrl.h"
#include "ProTabPageLogin.h"
#include "afxdialogex.h"


// CProTabPageLogin dialog

IMPLEMENT_DYNAMIC(CProTabPageLogin, CPropertyPage)

CProTabPageLogin::CProTabPageLogin()
	: CPropertyPage(IDD_TABPAGE_LOGIN)
{

}

CProTabPageLogin::~CProTabPageLogin()
{
}

void CProTabPageLogin::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CProTabPageLogin, CPropertyPage)
END_MESSAGE_MAP()


// CProTabPageLogin message handlers
