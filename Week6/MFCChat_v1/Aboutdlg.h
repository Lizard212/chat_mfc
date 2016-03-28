#pragma once


// CAboutdlg dialog

class CAboutdlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAboutdlg)

public:
	CAboutdlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAboutdlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
