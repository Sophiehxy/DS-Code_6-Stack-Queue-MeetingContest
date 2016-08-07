//��Ŀ������ջʵ��һ������
//˼·��������ջ�ֱ���sin,sout���������ʱ������ѹ��sin��
//����Ҫ������ʱ�����ж�sout�Ƿ�Ϊ�գ���Ϊ�գ���sin���е�����push��sout�У�Ȼ��pop
//								      ��sout��Ϊ��ʱ��ֱ�ӽ�sout�е�top������pop�ͺ�

#pragma once

template<class T>
class Stack
{
public:
	Stack()
		:_array(NULL)
		, _size(0)
		, _capacity(0)
	{}
	~Stack()
	{
		if (_array)
		{
			delete[] _array;
		}
		_size = 0;
		_capacity = 0;
	}

	void _CheckCapacity()
	{
		if (_size >= _capacity)
		{
			_capacity = 2 * _capacity + 3;
			T* tmp = new T[_capacity];
			for (int i = 0; i < _size; ++i)
			{
				tmp[i] = _array[i];
			}
			delete[] _array;
			_array = tmp;
		}
	}

	void Push(const T& x)
	{
		_CheckCapacity();
		_array[_size++] = x;
	}

	T& Pop()
	{
		/*if (_array)
		{
			cout << "The Stack is Empty.So that you can not pop any data." << endl;
			delete[] _array;
			_array = NULL;
		}*/
		assert(_array);
		return _array[--_size];
	}

	size_t Size()
	{
		//cout << "The size of the stack is " << _size << " ." << endl;
		return _size;
	}
	bool Empty()
	{
		if (_size <= 0 || _array==NULL)
		{
			//cout << "EMPTY" << endl;
			return true;
		}

		else
		{
			//cout << "NOT EMPTY" << endl;
			return false;
		}

	}
	const T& Top()
	{
		if (_size <= 0)
		{
			//cout << "The Stack is Empty.There's no data in stack." << endl;
			return 0;

		}
		else
		{
			//cout << "The top of stack is " << _array[_size - 1] << " ." << endl;
			return _array[_size - 1];
		}
	}

	void Print()
	{
		if (_size <= 0)
		{
			cout << "This stack is empty." << endl;
		}
		else
		{
			for (int i = _size - 1; i >= 0; --i)
			{
				cout << _array[i] << "  ";
			}
			cout << endl;
		}
		
	}
protected:
	T* _array;
	size_t _size;
	size_t _capacity;

};


template<class T>
class Queue
{
public:
	Queue()
	{}
	Queue(Stack<T>* s1, Stack<T>* s2)
		:sin(s1)
		,sout(s2)
	{}
	~Queue()
	{}
public:
	void inQueue(const T& x)
	{
		sin.Push(x);
	}

	void outQueue()
	{
		if (sin.Empty() && sout.Empty())//sin,sout��Ϊ��
		{
			cout << "no data." << endl;
			return;
		}
		else if (sout.Empty()&&!sin.Empty())//soutΪ�գ�sin��Ϊ��
		{
			while (!sin.Empty())
			{
				T tmp = sin.Pop();//��ʱ��sin�Ѿ�ִ����pop
				sout.Push(tmp);
			}
			sout.Pop();
						
		}
		else if (!sout.Empty())//sout��Ϊ��
		{
			sout.Pop();
		}
	}

	T& Front()
	{
		if (sout.Empty())
		{
			while (!sin.Empty())
			{
				T tmp = sin.Pop();//��ʱ��sin�Ѿ�ִ����pop
				sout.Push(tmp);
			}
		}
		T ret = sout.Top();
		cout << "front is " << ret << endl;
		return ret;
	}

	size_t Size()
	{
		if (sout.Empty())
		{
			while (!sin.Empty())
			{
				T tmp = sin.Pop();//��ʱ��sin�Ѿ�ִ����pop
				sout.Push(tmp);
			}
		}
		cout << "Size:" << sout.Size() << endl;
		return sout.Size();
	}

	void QPrint()
	{
		sin.Print();
		sout.Print();
	}
private:
	Stack<T> sin;//����ջ
	Stack<T> sout;//���ջ
};

void STQueueTest()
{
	Queue<int> q;
	q.inQueue(1);
	q.inQueue(2);
	q.inQueue(3);
	q.inQueue(4);
	q.inQueue(5);
	//q.QPrint();
	q.Size();
	cout << endl;

	q.outQueue();
	q.Front();
	//q.QPrint();
	
	q.outQueue();
	q.Front();
	//q.QPrint(); 
	
	q.outQueue();
	q.Front();
	//q.QPrint();
	
	q.outQueue();
	q.Front();
	//q.QPrint();
	
	q.outQueue();
	q.Front();
	//q.QPrint();
	q.Size();

}