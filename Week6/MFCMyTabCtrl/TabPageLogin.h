#pragma once


// TabPageLogin dialog

class TabPageLogin : public CDialogEx
{
	DECLARE_DYNAMIC(TabPageLogin)

public:
	TabPageLogin(CWnd* pParent = NULL);   // standard constructor
	virtual ~TabPageLogin();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TABPAGE_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
