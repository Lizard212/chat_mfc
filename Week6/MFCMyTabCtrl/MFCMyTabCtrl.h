
// MFCMyTabCtrl.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCMyTabCtrlApp:
// See MFCMyTabCtrl.cpp for the implementation of this class
//

class CMFCMyTabCtrlApp : public CWinApp
{
public:
	CMFCMyTabCtrlApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedCheckLogin();
};

extern CMFCMyTabCtrlApp theApp;