#pragma once

#include "Define.h"

//345. 反转字符串中的元音字母

//编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
//
//示例 1:
//
//输入: "hello"
//	输出 : "holle"
//	示例 2 :
//
//	输入 : "leetcode"
//	输出 : "leotcede"
//	说明 :
//	元音字母不包含字母"y"。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/reverse-vowels-of-a-string
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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