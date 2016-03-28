// Tab1.cpp : implementation file
//

#include "stdafx.h"
#include "MFCMyTabCtrl.h"
#include "Tab1.h"
#include "afxdialogex.h"


// Tab1 dialog

IMPLEMENT_DYNAMIC(Tab1, CDialogEx)

Tab1::Tab1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCMYTABCTRL_DIALOG, pParent)
{

}

Tab1::~Tab1()
{
}

void Tab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Tab1, CDialogEx)
END_MESSAGE_MAP()


// Tab1 message handlers
