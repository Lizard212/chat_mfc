#pragma once
#include "afxwin.h"
#include"Context.h"
#include"PictureCtrl.h"
#include"BUS.h"
#define VM_RESULT_NOTIFY2 (WM_APP + 1102)
// Profile dialog

class Profile : public CDialogEx
{
	DECLARE_DYNAMIC(Profile)

public:
	Profile(CWnd* pParent = NULL);   // standard constructor
	virtual ~Profile();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_PROFILE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()


public:
	HICON hIcon;
	CBrush brush;
	BUS bus;

	CPictureCtrl m_PofileAvatar;
	CStatic m_ProfileName;
	CStatic m_ProfileGender;
	CStatic m_ProfileDateOfBirth;
	CStatic m_ProfileNumber;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg HCURSOR OnQueryDragIcon();
	virtual BOOL OnInitDialog();
	afx_msg LRESULT GetResult(WPARAM p, LPARAM l);
};
