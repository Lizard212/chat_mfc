
// ServerChatDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include"TcpSocket.h"
#include<string>
using namespace std;

// CServerChatDlg dialog
class CServerChatDlg : public CDialogEx
{
// Construction
public:
	CServerChatDlg(CWnd* pParent = NULL);	// standard constructor
	void ShowServerInfor(string sValue);
	void AppendTextToEditCtrl(CListBox& edit, LPCTSTR pszText);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERVERCHAT_DIALOG };
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
	CListBox m_list_status_connection;
	CButton m_btn_start;
	CButton m_btn_stop;
	CStatic m_label_ip;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	UINT ThreadFunc();
	static UINT _cdecl StaticThreadFunc(LPVOID param);
private:
	HANDLE m_thread_handle;
	CWinThread *cTh;
	//TcpSocket  *m_tcpsocket;
};
