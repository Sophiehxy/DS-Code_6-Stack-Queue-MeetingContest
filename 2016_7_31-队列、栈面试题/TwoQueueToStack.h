//��Ŀ����������ʵ��һ��ջ
//˼·�����������зֱ���q1,q2��
//1������ѹջʱ����a�����Ȳ鿴q1,q2��һ��Ϊ�գ�����������Ϊ�ա�
//			   ��b��qi��q2��Ϊ�գ����������һ�����У�����ѡ��q1��
//			   ��c��q1Ϊ��q2��Ϊ��ʱ���������뵽q2��
//			   ��d��q1��Ϊ��q2Ϊ��ʱ���������뵽q1��
//2������ջʱ�������յĶ����е���������ѹ������һ��Ϊ�յĶ��У�ֱ��ֻʣһ�����ݣ�Ȼ�󽫸�����pop����

#pragma once
#include<queue>
template<class T>
struct QueueNode
{
	T _data;
	QueueNode<T>* _next;
	QueueNode(const T& x)
		:_data(x)
		, _next(NULL)
	{}
};

template<class T>
class Queue
{
protected:
	QueueNode<T>* _head;
	QueueNode<T>* _tail;
public:
	Queue()
		:_head(NULL)
		, _tail(NULL)
	{}

	~Queue()
	{
		QueueNode<T>* begin = _head;
		while (begin)
		{
			QueueNode<T>* del = begin;
			begin = begin->_next;
			delete del;
		}
		_tail = _head = NULL;
	}

public:
	void Push(const T& x)
	{
		if (_head == NULL)
		{
			_head = _tail = new QueueNode<T>(x);
		}
		else
		{
			_tail->_next = new QueueNode<T>(x);
			_tail = _tail->_next;
		}
	}

	T& Pop()
	{
		assert(_head);
		if (_head == _tail)//ֻ��һ������
		{
			delete _head;
			_head = _tail = NULL;
		}
		else
		{
			QueueNode<T>* del = _head;
			_head = _head->_next;
			delete del;
			return _head->_data;
		}
	}

	size_t Size()
	{
		int size = 0;
		QueueNode<T>* pHead = _head;
		while (pHead)
		{
			++size;
			pHead = pHead->_next;
		}
		//cout << "The size of queue is " << size << " ." << endl;
		return size;
	}

	T& Front()
	{
		//cout << "The front of the queue is :" << _head->_data << endl;
		return _head->_data;
	}

	T& Back()
	{
		//cout << "The back of the queue is :" << _tail->_data << endl;
		return _tail->_data;
	}

	bool Empty()
	{
		if (_head == NULL)
		{
			//cout << "It's empty." << endl;
			return true;
		}
		else
		{
			//cout << "It's not empty." << endl;
			return false;
		}
	}
};


template<class T>
class Stack
{
public:
	Stack()
	{}
	~Stack()
	{}

public:
	void inStack(const T& x)
	{
		if (!q1.Empty())
		{
			q1.Push(x);
		}
		else if (!q2.Empty())
		{
			q2.Push(x);
		}
		else if (q1.Empty() && q2.Empty())
		{
			q1.Push(x);
		}
	}

	void outStack()
	{
		if (q1.Empty() && q2.Empty())
		{
			cout << "no data." << endl;
			return;
		}
		else if (!q1.Empty() && q2.Empty())
		{
			while (!q1.Empty() && q1.Front() != q1.Back())
			{
				T ret = q1.Front();
				q1.Pop();
				q2.Push(ret);
			}
			q1.Pop();
		}
		else if (q1.Empty() && !q2.Empty())
		{
			while (!q2.Empty() && q2.Front() != q2.Back())
			{
				T ret = q2.Front();
				q2.Pop();
				q1.Push(ret);
			}
			q2.Pop();
		}
	}

	size_t Size()
	{
		size_t size = q1.Size() | q2.Size();
		cout << "Size:" << size << endl;
		return size;
	}

	T Top()
	{
		T ret;
		if (q1.Empty() && q2.Empty())
		{
			cout << "no data." << endl;
			return -9;
		}
		else if (q1.Empty())
		{
			ret = q2.Back();
		}
		else if (q2.Empty())
		{
			ret = q1.Back();
		}
		
		cout << "Top:" << ret << endl;
		return ret;
	}
protected:
	Queue<T> q1;
	Queue<T> q2;
};
void QuStackTest()
{
	Stack<int> s;
	s.inStack(1);
	s.inStack(2);
	s.inStack(3);
	s.inStack(4);
	s.Size();
	s.Top();

	s.outStack();
	s.Top();
	s.outStack();
	s.Top();
	s.outStack();
	s.Top();
	s.outStack();
	s.Top();
	/*s.outStack();
	s.Top();
	s.Size();*/

}
