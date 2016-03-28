#pragma once
#include "afxwin.h"
#include"AccountRepository.h"
#include"Context.h"
#include"PictureCtrl.h"
#include "afxcmn.h"
#include"BUS.h"
#include"MFCChat_v1Dlg.h"
#include"Chat2.h"
#include<iostream>
#include"Profile.h"
#define VM_RESULT_NOTIFY (WM_APP + 1100)
#define VM_RESULT_NOTITY1 (WM_APP + 1101) 
#define VM_RESULT_NOTIFY2 (WM_APP + 1102)

// Test_Dlg dialog


class Test_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Test_Dlg)

public:
	Test_Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~Test_Dlg();

	static UINT LoadMessages(LPVOID param);

	typedef struct THREADSTRUCT
	{ 
		Test_Dlg*  _this;
	}THREADSTRUCT;


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CMenu main_menu;
	HICON m_hIcon;
	CBrush m_brush;

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg HCURSOR OnQueryDragIcon();
	void LoadListFriends();
	CStatic m_iChat_username;
	CStatic m_iChat_status;
	//CListBox m_List_friends;
	CListBox m_List_Message1;
	CEdit m_message1;
	CButton m_button_send1;
	CImage m_list_image;
	CImageList m_list_images;
	CBitmap bmp;
	CListCtrl m_ListCtrl;
	afx_msg LRESULT GetResult(WPARAM w, LPARAM l);
	
	Chat2 *chat2;
	Profile* profile;
	CPictureCtrl m_iChat_avarchar;
	afx_msg void OnBnClickedSend();
	afx_msg void OnIchatSignout();
	afx_msg void OnIchatClose();
	afx_msg void OnHelpAboutichat32781();
	afx_msg void InitListCtrl();
	afx_msg BOOL InitListImage();
	afx_msg void InsertItem();
	afx_msg void InitDialogPofile();

   // static DWORD WINAPI DatabaseChange(LPVOID arg);
	static LRESULT WINAPI SendMessage(UINT, WPARAM, LPARAM);
	afx_msg LRESULT GetMessages(WPARAM w, LPARAM l);

	
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit3();
	CEdit m_search;
	CButton m_button_search;
	afx_msg void OnStnClickedFriendName();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);

	CPictureCtrl m_avatar_friend;
	CStatic m_friend_name;
	CStatic m_friend_status;
	 HWND handle2;
	 afx_msg void OnStart();
	 CButton m_button_emojj;
	 afx_msg void OnPopupViewprofile();
};
