#pragma once

#include "Define.h"

//492. �������
//
//��Ϊһλweb�����ߣ� ��������ȥ�滮һ��ҳ��ĳߴ��Ǻ���Ҫ�ġ� �ָ���һ������ľ���ҳ�������������������һ������Ϊ L �Ϳ��Ϊ W ����������Ҫ��ľ��ε�ҳ�档Ҫ��
//
//1. ����Ƶľ���ҳ�������ڸ�����Ŀ�������
//
//2. ��� W ��Ӧ���ڳ��� L������֮��Ҫ�� L >= W ��
//
//3. ���� L �Ϳ�� W ֮��Ĳ��Ӧ��������С��
//����Ҫ��˳���������Ƶ�ҳ��ĳ��� L �Ϳ�� W��
//
//ʾ����
//
//���� : 4
//	��� : [2, 2]
//	���� : Ŀ������� 4�� ���п��ܵĹ��췽����[1, 4], [2, 2], [4, 1]��
//	���Ǹ���Ҫ��2��[1, 4] ������Ҫ��; ����Ҫ��3��[2, 2] ��[4, 1] ���ܷ���Ҫ��.����������� L Ϊ 2�� ��� W Ϊ 2��
//	˵�� :
//
//��������������� 10, 000, 000 ��Ϊ��������
//����Ƶ�ҳ��ĳ��ȺͿ�ȱ��붼����������

vector<int> constructRectangle2(int area) {

	int index = 0;
	vector< vector<int> > vec;

	for (int i = area; i >= 1; i--)
	{
		int temp = area / i;

		if (temp > i && vec.size() > 0)
		{
			break;
		}

		if (area % i == 0)
		{
			vector<int> v = { i, temp };
			vec.push_back(v);
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[index][0] - vec[index][1] > vec[i][0] - vec[i][1])
		{
			index = i;
		}
	}

	return vec[index];
}

vector<int> constructRectangle(int area) {

	int w = sqrt(area);

	while (area % w != 0)
		w--;

	return { area / w, w };
}