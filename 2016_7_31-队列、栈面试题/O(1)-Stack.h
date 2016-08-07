//��Ŀ��ʵ��һ��ջ��Ҫ��ʵ��Push(��ջ)��Pop(��ջ)��Min(������Сֵ�Ĳ���)��ʱ�临�Ӷ�ΪO(1)
//˼·����ջ�ĳ�ԱΪ����ջ��һ��������ջ��ջ��Ϊ����ջ����һ��Ϊ��Сջ�������ҵ������е���Сֵ
//��ջʱ�������Сջû�����ݣ��ͰѸ�����ͬʱ�뵽����ջ����Сջ������Сջ�����ݣ���Ƚ�����Ҫ��ջ����������Сջ��ջ�������ݣ�
//����Сջ�е�����С���Ͳ�����Сջ��ֻ����������ջ������Сջ��ջ�����ݴ���Ҫ��ջ��ֵ���ͽ�������ͬʱ�뵽����ջ����Сջ��
//��ջʱ����Ҫ��ջ����������Сջ��ջ������һ��ʱ���Ͱ�����ջ����Сջͬʱ��pop����ʱ����Сֵ�ı�Ϊ������Сջ��ջ������ֵ


#pragma once
#include<stack>
template <class T>
class Stack
{
public:
	void Push(const T& x)
	{
		if (_minStack.empty())//��СջΪ��,����ջ����Сջ������push����
		{
			_stack.push(x);
			_minStack.push(x);
		}
		else	//��Сջ��Ϊ��,��Ƚ���Сջջ��������Ҫ��ջ�����ݴ�С
		{
			//���1����Сջջ������С����ֻ��������ջ��ջ����
			if (_minStack.top() < x)
			{
				_stack.push(x);
			}

			//���2����Сջջ�����ݴ�������ջ����Сջ��������ջ����
			else if (_minStack.top() >= x)
			{
				_stack.push(x);
				_minStack.push(x);
			}
		}
	}

	void Pop()
	{
		if (_stack.empty())//ջΪ�գ������ݣ�ֱ�ӷ���
		{
			cout << "empty." << endl;
			return;
		}
		else	//ջ��Ϊ��,��ջ��Ƚ���Сջջ��������Ҫ��ջ������(����ջ��ջ������)�Ƿ����
		{
			//���1������ȣ���ֻ��������ջ��ջ����
			if (_minStack.top() != _stack.top())
			{
				_stack.pop();
			}

			//���2����ȣ�������ջ����Сջ�����г�ջ����,��ʱ��СֵΪ��Сջ�µ�ջ������ֵ
			else if (_minStack.top() == _stack.top())
			{
				_stack.pop();
				_minStack.pop();
			}
		}
	}

	T& Min()
	{
		cout << "min:" << _minStack.top() << endl;
		return _minStack.top();
	}
private:
	stack<T> _stack;
	stack<T> _minStack;
};

void StackTest()
{
	Stack<int> s;
	s.Push(5);
	s.Min();
	s.Push(3);
	s.Push(2);
	s.Min();

	s.Push(4);
	s.Min();
	s.Push(1);
	s.Min();

	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
}