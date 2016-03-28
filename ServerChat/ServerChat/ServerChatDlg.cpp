
// ServerChatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ServerChat.h"
#include "ServerChatDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CServerChatDlg dialog


TcpSocket tcpsocket;
CServerChatDlg::CServerChatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SERVERCHAT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerChatDlg::ShowServerInfor(string sValue)
{
	CString  strLine(sValue.c_str());

	//m_list_status_connection.AddString(_T("ip connected"));
}



void CServerChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list_status_connection);
	DDX_Control(pDX, IDC_BUTTON1, m_btn_start);
	DDX_Control(pDX, IDC_BUTTON2, m_btn_stop);
	DDX_Control(pDX, IDC_PORT, m_label_ip);
}

BEGIN_MESSAGE_MAP(CServerChatDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CServerChatDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CServerChatDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CServerChatDlg message handlers

BOOL CServerChatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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


	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CServerChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
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



void CServerChatDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CServerChatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CServerChatDlg::OnBnClickedButton1()
{
	m_btn_start.ShowWindow(SW_HIDE);
	m_btn_stop.ShowWindow(SW_SHOW);
	m_list_status_connection.AddString(_T("Server started."));
	cTh = AfxBeginThread(StaticThreadFunc, this);
	m_thread_handle = cTh->m_hThread;
	
	
}


void CServerChatDlg::OnBnClickedButton2()
{

	m_btn_start.ShowWindow(SW_SHOW);
	m_btn_stop.ShowWindow(SW_HIDE); 
	tcpsocket.~TcpSocket();
	//m_tcpsocket->~TcpSocket();
	m_list_status_connection.AddString(_T("Server has stoped."));
}

UINT CServerChatDlg::ThreadFunc()
{
	//m_tcpsocket = new TcpSocket(this);
	tcpsocket.Create();
	tcpsocket.InitInfor("1");
	tcpsocket.Listen();
	tcpsocket.Accept();
	//m_tcpsocket->Create();
	//m_tcpsocket->InitInfor("1");
	//m_tcpsocket->Listen();
	//m_tcpsocket->Accept();
	return 0;
}

UINT CServerChatDlg::StaticThreadFunc(LPVOID param)
{
	CServerChatDlg *serverdlg = (CServerChatDlg*)param;
	UINT retCode = serverdlg->ThreadFunc();
	return retCode;
}
