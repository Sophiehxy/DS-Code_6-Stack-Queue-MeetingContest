//题目：用一个数组实现两个栈
//思路：以数组的两端分别作两个栈的栈底，设置一个flag，当flag=1，表示操作左边的栈，当flag=2，表示操作右边的栈
//设置_top1,_top2，分别为左右栈的栈顶指针，这样就可以清楚地知道两个站的范围大小了
//入栈时，注意判断数组是否已满，若满了，则返回，不满，则按flag的值操作对应栈，此时注意左边的栈是_top++;右边的栈时_top2--
//出栈时，注意两栈是否为空。当不为空时，直接修改_top1,_top2的值，即可完成出栈操作



#pragma once
template <class T, size_t _size>
class Array
{
public:
	Array()
		:_top1(0)//_top1表示的时当前位置的下一个的下标
		, _top2(_size)//_top2表示的时当前位置的下标，只有这样才可以保证不会多计算数组中的空余位置，也不会少计算空余位置
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
		if (_top1 <= 0 && _top2 >= _size)//数组为空，左右两边都没有数据
		{
			cout << "both empty" << endl;
			return;
		}
		else if (_top1 <= 0)//数组左边为空，右边不为空
		{
			if (flag == 1)//选择Pop左边的栈
			{
				cout << "a1 empty" << endl;
				return;
			}
			else if (flag == 2)//选择Pop右边的栈
			{
				_top2++;
				return;
			}
		}
		else if (_top2 >= _size)//数组右边为空，左边不为空
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
		else		//数组左右两边均有数据，都可执行pop操作
		{
			if (flag == 1)
			{
				_top1--;
				return;
			}
			else if (flag == 2)//选择Pop右边的栈
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