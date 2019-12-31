#pragma once

#include "Define.h"

//86. �ָ�����
//
//����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��
//
//��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�
//
//ʾ�� :
//
//����: head = 1->4->3->2->5->2, x = 3
//	��� : 1->2->2->4->3->5
ListNode* partition(ListNode* head, int x) {
	ListNode* pLeftNode = new ListNode(0);
	ListNode* pRightNode = new ListNode(0);
	ListNode* pCurLeft = pLeftNode;
	ListNode* pCurRight = pRightNode;

	ListNode* pTemp = head;

	while (pTemp)
	{
		if (pTemp->val < x)
		{
			pCurLeft->next = pTemp;
			pCurLeft = pCurLeft->next;
		}
		else
		{
			pCurRight->next = pTemp;
			pCurRight = pCurRight->next;
		}

		pTemp = pTemp->next;
	}

	pCurRight->next = nullptr;
	pCurLeft->next = pRightNode->next;

	pCurLeft = pLeftNode->next;

	delete pLeftNode;
	delete pRightNode;

	return pCurLeft;
}