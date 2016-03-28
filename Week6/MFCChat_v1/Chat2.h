#pragma once
#include"afxwin.h"
#include<string>
using namespace std;

#define VM_RESULT_NOTIFY (WM_APP + 1100)
#define VM_RESULT_NOTITY1 (WM_APP + 1101 )
// Chat2 dialog

// Chat2 dialog

class Chat2 : public CDialogEx
{
	DECLARE_DYNAMIC(Chat2)

public:
	Chat2(CWnd* pParent = NULL);   // standard constructor
	virtual ~Chat2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg LRESULT GetResult(WPARAM w, LPARAM l);
	HWND hwnd_chat1;
	CEdit m_message2;
	afx_msg void OnBnClickedButtonSend2();
	CListBox m_list_message2;
};
