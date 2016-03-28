// Register_Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCChat_v1.h"
#include "Register_Dlg.h"
#include "afxdialogex.h"
#include"MFCChat_v1Dlg.h"

// Register_Dlg dialog

IMPLEMENT_DYNAMIC(Register_Dlg, CDialogEx)

Register_Dlg::Register_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_REGISTER, pParent)
{
	m_Hicon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));

}

Register_Dlg::~Register_Dlg()
{
}

void Register_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDREGISTER, m_Button_Register);
	DDX_Control(pDX, IDC_EDIT1, m_register_email);
	DDX_Control(pDX, IDC_EDIT2, m_register_password);
	DDX_Control(pDX, IDC_EDIT3, m_register_repassword);
	DDX_Control(pDX, IDC_EDIT4, m_first_name);
	DDX_Control(pDX, IDC_EDIT6, m_register_last_name);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_register_date_of_birth);
	DDX_Control(pDX, IDC_COMBO_GENDER, m_register_gender);
}


BEGIN_MESSAGE_MAP(Register_Dlg, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDREGISTER, &Register_Dlg::OnBnClickedRegister)
END_MESSAGE_MAP()


// Register_Dlg message handlers


HBRUSH Register_Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	hbr = m_Brush;

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}


BOOL Register_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// Set Icon
	SetIcon(m_Hicon, TRUE);
	SetIcon(m_Hicon, FALSE);

	// Set defaul value of combo gender index = 0
	m_register_gender.SetCurSel(0);
	//
	m_Brush.CreateSolidBrush(RGB(255, 255, 255));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


HCURSOR Register_Dlg::OnQueryDragIcon()
{
	// TODO: Add your message handler code here and/or call default
	return static_cast<HCURSOR>(m_Hicon);

}


void Register_Dlg::OnBnClickedRegister()
{
	UpdateData(TRUE);
	CString email, password, repassword, firstname, lastname, date_of_birth, gender;

	m_register_email.GetWindowTextW(email);
	m_register_password.GetWindowTextW(password);
	m_register_repassword.GetWindowTextW(repassword);
	m_register_last_name.GetWindowTextW(lastname);
	m_first_name.GetWindowTextW(firstname);
	m_register_date_of_birth.GetWindowTextW(date_of_birth);
	int index = m_register_gender.GetCurSel();
	m_register_gender.GetLBText(index, gender);

	CT2CA pszName1(email); string _email(pszName1);
	CT2CA pszName2(password);string _password(pszName2);
	CT2CA pszName3(repassword);string _repassword(pszName3);
	CT2CA pszName4(firstname);string _firstname(pszName4);
	CT2CA pszName5(lastname);string _lassname(pszName5);
	CT2CA pszName6(date_of_birth);string _date_of_birth(pszName6);
	CT2CA pszName7(gender);string _gender(pszName7);

	if (bus.checkEmail(_email))
	{
		MessageBox(_T("Email is exists"), _T("Warning"), MB_OK | MB_ICONWARNING);
		return;
	}
	if (_password != _repassword)
	{
		MessageBox(_T("Password and repassword not match"), _T("Warning"), MB_OK | MB_ICONWARNING);
		return;
	}
	if (_email == "" || _password == "" || _firstname == "" || _lassname == "")
	{
		MessageBox(_T("You  have not  filled out enough information"), _T("Warning"), MB_OK | MB_ICONWARNING);
		return;
	}

	Account account(NULL, _email, "0", _password, _firstname, _lassname, _date_of_birth, _gender, "", "res\\tieu_ngao.jpg", "Have a nice day");
	bus.Insert(account);
	MessageBox(_T("Register successfully ! \n Sign in to continue."), _T("iChat"), MB_OK | MB_ICONINFORMATION);


	UpdateData(FALSE);


	EndDialog(0);

}
