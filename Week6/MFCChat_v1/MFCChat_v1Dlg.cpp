
// MFCChat_v1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCChat_v1.h"
#include "MFCChat_v1Dlg.h"
#include "afxdialogex.h"
#include"Test_Dlg.h"
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


// CMFCChat_v1Dlg dialog



CMFCChat_v1Dlg::CMFCChat_v1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCCHAT_V1_DIALOG, pParent)
{
	m_hIcon= LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	CImage image;
	image.Load(_T("res\\Cloud-icon.bmp"));

	m_bitmap.Attach(image.Detach());
	
}

void CMFCChat_v1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ID_SIGNIN, m_Singin_button);
	DDX_Control(pDX, IDC_EMAIL, m_Edit_Email);
	DDX_Control(pDX, IDC_PASSWORD, m_Edit_Password);
	//  DDX_Control(pDX, IDC_PICTURE1, m_Picture_Control);
	DDX_Control(pDX, IDC_PICTURE1, m_Picture_Control);
	DDX_Control(pDX, ID_SIGNUP, m_Signup_Button);
}

BEGIN_MESSAGE_MAP(CMFCChat_v1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_MFCLINK1, &CMFCChat_v1Dlg::OnBnClickedMfclink1)
	ON_BN_CLICKED(ID_SIGNIN, &CMFCChat_v1Dlg::OnBnClickedSignin)
	ON_BN_CLICKED(ID_SIGNUP, &CMFCChat_v1Dlg::OnBnClickedSignup)
	ON_COMMAND(ID_ICHAT_EXIT, &CMFCChat_v1Dlg::OnIchatExit)
	ON_COMMAND(ID_HELP_ABOUTICHAT, &CMFCChat_v1Dlg::OnHelpAboutichat)
	ON_WM_CLOSE()
END_MESSAGE_MAP()




BOOL CMFCChat_v1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	// Menu login

	m_brush.CreateSolidBrush(RGB(0, 175, 240));
	m_menu_login.LoadMenuW(IDR_MENU1);
	SetMenu(&m_menu_login);

	// Button signin

	m_Singin_button.SetFaceColor(RGB(115, 172, 33),true);
	//m_Singin_button.SetFaceColor(2252835);
	m_Singin_button.SetTextColor(RGB(255, 255, 255));
	m_Singin_button.SetTextHotColor(RGB(115, 172, 33) );
	m_Singin_button.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;

	m_Singin_button.SetTooltip(_T("Press to sign in iChat"));

	// Button sign up
	m_Signup_Button.SetFaceColor(RGB(115, 172, 33), true);
	//m_Singin_button.SetFaceColor(2252835);
	m_Signup_Button.SetTextColor(RGB(255, 255, 255));
	m_Signup_Button.SetTextHotColor(RGB(115, 172, 33));
	m_Signup_Button.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;

	m_Signup_Button.SetTooltip(_T("Press to sign up iChat free"));

	// Set font
	m_pFont->CreatePointFont(150, _T("Consolas"));
	m_pFont1->CreatePointFont(120, _T("Arial"));

	GetDlgItem(IDC_EMAIL)->SetFont(m_pFont, TRUE);
	GetDlgItem(IDC_PASSWORD)->SetFont(m_pFont, TRUE);
	GetDlgItem(ID_SIGNIN)->SetFont(m_pFont1, TRUE);
	GetDlgItem(ID_SIGNUP)->SetFont(m_pFont1, TRUE);
	// Set text default
	m_Edit_Email.SetWindowTextW(_T("thangpv"));
	m_Edit_Password.SetWindowTextW(_T("123"));

	// Load Imagie
    m_Picture_Control.SetBitmap((HBITMAP)m_bitmap.Detach());

	//HANDLE hThread = CreateThread(NULL, 0, Test_Dlg::DatabaseChange, NULL, 0, NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCChat_v1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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



void CMFCChat_v1Dlg::OnPaint()
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
HCURSOR CMFCChat_v1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






HBRUSH CMFCChat_v1Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	hbr = m_brush;
	
	return hbr;
}


void CMFCChat_v1Dlg::OnBnClickedMfclink1()
{
	//MessageBox(_T("feeling good"), _T("asdf"), MB_OK);
	//
	//Register_Dlg register_dlg;
	//register_dlg.DoModal();
}


void CMFCChat_v1Dlg::OnBnClickedSignin()
{
	UpdateData(TRUE);
	CString str1;
	CString str2;
	m_Edit_Email.GetWindowTextW(str1);
	m_Edit_Password.GetWindowTextW(str2);

	CT2CA pszName1(str1);
	string s1(pszName1);
	CT2CA pszName2(str2);
	string s2(pszName2);
	if (!bus.Check(s1, s2))
	{
		MessageBox(_T("Email or password incorrect"), _T("Warning"), MB_OK| MB_ICONWARNING);
	}
	else
	{
		Context::setAccount(bus.Select(s1));
		ShowWindow(SW_HIDE);


		Test_Dlg test_dlg;
		test_dlg.DoModal();
		UpdateData(FALSE);

		EndDialog(0);
	}



}


void CMFCChat_v1Dlg::OnBnClickedSignup()
{

	Register_Dlg register_dlg;
	register_dlg.DoModal();


	// TODO: Add your control notification handler code here
}


void CMFCChat_v1Dlg::OnIchatExit()
{
	int msgboxID = MessageBox(_T("Are you sure close app"), _T("iChat"), MB_OKCANCEL|MB_ICONWARNING);
	switch (msgboxID)
	{
	case IDCANCEL:
			break;
	case IDOK:
	{

		EndDialog(1);
	}

	}

}


void CMFCChat_v1Dlg::OnHelpAboutichat()
{
	CAboutDlg about_dlg;
	about_dlg.DoModal();
}


void CMFCChat_v1Dlg::OnClose()
{
	//CDialogEx::OnClose();
	
	int msgboxID = MessageBox(_T("Are you sure close the app"), _T("iChat"), MB_OKCANCEL| MB_ICONWARNING);
		switch (msgboxID)
		{
		case IDCANCEL:
			break;
		case IDOK:
		{

			CWnd::OnClose();
		}

		}
}
