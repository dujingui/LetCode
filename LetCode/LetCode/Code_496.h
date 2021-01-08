#pragma once

#include "Define.h"


//496. ��һ������Ԫ�� I
//
//��������û���ظ�Ԫ�ص����� nums1 �� nums2 ������nums1 �� nums2 ���Ӽ����ҵ� nums1 ��ÿ��Ԫ���� nums2 �е���һ��������ֵ��
//
//nums1 ������ x ����һ������Ԫ����ָ x �� nums2 �ж�Ӧλ�õ��ұߵĵ�һ���� x ���Ԫ�ء���������ڣ���Ӧλ����� - 1��
//
//ʾ�� 1:
//
//����: nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2].
//	��� : [-1, 3, -1]
//	���� :
//	����num1�е�����4�����޷��ڵڶ����������ҵ���һ����������֣������� - 1��
//	����num1�е�����1���ڶ�������������1�ұߵ���һ���ϴ������� 3��
//	����num1�е�����2���ڶ���������û����һ����������֣������� - 1��
//	ʾ�� 2 :
//
//	���� : nums1 = [2, 4], nums2 = [1, 2, 3, 4].
//	��� : [3, -1]
//	���� :
//	����num1�е�����2���ڶ��������е���һ���ϴ�������3��
//	����num1�е�����4���ڶ���������û����һ����������֣������� - 1��
//	ע�� :
//
//	nums1��nums2������Ԫ����Ψһ�ġ�
//		nums1��nums2 �������С��������1000��

vector<int> nextGreaterElement2(vector<int>& nums1, vector<int>& nums2) {
	vector<int> ret;

	for (int i = 0; i < nums1.size(); i++)
	{
		int j = 0;

		for (j = 0; j < nums2.size(); j++)
		{
			if (nums2[j] == nums1[i])
			{
				break;
			}
		}

		for (j = j + 1; j < nums2.size(); j++)
		{
			if (nums2[j] > nums1[i])
			{
				break;
			}
		}

		ret.push_back(j < nums2.size() ? nums2[j] : -1);
	}

	return ret;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	vector<int> ret;

	map<int, int> map;
	stack<int> stack;

	for (int i = 0; i < nums2.size(); i++)
	{
		while (stack.size() > 0 && nums2[i] > stack.top())
		{
			map[stack.top()] = nums2[i];
			stack.pop();
		}

		stack.push(nums2[i]);
	}

	while (stack.size() > 0)
	{
		map[stack.top()] = -1;
		stack.pop();
	}

	for (int i = 0; i < nums1.size(); i++)
	{
		ret.push_back(map[nums1[i]]);
	}

	return ret;
}

void test_496()
{
	std::vector<int> num1 = { 4,1,2 };
	std::vector<int> num2 = { 1,3,4,2 };
	std::vector<int> ret = nextGreaterElement(num1, num2);
}