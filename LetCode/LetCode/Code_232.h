#pragma once

#include "Define.h"

//232. ��ջʵ�ֶ���
//
//ʹ��ջʵ�ֶ��е����в�����
//
//push(x) --��һ��Ԫ�ط�����е�β����
//pop() --�Ӷ����ײ��Ƴ�Ԫ�ء�
//peek() --���ض����ײ���Ԫ�ء�
//empty() --���ض����Ƿ�Ϊ�ա�
//ʾ�� :
//
//MyQueue queue = new MyQueue();
//
//queue.push(1);
//queue.push(2);
//queue.peek();  // ���� 1
//queue.pop();   // ���� 1
//queue.empty(); // ���� false
//˵��:
//
//��ֻ��ʹ�ñ�׼��ջ���� -- Ҳ����ֻ�� push to top, peek / pop from top, size, �� is empty �����ǺϷ��ġ�
//����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
//�������в���������Ч�� �����磬һ���յĶ��в������ pop ���� peek ��������

class MyQueue {
private:
	stack<int> m_stack;
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		m_stack.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		stack<int> tempstack;

		while (m_stack.size() > 0)
		{
			tempstack.push(m_stack.top());
			m_stack.pop();
		}

		int ret = tempstack.top();
		tempstack.pop();

		while (tempstack.size() > 0)
		{
			m_stack.push(tempstack.top());
			tempstack.pop();
		}
		
		return ret;
	}

	/** Get the front element. */
	int peek() {
		stack<int> tempstack;

		while (m_stack.size() > 0)
		{
			tempstack.push(m_stack.top());
			m_stack.pop();
		}

		int ret = tempstack.top();

		while (tempstack.size() > 0)
		{
			m_stack.push(tempstack.top());
			tempstack.pop();
		}

		return ret;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return m_stack.size() == 0;
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

void test_232()
{
	MyQueue* obj = new MyQueue();
	obj->push(1);
	obj->push(2);
	int param_2 = obj->pop();
	int param_3 = obj->peek();
	bool param_4 = obj->empty();
}