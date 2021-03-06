#pragma once

#include "Define.h"


//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//
//示例 1 :
//
//输入: "abcabcbb"
//	输出 : 3
//	解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//	示例 2 :
//
//	输入 : "bbbbb"
//	输出 : 1
//	解释 : 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//	示例 3 :
//
//	输入 : "pwwkew"
//	输出 : 3
//	解释 : 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//	请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

int lengthOfLongestSubstring(string s) {
	set<char> win;
	int i = 0, j = 0, n = s.length(), max = 0;

	while (i < n && j < n)
	{
		if (win.find(s.at(j)) == win.end())
		{
			win.insert(s.at(j++));
			max = max < win.size() ? win.size() : max;
		}
		else
		{
			win.erase(s.at(i++));
		}
	}

	return max;
}

//超出时间限制
int lengthOfLongestSubstring2(string s) {
	string str = "";
	int max = 0;

	for (int i = 0; i < s.length() - 1; i++)
	{
		for (int j = i; j < s.length(); j++)
		{
			if (indexOf(str, s[j]) < 0)
			{
				str += s[j];
			}
			else
			{
				break;
			}
		}

		if (max < str.length())
		{
			max = str.length();
		}

		str = "";
	}

	return max;
}

int indexOf(string& str, char& s) {
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == s)
		{
			return i;
		}
	}
	return -1;
}