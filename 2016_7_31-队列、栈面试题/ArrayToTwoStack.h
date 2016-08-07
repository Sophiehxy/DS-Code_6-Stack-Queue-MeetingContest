//��Ŀ����һ������ʵ������ջ
//˼·������������˷ֱ�������ջ��ջ�ף�����һ��flag����flag=1����ʾ������ߵ�ջ����flag=2����ʾ�����ұߵ�ջ
//����_top1,_top2���ֱ�Ϊ����ջ��ջ��ָ�룬�����Ϳ��������֪������վ�ķ�Χ��С��
//��ջʱ��ע���ж������Ƿ������������ˣ��򷵻أ���������flag��ֵ������Ӧջ����ʱע����ߵ�ջ��_top++;�ұߵ�ջʱ_top2--
//��ջʱ��ע����ջ�Ƿ�Ϊ�ա�����Ϊ��ʱ��ֱ���޸�_top1,_top2��ֵ��������ɳ�ջ����



#pragma once
template <class T, size_t _size>
class Array
{
public:
	Array()
		:_top1(0)//_top1��ʾ��ʱ��ǰλ�õ���һ�����±�
		, _top2(_size)//_top2��ʾ��ʱ��ǰλ�õ��±ֻ꣬�������ſ��Ա�֤�������������еĿ���λ�ã�Ҳ�����ټ������λ��
	{
		_array = new T[_size];
		memset(_array, 0, _size);
	}

	~Array()
	{
		if (_array)
		{
			delete[] _array;
		}
	}

public:
	void Push(int flag, const T& x)
	{
		if (_top1 >= _top2)
		{
			cout << "full." << endl;
		}
		else
		{
			if (flag == 1)
			{
				_array[_top1++] = x;
			}
			else if (flag == 2)
			{
				_array[--_top2] = x;
			}

			else
				return;
		}
	}
	void Pop(int flag)
	{
		if (_top1 <= 0 && _top2 >= _size)//����Ϊ�գ��������߶�û������
		{
			cout << "both empty" << endl;
			return;
		}
		else if (_top1 <= 0)//�������Ϊ�գ��ұ߲�Ϊ��
		{
			if (flag == 1)//ѡ��Pop��ߵ�ջ
			{
				cout << "a1 empty" << endl;
				return;
			}
			else if (flag == 2)//ѡ��Pop�ұߵ�ջ
			{
				_top2++;
				return;
			}
		}
		else if (_top2 >= _size)//�����ұ�Ϊ�գ���߲�Ϊ��
		{
			if (flag == 1)
			{
				_top1--;
				return;
			}
			else if (flag == 2)
			{
				cout << "a2 empty" << endl;
				return;
			}
		}
		else		//�����������߾������ݣ�����ִ��pop����
		{
			if (flag == 1)
			{
				_top1--;
				return;
			}
			else if (flag == 2)//ѡ��Pop�ұߵ�ջ
			{
				_top2++;
				return;
			}
		}
	}
	void Print()
	{
		cout << "Stack1: ";
		for (int i = 0; i < _top1; ++i)
		{
			cout << _array[i] << " ";
		}
		cout << endl;
		cout << "Stack1: ";
		for (int i = _size-1; i >=_top2; --i)
		{
			cout << _array[i] << " ";
		}
		cout << endl;
	}
private:
	T* _array;
	T _top1;
	T _top2;
};


void ArStackTest()
{
	Array<int,10> a;
	a.Push(1, 1);
	a.Push(1, 2);
	a.Push(1, 3);
	a.Push(1, 4);
	a.Push(1, 5);
	a.Push(1, 6);
	a.Push(1, 7);
	a.Push(2, 9);
	a.Push(2, 8);
	a.Push(2, 7);
	a.Push(2, 11);
	a.Push(2, 22);
	a.Push(2, 33);
	a.Print();

	a.Pop(1);
	a.Print();
	a.Pop(2);
	a.Print();

}