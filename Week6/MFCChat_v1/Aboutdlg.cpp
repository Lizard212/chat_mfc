// Aboutdlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCChat_v1.h"
#include "Aboutdlg.h"
#include "afxdialogex.h"


// CAboutdlg dialog

IMPLEMENT_DYNAMIC(CAboutdlg, CDialogEx)

CAboutdlg::CAboutdlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ABOUTBOX, pParent)
{

}

CAboutdlg::~CAboutdlg()
{
}

void CAboutdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutdlg, CDialogEx)
END_MESSAGE_MAP()


// CAboutdlg message handlers
