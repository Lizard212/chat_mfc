#pragma once


// CProTabPageLogin dialog

class CProTabPageLogin : public CPropertyPage
{
	DECLARE_DYNAMIC(CProTabPageLogin)

public:
	CProTabPageLogin();
	virtual ~CProTabPageLogin();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TABPAGE_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
