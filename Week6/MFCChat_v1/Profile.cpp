// Profile.cpp : implementation file
//

#include "stdafx.h"
#include "MFCChat_v1.h"
#include "Profile.h"
#include "afxdialogex.h"


// Profile dialog

IMPLEMENT_DYNAMIC(Profile, CDialogEx)

Profile::Profile(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_PROFILE, pParent)
{
	hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
}

Profile::~Profile()
{
}

void Profile::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_AVATAR_PROFILE, m_PofileAvatar);
	DDX_Control(pDX, IDC_PROFILE_NAME, m_ProfileName);
	DDX_Control(pDX, IDC_PROFILE_GENDER, m_ProfileGender);
	DDX_Control(pDX, IDC_PROFILE_BIRTHDAY, m_ProfileDateOfBirth);
	DDX_Control(pDX, IDC_PROFILE_PHONE, m_ProfileNumber);
}


BEGIN_MESSAGE_MAP(Profile, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(VM_RESULT_NOTIFY2,&Profile::GetResult)
END_MESSAGE_MAP()


// Profile message handlers


HBRUSH Profile::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	hbr = brush;

	return hbr;
}


HCURSOR Profile::OnQueryDragIcon()
{
	
	return static_cast<HCURSOR>(hIcon);
}


BOOL Profile::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// Set Icon
	SetIcon(hIcon, TRUE);
	SetIcon(hIcon, FALSE);
	
	// create brush
	brush.CreateSolidBrush(RGB(255, 255, 255));


	return TRUE;  
}

LRESULT Profile::GetResult(WPARAM p, LPARAM l)
{
	UpdateData(TRUE);
	Account temp_account = bus.Select(bus.selectEmail(l));
	string temp_name = temp_account.getFirstName() + " " + temp_account.getLastName();

	m_ProfileName.SetWindowText(CString(temp_name.c_str()));
	m_ProfileGender.SetWindowText(CString(temp_account.getSex().c_str()));
	m_ProfileDateOfBirth.SetWindowText(CString(temp_account.getDate_of_birth().c_str()));
	m_ProfileNumber.SetWindowText(CString(temp_account.getPhoneNumber().c_str()));
	CString a(temp_account.getAvatar().c_str());
	m_PofileAvatar.Load(a);
	UpdateData(FALSE);

	return LRESULT();
}
