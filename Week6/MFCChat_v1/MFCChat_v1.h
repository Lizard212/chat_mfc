
// MFCChat_v1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCChat_v1App:
// See MFCChat_v1.cpp for the implementation of this class
//

class CMFCChat_v1App : public CWinApp
{
public:
	CMFCChat_v1App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	
};

extern CMFCChat_v1App theApp;