#pragma once

#include "Define.h"

//516. 最长回文子序列 ?
//给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。
//
//示例 1:
//输入:
//
//"bbbab"
//输出 :
//
//	4
//	一个可能的最长回文子序列为 "bbbb"。
//
//	示例 2 :
//	输入 :
//
//	"cbbd"
//	输出 :
//
//	2
//	一个可能的最长回文子序列为 "bb"。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/longest-palindromic-subsequence
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int longestPalindromeSubseq(string s) {
	int maxLen = 0;
	vector<char> lv;
	vector<char> rv;

	vector<char> tlv;
	vector<char> trv;

	for (int i = 0; i < s.length() - 1; i++)
	{
		int len = 0;
		for (int l = i; l < s.length() - 1; l++)
		{
			for (int r = s.length() - 1; r > l; r--)
			{
				if (s[l] == s[r])
				{
					r--;
					len += 2;
					tlv.push_back(s[l]);
					trv[0] = s[r];
					break;
				}
			}
		}

		if (len > maxLen)
		{
			lv = tlv;
			rv = trv;
			maxLen = len;
		}
	}

	for (int i = 0; i < lv.size(); i++)
	{
		std::cout << lv[i];
	}

	return 0;
}

void test_516()
{
	std::vector<int> vec = { 1,2,3,6,2,3,4,7,8 };

	string str = "bbbab";
	std::cout << longestPalindromeSubseq(str) << endl;
}























int b()
{
	int a = 5;
	int b = 8;

	return a + b;
}