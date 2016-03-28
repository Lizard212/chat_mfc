
// MFCChat_v1Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include"Register_Dlg.h"
#include"Test_Dlg.h"
#include"BUS.h"
// CMFCChat_v1Dlg dialog
class CMFCChat_v1Dlg : public CDialogEx
{
// Construction
public:
	CMFCChat_v1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCHAT_V1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CBrush m_brush; // creating brush
	CMenu m_menu_login;
	BUS bus;
	
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
	CMFCButton m_Singin_button;
	CFont * m_pFont = new CFont();
	CBitmap m_bitmap;
	CFont * m_pFont1 = new CFont();
public:
	CEdit m_Edit_Email;
	CEdit m_Edit_Password;
	//CStatic m_Picture_Control;
	CStatic m_Picture_Control;
	CStatic m_Picture_Control1;
	afx_msg void OnBnClickedMfclink1();
	afx_msg void OnBnClickedSignin();
protected:
	CMFCButton m_Signup_Button;
public:
	afx_msg void OnBnClickedSignup();
	afx_msg void OnIchatExit();
	afx_msg void OnHelpAboutichat();
	afx_msg void OnClose();
};
