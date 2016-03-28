#pragma once


// Tab1 dialog

class Tab1 : public CDialogEx
{
	DECLARE_DYNAMIC(Tab1)

public:
	Tab1(CWnd* pParent = NULL);   // standard constructor
	virtual ~Tab1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCMYTABCTRL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
