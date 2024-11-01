#pragma once

//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
//示例：
//
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807

#include "Define.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* pHeadNode = nullptr;
	ListNode* pCurNode = nullptr;

	bool isJin = false;

	while (l1 || l2 || isJin)
	{
		int sum = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + (isJin ? 1 : 0);

		isJin = sum >= 10;

		ListNode* pTempNode = new ListNode(sum % 10);

		if (pHeadNode == nullptr)
		{
			pHeadNode = pTempNode;
			pCurNode = pTempNode;
		}
		else
		{
			pCurNode->next = pTempNode;
			pCurNode = pCurNode->next;
		}

		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
	}

	return pHeadNode;
}