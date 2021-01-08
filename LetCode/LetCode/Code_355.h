#pragma once

#include "Define.h"

//355. 设计推特
//设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注 / 取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：
//
//postTweet(userId, tweetId) : 创建一条新的推文
//getNewsFeed(userId) : 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
//follow(followerId, followeeId) : 关注一个用户
//unfollow(followerId, followeeId) : 取消关注一个用户
//示例 :
//
//Twitter twitter = new Twitter();
//
//// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
//twitter.postTweet(1, 5);
//
//// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
//twitter.getNewsFeed(1);
//
//// 用户1关注了用户2.
//twitter.follow(1, 2);
//
//// 用户2发送了一个新推文 (推文id = 6).
//twitter.postTweet(2, 6);
//
//// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
//// 推文id6应当在推文id5之前，因为它是在5之后发送的.
//twitter.getNewsFeed(1);
//
//// 用户1取消关注了用户2.
//twitter.unfollow(1, 2);
//
//// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
//// 因为用户1已经不再关注用户2.
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
	//越大越近
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
		m_FolloweeVec.push_back(followeeID);
	}

	void unfollow(int followeeID) {
		for (int i = 0; i < m_FolloweeVec.size(); i++)
		{
			if (m_FolloweeVec[i] == followeeID)
			{
				m_FolloweeVec.erase(m_FolloweeVec.begin() + i);
				break;
			}
		}
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

	vector<int>& getFolloweeVec()
	{
		return m_FolloweeVec;
	}
private:
	int m_nUserID;
	//推文列表
	vector<CTweet*> m_TweetVec;
	//关注的人的列表
	vector<int> m_FolloweeVec;
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

		vector<int>& followeeVec = pUser->getFolloweeVec();
		for (int i = 0; i < followeeVec.size(); i++)
		{
			auto iter2 = m_UserMap.find(followeeVec[i]);
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
	// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
	twitter.postTweet(1, 5);

	// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
	twitter.getNewsFeed(1);

	// 用户1关注了用户2.
	twitter.follow(1, 2);

	// 用户2发送了一个新推文 (推文id = 6).
	twitter.postTweet(2, 6);

	// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
	// 推文id6应当在推文id5之前，因为它是在5之后发送的.
	twitter.getNewsFeed(1);

	// 用户1取消关注了用户2.
	twitter.unfollow(1, 2);

	// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
	// 因为用户1已经不再关注用户2.
	twitter.getNewsFeed(1);

}