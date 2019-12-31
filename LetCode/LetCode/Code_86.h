#pragma once

#include "Define.h"

//86. 分隔链表
//
//给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
//
//你应当保留两个分区中每个节点的初始相对位置。
//
//示例 :
//
//输入: head = 1->4->3->2->5->2, x = 3
//	输出 : 1->2->2->4->3->5
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