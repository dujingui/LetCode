#pragma once

#include "Define.h"

//516. ����������� ?
//����һ���ַ���s���ҵ�������Ļ��������С����Լ���s����󳤶�Ϊ1000��
//
//ʾ�� 1:
//����:
//
//"bbbab"
//��� :
//
//	4
//	һ�����ܵ������������Ϊ "bbbb"��
//
//	ʾ�� 2 :
//	���� :
//
//	"cbbd"
//	��� :
//
//	2
//	һ�����ܵ������������Ϊ "bb"��
//
//	��Դ�����ۣ�LeetCode��
//	���ӣ�https ://leetcode-cn.com/problems/longest-palindromic-subsequence
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

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