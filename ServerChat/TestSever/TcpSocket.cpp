#include "stdafx.h"
#include "TcpSocket.h"
#include<WS2tcpip.h>
//#include"ServerChat.h"
#include"Parse.h"

bool TcpSocket::Create()
{
	
	if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0)
	{
		//cout << "Failed. Error code :" << WSAGetLastError();
		return false;
	}
	//str.Format(_T())
	cout << "Initialised.\n";

	if ((server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
	{
		cout << "Could not create socket :  ", WSAGetLastError();
	}

	cout << "Socket created.\n";
	return true;
}

bool TcpSocket::InitInfor(string addr)
{


	server_infor.sin_family = AF_INET;
	server_infor.sin_port = htons(DEFAULT_PORT);
	server_infor.sin_addr.s_addr = ADDR_ANY;
	return true;
}

bool TcpSocket::Listen()
{
	if (bind(server_socket, (struct sockaddr*)&server_infor, sizeof(server_infor)) == SOCKET_ERROR)
	{
		cout << "Bind failed with error code : " << WSAGetLastError();

		return false;
		exit(1);
	}
	cout << "Bind done.\n";
	if (listen(server_socket, SOMAXCONN) == SOCKET_ERROR)
	{
		cout << " Listen failed with error :  \n" << WSAGetLastError();
		closesocket(server_socket);
		WSACleanup();
		return false;
	}
	
	return true;

}

bool TcpSocket::Accept()
{
	
	int count_connection = 0;
	while (1)
	{

		SOCKET client_socket = INVALID_SOCKET;

			client_socket = accept(server_socket, NULL, NULL);
		if (client_socket == INVALID_SOCKET)
		{
			printf("accept failed : %d \n", WSAGetLastError());
			closesocket(server_socket);
			WSACleanup();
			return false;
		}

 		++count_connection;

		// Get IP client
		socklen_t len;
		struct sockaddr_storage addr;
		char ipstr[INET6_ADDRSTRLEN];
		int port;
		getpeername(client_socket, (struct sockaddr*)&addr, &len);

		len = sizeof addr;
		if (addr.ss_family == AF_INET)
		{
			struct sockaddr_in *s = (struct sockaddr_in*)&addr;
			port = ntohs(s->sin_port);
			inet_ntop(AF_INET, &s->sin_addr, ipstr, sizeof ipstr);
		}
		//m_pDialog->ShowServerInfor("Connected peer IP address: " + string(ipstr) + "\n");


		ClientSocket client;

		client.s = client_socket;
		client.socket_id = count_connection;

		HANDLE hand = CreateThread(NULL, 0, DataThread, (LPVOID)&client, 0, NULL);
		
	}
	

}

bool TcpSocket::Send(SOCKET s, string message)
{
	if (send(s, message.c_str(), message.size(), 0) < 0)
	{
		return false;
	}
	return true;
	
}



DWORD TcpSocket::DataThread(LPVOID arg)
{
	ClientSocket *client_socket = (ClientSocket *)arg;
	ClientSocket client = *client_socket;
	string s;
	string buff;
	char buffer[2000];
	Parse j;
	int result, recv_size;
	string  t = "test";
	while (1)
	{
		result = recv(client.s, buffer, 20000, 0);
		if (result > 0)
		{ 
			buffer[result -1] = '\0';
			cout << buffer << endl;
			
			//
			s = j.ParseJson(string(buffer));
			if (send(client.s, s.c_str(), j.ParseJson(string(buffer)).size() , 0) < 0)
			{
				break;
			}
			//buff = string(buffer).size() - 1;
			//if (Send(client.s,j.ParseJson(string(buffer)) )== false)
			//{
			//	break;
			//}

		}
		else
		{
			cout << "Error id : " << WSAGetLastError();
			break;
		}
		//Sleep(100);
	}

	return 0;
}




TcpSocket::TcpSocket(CServerChatDlg * dialog)
{
	m_pDialog = dialog;
}

TcpSocket::TcpSocket()
{
}

TcpSocket::~TcpSocket()
{
	closesocket(server_socket);
	WSACleanup();
}
