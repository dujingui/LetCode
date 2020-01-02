#pragma once

#include "Define.h"

//345. ��ת�ַ����е�Ԫ����ĸ

//��дһ�����������ַ�����Ϊ���룬��ת���ַ����е�Ԫ����ĸ��
//
//ʾ�� 1:
//
//����: "hello"
//	��� : "holle"
//	ʾ�� 2 :
//
//	���� : "leetcode"
//	��� : "leotcede"
//	˵�� :
//	Ԫ����ĸ��������ĸ"y"��
//
//	��Դ�����ۣ�LeetCode��
//	���ӣ�https ://leetcode-cn.com/problems/reverse-vowels-of-a-string
//	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

bool isVowel(char& c) {
	bool isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	bool isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

	return isLowercaseVowel || isUppercaseVowel;
}

string reverseVowels2(string s) {
	int head = 0, tail = s.length() - 1;

	char* pRet = new char[s.length() + 1]();

	while (head <= tail)
	{
		if (isVowel(s[head]) && isVowel(s[tail]))
		{
			pRet[head] = s[tail];
			pRet[tail] = s[head];

			head++;
			tail--;
		}
		else
		{
			if (!isVowel(s[head]))
			{
				pRet[head] = s[head];
				head++;
			}

			if (!isVowel(s[tail]))
			{
				pRet[tail] = s[tail];
				tail--;
			}
		}
	}

	string ret(pRet);

	delete[] pRet;

	return ret;
}

string reverseVowels(string s) {
	set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
	set<char>::iterator iterend = vowels.end();

	int head = 0, tail = s.length() - 1;

	char* pRet = new char[s.length() + 1]();

	while (head <= tail)
	{
		if ( (vowels.find(s[head]) != iterend) && (vowels.find(s[tail]) != iterend) )
		{
			pRet[head] = s[tail];
			pRet[tail] = s[head];

			head++;
			tail--;
		}
		else
		{
			if (vowels.find(s[head]) == iterend)
			{
				pRet[head] = s[head];
				head++;
			}

			if (vowels.find(s[tail]) == iterend)
			{
				pRet[tail] = s[tail];
				tail--;
			}
		}
	}

	string ret(pRet);

	delete[] pRet;

	return ret;
}