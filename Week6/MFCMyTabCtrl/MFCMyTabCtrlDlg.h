
// MFCMyTabCtrlDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include"TabPageLogin.h"

// CMFCMyTabCtrlDlg dialog
class CMFCMyTabCtrlDlg : public CDialogEx
{
// Construction
public:
	CMFCMyTabCtrlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCMYTABCTRL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_MyTabCtrl;
	TabPageLogin tab;
	afx_msg void OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
