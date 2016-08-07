//题目：实现一个栈，要求实现Push(入栈)、Pop(出栈)、Min(返回最小值的操作)的时间复杂度为O(1)
//思路：该栈的成员为两个栈，一个正常出栈入栈称为正常栈，另一个为最小栈，用来找到数据中的最小值
//入栈时，如果最小栈没有数据，就把该数据同时入到正常栈和最小栈，若最小栈有数据，则比较现在要入栈的数据与最小栈中栈顶的数据，
//若最小栈中的数据小，就不动最小栈，只进行正常入栈；若最小栈的栈顶数据大于要入栈的值，就将该数据同时入到正常栈和最小栈。
//出栈时，当要出栈的数据与最小栈的栈顶数据一样时，就把正常栈和最小栈同时都pop，这时，最小值改变为现在最小栈的栈顶数据值


#pragma once
#include<stack>
template <class T>
class Stack
{
public:
	void Push(const T& x)
	{
		if (_minStack.empty())//最小栈为空,正常栈、最小栈都进行push操作
		{
			_stack.push(x);
			_minStack.push(x);
		}
		else	//最小栈不为空,需比较最小栈栈顶数据与要入栈的数据大小
		{
			//情况1，最小栈栈顶数据小，则只进行正常栈入栈操作
			if (_minStack.top() < x)
			{
				_stack.push(x);
			}

			//情况2，最小栈栈顶数据大，则正常栈，最小栈都进行入栈操作
			else if (_minStack.top() >= x)
			{
				_stack.push(x);
				_minStack.push(x);
			}
		}
	}

	void Pop()
	{
		if (_stack.empty())//栈为空，无数据，直接返回
		{
			cout << "empty." << endl;
			return;
		}
		else	//栈不为空,出栈需比较最小栈栈顶数据与要出栈的数据(正常栈的栈顶数据)是否相等
		{
			//情况1，不相等，则只进行正常栈出栈操作
			if (_minStack.top() != _stack.top())
			{
				_stack.pop();
			}

			//情况2，相等，则正常栈，最小栈都进行出栈操作,此时最小值为最小栈新的栈顶数据值
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