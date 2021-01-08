#pragma once

#include "Define.h"

//��������
//Ӧ��������Ԫ�ص����򣬲�������Ĺ�����ʽ�����������һ���˿��ơ���ʼʱ�����ǵ�����Ϊ�ղ���
//�����ϵ����泯�£�Ȼ��ÿ�δ�����������һ���Ʋ��������뵽��������ȷ��λ�á�Ϊ���ҵ�һ���Ƶ�
//��ȷλ�ã����Ǵ��ҵ�����ΪҪ����ƶ�Ԫ�أ����Դ��ҵ��󷽱�һ�㣩�������������е�ÿһ���ƽ��бȽϡ�

//����
//�ռ临�Ӷȣ�O(N)
//ʱ�临�Ӷȣ�O(N^2 + N)
void InsertSort1(vector<int>& p)
{
	//���е���
	vector<int> h;
	//�����Ƶ�����
	int hs = 0;
	h.resize(p.size());

	//���ѭ���൱�������ϵ���
	for (int i = 0; i < p.size(); i++)
	{
		//������������һ����
		int value = p[i];

		//����û����ֱ�Ӳ���
		if (hs <= 0)
		{
			h[0] = value;
			hs++;
			continue;
		}

		int j = hs - 1;

		//���ҵ��������е���(0��i)���бȽ�
		for (; j >= 0; j --)
		{
			if (value > h[j])
			{
				break;
			}
			else
			{
				//��ǰԪ�ز������������� �����һ��
				h[j + 1] = h[j];
			}
		}

		h[j + 1] = value;
		hs++;
	}

	for (int i = 0; i < hs; i++)
	{
		p[i] = h[i];
	}
}

//����
//�ռ临�Ӷȣ�O(1)
//ʱ�临�Ӷȣ�O(N^2)
void InsertSort2(vector<int>& p)
{
	//���ѭ���൱�������ϵ���(Ĭ��������һ���ƣ���Ϊ���ñȽ�)
	for (int i = 1; i < p.size(); i++)
	{
		//������������һ����
		int value = p[i];

		//ָ�����е����ұߵ���
		int j = i - 1;

		//���ҵ��������е���(i - 1��0)���бȽ�
		for (; j >= 0; j--)
		{
			if (value > p[j])
			{
				//�ҵ�λ���� �˳�ȥ����
				break;
			}
			else
			{
				//��ǰԪ�ز������������� �����һ��
				p[j + 1] = p[j];
			}
		}

		p[j + 1] = value;
	}
}

//����
void InsertSort(vector<int>& p)
{
	for (int i = 1; i < p.size(); i++)
	{
		int value = p[i];

		int j = i - 1;

		for (; j >= 0; j--)
		{
			if (value < p[j])
				break;
			else
				p[j + 1] = p[j];
		}
		p[j + 1] = value;
	}
}

void test_InsertSort()
{
	vector<int> vec = { 10,5,15,3,7,18 };
	InsertSort(vec);
}