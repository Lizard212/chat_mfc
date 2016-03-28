#pragma once

#include<WinSock2.h>
#include <Windows.h>
#include<iostream>
#include<string>
#include"ServerChatDlg.h"
#include"Context.h"

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT 1234
#define WINSOCK_DEPRECATED_NO_WARNINGS 1

using namespace std;
class CServerChatDlg;

#pragma comment (lib,"Ws2_32.lib")
#pragma comment (lib,"Mswsock.lib")
#pragma comment (lib,"Advapi32.lib")

struct ClientSocket {
	SOCKET s;
	int socket_id;
};

class TcpSocket
{
private:
	WSADATA wsa_data;
	struct sockaddr_in server_infor;
	SOCKET server_socket = INVALID_SOCKET;
	
public:
	bool Create();
	bool InitInfor(string addr);
	bool Listen();
	bool Accept();
	static bool Send(SOCKET s, string message);

	static 	DWORD WINAPI DataThread(LPVOID arg);

	CServerChatDlg *m_pDialog;

	HANDLE m_Thread_handle[100];
	CWinThread *cpTh[100];
	TcpSocket(CServerChatDlg* dialog);
	TcpSocket();
	~TcpSocket();
};

