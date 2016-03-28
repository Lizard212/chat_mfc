#pragma once
#include "AccountRepository.h"
#include "FriendRepository.h"
#include "MessageRepository.h"

	class Bus
	{
	private:
		AccountRepository ar;
		FriendRepository fr;
		MessageRepository mr;
	public:
#pragma region User
		void InsertUser(User u)
		{
			 ar.Insert(u);
		}

		void DeleteUser(int id_user)
		{
			ar.Delete(id_user);
		}

		bool CheckUser(string email, string password)
		{
			return ar.Check(email, password);
		}

		bool CheckEmailUser(string email, string username)
		{
			return ar.CheckEmail(email, username);
		}

		bool CheckUsername(string  username)
		{
			return ar.CheckUsername(username);
		}

		User SelectUser(string email)
		{
			return ar.Select(email);
		}

		string SelectEmailUser(int user_id)
		{
			return ar.SelectEmail(user_id);
		}

		int SelectIdUser(string _username)
		{
			return ar.SelectId(_username);
		}

#pragma endregion

#pragma region Friend
		bool CheckFriendExits(int id_user1, int id_user2)
		{
			return fr.Check(id_user1, id_user2);
		}
		void InsertFriend(Friend _friend)
		{
			fr.Insert(_friend);
		}

		void UpdateFriend(Friend _friend)
		{
			fr.Update(_friend);
		}

		void DeleteFriend(int friend_id)
		{
			fr.Delete(friend_id);
		}

		list<Friend> GetListFriend(int user_id)
		{
			return fr.Select(user_id);
		}
		
		list<Friend> SearchListFriend(string keyword, int user_id)
		{
			return fr.Search(keyword, user_id);
		}

#pragma endregion

#pragma region Message
		void InsertMessage(Message message)
		{
			mr.Insert(message);
		}

		list<Message> GetListMessages(int user_id, int friend_id, int number_of_message)
		{
			return mr.Select(user_id, friend_id, number_of_message);
		}

		void DeleteMessage(int sender_id)
		{
			return mr.Delete(sender_id);
		}
#pragma endregion

	public:
		Bus();
		~Bus();
	};



