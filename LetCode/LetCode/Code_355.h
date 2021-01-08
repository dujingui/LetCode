#pragma once

#include "Define.h"

//355. �������
//���һ���򻯰������(Twitter)���������û�ʵ�ַ������ģ���ע / ȡ����ע�����û����ܹ�������ע�ˣ������Լ��������ʮ�����ġ���������Ҫ֧�����µļ������ܣ�
//
//postTweet(userId, tweetId) : ����һ���µ�����
//getNewsFeed(userId) : ���������ʮ�����ġ�ÿ�����Ķ��������ɴ��û���ע���˻������û��Լ������ġ����ı��밴��ʱ��˳��������Ŀ�ʼ����
//follow(followerId, followeeId) : ��עһ���û�
//unfollow(followerId, followeeId) : ȡ����עһ���û�
//ʾ�� :
//
//Twitter twitter = new Twitter();
//
//// �û�1������һ�������� (�û�id = 1, ����id = 5).
//twitter.postTweet(1, 5);
//
//// �û�1�Ļ�ȡ����Ӧ������һ���б����а���һ��idΪ5������.
//twitter.getNewsFeed(1);
//
//// �û�1��ע���û�2.
//twitter.follow(1, 2);
//
//// �û�2������һ�������� (����id = 6).
//twitter.postTweet(2, 6);
//
//// �û�1�Ļ�ȡ����Ӧ������һ���б����а����������ģ�id�ֱ�Ϊ -> [6, 5].
//// ����id6Ӧ��������id5֮ǰ����Ϊ������5֮���͵�.
//twitter.getNewsFeed(1);
//
//// �û�1ȡ����ע���û�2.
//twitter.unfollow(1, 2);
//
//// �û�1�Ļ�ȡ����Ӧ������һ���б����а���һ��idΪ5������.
//// ��Ϊ�û�1�Ѿ����ٹ�ע�û�2.
//twitter.getNewsFeed(1);



class CTweet {
public:
	CTweet(int id, int sortID)
	{
		m_nID = id;
		m_nSortID = sortID;
	}

	int GetSortID() { return m_nSortID; }

	int GetID() { return m_nID; }
private:
	int m_nID;
	//Խ��Խ��
	int m_nSortID;
};

class CUser {
public:
	CUser(int userID)
	{
		m_nUserID = userID;
	}

	void postTweet(CTweet* pTweet)
	{
		m_TweetVec.push_back(pTweet);
	}

	void follow(int followeeID) {
		if (followeeID == m_nUserID)return;

		m_FolloweeSet.insert(followeeID);
	}

	void unfollow(int followeeID) {
		auto iter = m_FolloweeSet.find(followeeID);
		if (iter == m_FolloweeSet.end())
		{
			return;
		}

		m_FolloweeSet.erase(iter);
	}

	vector<CTweet*> getNewsFeed(int num) {
		vector<CTweet*> ret;

		for (int i = m_TweetVec.size() - 1; i >= 0; i --)
		{
			if (ret.size() >= num)
			{
				break;
			}

			ret.push_back(m_TweetVec[i]);
		}

		return ret;
	}

	unordered_set<int>& getFolloweeVec()
	{
		return m_FolloweeSet;
	}
private:
	int m_nUserID;
	//�����б�
	vector<CTweet*> m_TweetVec;
	//��ע���˵��б�
	unordered_set<int> m_FolloweeSet;
};


class Twitter 
{
public:
	Twitter() {
		m_nTweetSortID = 1;
	}

	void postTweet(int userId, int tweetId) {

		CTweet* tweet = new CTweet(tweetId, m_nTweetSortID ++);

		auto iter = m_UserMap.find(userId);
		if (iter == m_UserMap.end())
		{
			auto user = new CUser(userId);
			user->postTweet(tweet);

			m_UserMap.insert(make_pair(userId, user));

			return;
		}

		(*iter).second->postTweet(tweet);
	}

	static bool tweetCompare(CTweet* a, CTweet* b) {
		return a->GetSortID() > b->GetSortID();
	}

	vector<int> getNewsFeed(int userId) {
		vector<int> ret;

		int num = 10;

		auto iter = m_UserMap.find(userId);
		if (iter == m_UserMap.end())
		{
			return ret;
		}

		auto pUser = (*iter).second;

		vector<CTweet*> newsfeedVec = pUser->getNewsFeed(num);

		unordered_set<int>& followeeVec = pUser->getFolloweeVec();
		for (auto iter1 = followeeVec.begin(); iter1 != followeeVec.end(); iter1++)
		{
			auto iter2 = m_UserMap.find(*iter1);
			if (iter2 == m_UserMap.end())
			{
				continue;
			}

			auto iter3 = (*iter2).second->getNewsFeed(num);

			newsfeedVec.insert(newsfeedVec.end(), iter3.begin(), iter3.end());
		}

		sort(newsfeedVec.begin(), newsfeedVec.end(), tweetCompare);

		for (int i = 0; i < newsfeedVec.size(); i++)
		{
			ret.push_back(newsfeedVec[i]->GetID());

			if (ret.size() >= num)
			{
				break;
			}
		}

		return ret;
	}

	void follow(int followerId, int followeeId) {
		auto iter = m_UserMap.find(followerId);
		if (iter == m_UserMap.end())
		{
			auto user = new CUser(followerId);
			m_UserMap.insert(make_pair(followerId, user));

			user->follow(followeeId);

			return;
		}

		(*iter).second->follow(followeeId);
	}

	void unfollow(int followerId, int followeeId) {
		auto iter = m_UserMap.find(followerId);
		if (iter == m_UserMap.end())
		{
			return;
		}

		(*iter).second->unfollow(followeeId);
	}

private:
	map<int, CUser*> m_UserMap;
	int m_nTweetSortID;
};


void test_355() {
	Twitter twitter;
	// �û�1������һ�������� (�û�id = 1, ����id = 5).
	twitter.postTweet(1, 5);

	// �û�1�Ļ�ȡ����Ӧ������һ���б����а���һ��idΪ5������.
	twitter.getNewsFeed(1);

	// �û�1��ע���û�2.
	twitter.follow(1, 2);

	// �û�2������һ�������� (����id = 6).
	twitter.postTweet(2, 6);

	// �û�1�Ļ�ȡ����Ӧ������һ���б����а����������ģ�id�ֱ�Ϊ -> [6, 5].
	// ����id6Ӧ��������id5֮ǰ����Ϊ������5֮���͵�.
	twitter.getNewsFeed(1);

	// �û�1ȡ����ע���û�2.
	twitter.unfollow(1, 2);

	// �û�1�Ļ�ȡ����Ӧ������һ���б����а���һ��idΪ5������.
	// ��Ϊ�û�1�Ѿ����ٹ�ע�û�2.
	twitter.getNewsFeed(1);

}

void test_355_2()
{
	//["Twitter", "postTweet", "follow", "getNewsFeed"]
	//[[], [1, 5], [1, 1], [1]]

	Twitter twitter;
	twitter.postTweet(1, 5);
	twitter.follow(1, 1);
	twitter.getNewsFeed(1);
}

void test_355_3()
{
	//["Twitter", "postTweet", "getNewsFeed", "follow", "getNewsFeed", "unfollow", "getNewsFeed"]
	//[[], [1, 1], [1], [2, 1], [2], [2, 1], [2]]

	Twitter twitter;
	twitter.postTweet(1, 1);
	twitter.getNewsFeed(1);
	twitter.follow(2, 1);
	twitter.getNewsFeed(2);
	twitter.unfollow(2, 1);
	twitter.getNewsFeed(2);
}