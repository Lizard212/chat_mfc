// Test_Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCChat_v1.h"
#include "Test_Dlg.h"
#include "afxdialogex.h"
#include"MFCChat_v1Dlg.h"
#include"Aboutdlg.h"
#include<gdiplus.h>
#include<thread>


using namespace Gdiplus;

IMPLEMENT_DYNAMIC(Test_Dlg, CDialogEx)
BUS bus;
Test_Dlg::Test_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	//CreateThread(NULL, 0, DatabaseChange, NULL, 0, NULL);
	m_hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	
	
}

Test_Dlg::~Test_Dlg()
{
}

UINT Test_Dlg::LoadMessages(LPVOID param)
{
	

	while (1)
	{

		THREADSTRUCT* ts = (THREADSTRUCT*)param;
		int num_of_messages = bus.CountMessages();
		if (num_of_messages >= 0)
		{
			CString s("1");
			Account account = Context::getAccount();
			
			//::SendMessage(handle2,VM_RESULT_NOTITY1, (WPARAM)(LPCTSTR)s, NULL);
			list<Message> list_messages = bus.message_Select(account.getEmail(),10 );
			ts->_this->m_List_Message1.ResetContent();
			list<Message>::iterator j;
			for (j = list_messages.begin(); j != list_messages.end(); ++j)
			{

				ts->_this->m_List_Message1.AddString(CString(j->getContent().c_str()));

			}

		}
		Sleep(100);
	}

	
	return 0;
}

void Test_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_USERNAME_, m_iChat_username);
	DDX_Control(pDX, IDC_STATUS, m_iChat_status);
	//DDX_Control(pDX, IDC_LIST_FRIENDS, m_List_friends);
	DDX_Control(pDX, IDC_LIST_MESSAGE1, m_List_Message1);
	DDX_Control(pDX, IDC_EDIT1, m_message1);
	DDX_Control(pDX, IDSEND, m_button_send1);

	DDX_Control(pDX, IDC_AVATAR, m_iChat_avarchar);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	DDX_Control(pDX, IDC_EDIT3, m_search);
	DDX_Control(pDX, IDC_BUTTON_SEARCH, m_button_search);
	DDX_Control(pDX, IDC_AVATAR_FRIEND, m_avatar_friend);
	DDX_Control(pDX, IDC_FRIEND_NAME, m_friend_name);
	DDX_Control(pDX, IDC_FRIEND_STATUS, m_friend_status);
	DDX_Control(pDX, ID_EMOTICON, m_button_emojj);
}


BEGIN_MESSAGE_MAP(Test_Dlg, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_QUERYDRAGICON()
	//ON_MESSAGE(VM_RESULT_NOTIFY, &Chat2::GetResult)
	//ON_MESSAGE(VM_RESULT_NOTITY1, &Test_Dlg::GetResult)
	ON_MESSAGE(VM_RESULT_NOTIFY2,&Profile::GetResult)
	ON_MESSAGE(VM_RESULT_NOTITY1, &Test_Dlg::GetMessages)
	ON_BN_CLICKED(IDSEND, &Test_Dlg::OnBnClickedSend)
	ON_COMMAND(ID_ICHAT_SIGNOUT, &Test_Dlg::OnIchatSignout)
	ON_COMMAND(ID_ICHAT_CLOSE, &Test_Dlg::OnIchatClose)
	ON_COMMAND(ID_HELP_ABOUTICHAT32781, &Test_Dlg::OnHelpAboutichat32781)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &Test_Dlg::OnLvnItemchangedList1)
	ON_EN_CHANGE(IDC_EDIT3, &Test_Dlg::OnEnChangeEdit3)
	ON_STN_CLICKED(IDC_FRIEND_NAME, &Test_Dlg::OnStnClickedFriendName)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_POPUP_VIEWPROFILE, &Test_Dlg::OnPopupViewprofile)
END_MESSAGE_MAP()


// Test_Dlg message handlers


BOOL Test_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// Set menu
	main_menu.LoadMenuW(IDR_MENU2);
	SetMenu(&main_menu);

	// Set Icon
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Create brush
	m_brush.CreateSolidBrush(RGB(255, 255, 255));
    // Set icon button search
	m_button_search.ModifyStyle(0, BS_ICON);
	HICON hIcn1 = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON2), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
	m_button_search.SetIcon(hIcn1);
	// Set icon button emotion
	m_button_emojj.ModifyStyle(0, BS_ICON);
	HICON hIcn2 = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON5), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	m_button_emojj.SetIcon(hIcn2);
	// Get Account
	Account account = Context::getAccount();

	// Load avatar
	//m_Picture_Control_Avatar.SetBitmap((HBITMAP)m_bitmap.Detach());

	// Set username  and Status
	string temp0 = account.getFirstName() + " " + account.getLastName();
	CString temp1(temp0.c_str());
	CString temp2(account.getStatus().c_str());
	m_iChat_username.SetWindowText(temp1);
	m_iChat_status.SetWindowText(temp2);

	// Load avatar
	CString a(account.getAvatar().c_str());
	m_iChat_avarchar.Load(a);

	
	// Setup columns
	InitListCtrl();
	// Load List friends
	LoadListFriends();
	// Load list Image
	InitListImage();
	
	// 
	InitDialogPofile();

	    //HWND handle2 = this->GetSafeHwnd();

	
		//HANDLE hThread = CreateThread(NULL, 0, DatabaseChange, NULL, 0, NULL);
	OnStart();


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}



LRESULT Test_Dlg::SendMessage(UINT ,WPARAM, LPARAM)
{
	return LRESULT();
}



LRESULT Test_Dlg::GetMessages(WPARAM w, LPARAM l)
{
	Account account = Context::getAccount();
	string s(CT2A((LPCTSTR)w));
	if (s == "1")
	{

		list<Message> list_messages = bus.message_Select(account.getEmail(), 20);
		list<Message>::iterator j;
		for (j = list_messages.begin(); j != list_messages.end(); ++j)
		{

			m_List_Message1.AddString(CString(j->getContent().c_str()));

		}
	}
	return LRESULT();

}

HBRUSH Test_Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	hbr = m_brush;
	return hbr;
}


HCURSOR Test_Dlg::OnQueryDragIcon()
{

	return static_cast<HCURSOR>(m_hIcon);
}


void Test_Dlg::LoadListFriends()
{
	Account account = Context::getAccount();
	list<Friend> list_friend = bus.friend_Select_All();

	list<Friend>::iterator i;
	for (i = list_friend.begin(); i != list_friend.end(); ++i)
	{
		CString str(i->getFriendName().c_str());
		m_ListCtrl.InsertItem(0, str);
	
	}

}

void Test_Dlg::OnBnClickedSend()
{
	UpdateData(TRUE);
	CString s;
	m_message1.GetWindowTextW(s);
	CT2A temp(s); string str(temp);
	Account account = Context::getAccount();
	if (str == "")
	{
		return;
	}
	int temp1_count_messages = bus.CountMessages();
	// Insert mesage
	Message message;
	message.setContent(str);
	message.setIdSender(account.getIdAccount());
	message.setIdReceiver(Context::getIdAccount());
	bus.message_Insert(message);
	//HANDLE hThread = CreateThread(NULL, 0, DatabaseChange, NULL, 0, NULL);
	//chat2->ShowWindow(SW_SHOW);
	//chat2->SendMessage(VM_RESULT_NOTIFY, (WPARAM)(LPCTSTR)s, NULL);

	//m_List_Message1.AddString(s);
	// TODO: Add your control notification handler code here
}

LRESULT Test_Dlg::GetResult(WPARAM w, LPARAM l)
{
	UpdateData(TRUE);

	m_List_Message1.AddString((LPCTSTR)w);
	
	return LRESULT();

}

void Test_Dlg::OnIchatSignout()
{
	MessageBox(_T("You have logged out "), _T("iChat"), MB_OK);
	this->EndDialog(1);
	CMFCChat_v1Dlg signin;
	signin.DoModal();
}

void Test_Dlg::OnIchatClose()
{
	int msgboxID = MessageBox(_T("Are you sure close app"), _T("iChat"), MB_OKCANCEL | MB_ICONWARNING);
	switch (msgboxID)
	{
	case IDCANCEL:
		break;
	case IDOK:
	{

		EndDialog(1);
	}

	}
}

void Test_Dlg::OnHelpAboutichat32781()
{
	  
	CAboutdlg c;
	c.DoModal();
	
}

void Test_Dlg::InitListCtrl()
{
	CRect rect;
	m_ListCtrl.GetClientRect(&rect);
	int nColInterval = rect.Width();

	m_ListCtrl.InsertColumn(0, _T("Friends"),LVCFMT_LEFT,nColInterval);
}

BOOL Test_Dlg::InitListImage()
{	
	
	m_list_images.Create(32, 32, ILC_COLOR32, 2, 2);
	m_list_images.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_ListCtrl.SetImageList(&m_list_images, LVSIL_SMALL);

	return TRUE;
}

void Test_Dlg::InsertItem()
{


} 

void Test_Dlg::InitDialogPofile()
{
	
	profile = new Profile();
	if (profile != NULL)
	{
		BOOL ret = profile->Create(IDD_DIALOG_PROFILE, this);
		if(!ret) // Create failed
		{
			AfxMessageBox(_T("Error creating Dialog"));
		}
	}
}

void Test_Dlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	int temp_id;
	POSITION pos = m_ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		return;
	}
	else
	{
		while (pos)
		{
			int nItem = m_ListCtrl.GetNextSelectedItem(pos);
			Account account;
			list<Friend> list_friend = bus.friend_Select_All();
			
			list<Friend>::iterator i = list_friend.begin();
			advance(i, nItem );
			Context::setIdAccount(i->getIdFriend());

			string temp_email = bus.selectEmail(i->getIdFriend());
			   Account temp_account =	bus.Select(temp_email);


			string temp0 = temp_account.getFirstName() + " " + temp_account.getLastName();
			CString temp1(temp0.c_str());
			CString temp2(temp_account.getStatus().c_str());
			m_friend_name.SetWindowText(temp1);
			m_friend_status.SetWindowText(temp2);
			
			// Load avatar
			CString a(temp_account.getAvatar().c_str());
			m_avatar_friend.Load(a);

		   // Load list messages
	
			

			UpdateData(FALSE);

		}	
	}
	*pResult = 0;
	
}
	
// Search in list friend when you type text on search text
void Test_Dlg::OnEnChangeEdit3()
{
	
	CString keywords;
	m_search.GetWindowText(keywords);
	CT2CA pszName1(keywords); string words(pszName1);
	if (words == "") 
	{
		m_ListCtrl.DeleteAllItems();
		LoadListFriends();
	}
	else
	{
		Account account = Context::getAccount();
		m_ListCtrl.DeleteAllItems();
		list<Friend> list_friend = bus.friend_Search(words);

		list<Friend>::iterator i;
		for (i = list_friend.begin(); i != list_friend.end(); ++i)
		{
			CString str(i->getFriendName().c_str());
			m_ListCtrl.InsertItem(0, str);

		}
		
	}
}


void Test_Dlg::OnStnClickedFriendName()
{
	// TODO: Add your control notification handler code here
}


// Show context menu when right click on list control
void Test_Dlg::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{

	CMenu menu;
	VERIFY(menu.LoadMenu(IDR_MENU3));
	CMenu* pPopup = menu.GetSubMenu(0);

	int selected = m_ListCtrl.GetNextItem(-1, LVNI_SELECTED);
	if (selected < 0)
	{
		return;
	}

	RECT rect;
	GetWindowRect(&rect);
	CPoint mousepos;
	GetCursorPos(&mousepos);
	pPopup->TrackPopupMenu(NULL, mousepos.x, mousepos.y, this);

}

void Test_Dlg::OnStart()
{
	THREADSTRUCT *_param = new THREADSTRUCT;
	_param->_this = this;
	AfxBeginThread(LoadMessages, _param);

}


// Event click on right clicked view profile

void Test_Dlg::OnPopupViewprofile()
{
	int temp_id = Context::getIdAccount();

	profile->SendMessage(VM_RESULT_NOTIFY2, NULL, (LPARAM)temp_id);
	profile->ShowWindow(SW_SHOW);

}
// 
//chat2 = new Chat2();
//if (chat2 != NULL)
//{
//	BOOL ret = chat2->Create(IDD_CHAT, this);
//	if (!ret) // Create failed
//	{
//		AfxMessageBox(_T("Error creating Dialog"));
//	}
//}
////

//HWND hwnd_chat2 = this->GetSafeHwnd();
//chat2->hwnd_chat1 = hwnd_chat2;
