#pragma once
#include "afxwin.h"
#include "afxdtctl.h"
#include<string>
#include"BUS.h"
#include"stdafx.h"
using namespace std;
// Register_Dlg dialog

class Register_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Register_Dlg)

public:
	Register_Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~Register_Dlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REGISTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	HICON m_Hicon;
	CBrush m_Brush;
	BUS bus;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg HCURSOR OnQueryDragIcon();
	CButton m_Button_Register;
	CEdit m_register_email;
	CEdit m_register_password;
	CEdit m_register_repassword;
	CEdit m_first_name;
	CEdit m_register_last_name;
	CDateTimeCtrl m_register_date_of_birth;
	CComboBox m_register_gender;
	afx_msg void OnBnClickedRegister();
};
