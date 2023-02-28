#ifndef CHAPTER14_H_
#define CHAPTER14_H_

class Chapter14
{
private:
	;
public:
	void Run();
	void TestStack1();
	void TestStack2();
};




//定义类模板11.14
template <typename Type>
class Stack1
{
private:
	enum {MAX = 10};
	Type m_items[MAX];
	int m_top;
public:
	Stack1();
	bool IsEmpty();
	bool IsFull();
	bool Push(const Type& item);
	bool Pop(Type& item);
};
template <typename Type>
Stack1<Type>::Stack1()
{
	m_top = 0;
}
template <typename Type>
bool Stack1<Type>::IsEmpty()
{
	return 0 == m_top;
}
template <typename Type>
bool Stack1<Type>::IsFull()
{
	return MAX == m_top;
}
template <typename Type>
bool Stack1<Type>::Push(const Type& item)
{
	if (m_top < MAX)
	{
		m_items[m_top++] = item;
		return true;
	}
	else
	{
		return false;
	}
}
template <typename Type>
bool Stack1<Type>::Pop(Type& item)
{
	if (m_top > 0)
	{
		item = m_items[--m_top];
		return true;
	}
	else
	{
		return false;
	}
}


//深入探讨模板类14.15
template <typename Type>
class Stack2
{
private:
	enum { SIZE = 10 };
	int m_stackSize;
	Type* m_items;
	int m_top;
public:
	Stack2();
	explicit Stack2(int stackSize);
	Stack2(const Stack2<Type>& st);
	~Stack2();
	Stack2<Type>& operator=(const Stack2<Type>& st);
	bool IsEmpty();
	bool IsFull();
	bool Push(const Type& item);
	bool Pop(Type& item);
};

template <typename Type>
Stack2<Type>::Stack2()
{
	m_stackSize = SIZE;
	m_items = new Type[m_stackSize];
	m_top = 0;
}
template <typename Type>
Stack2<Type>::Stack2(int stackSize)
{
	m_stackSize = stackSize;
	m_items = new Type[m_stackSize];
	m_top = 0;
}
template <typename Type>
Stack2<Type>::Stack2(const Stack2<Type>& st)
{
	m_stackSize = st.m_stackSize;
	m_top = st.m_top;
	m_items = new Type[st.m_stackSize];
	for (int i = 0; i < m_top; i++)
	{
		m_items[i] = st.m_items[i];
	}
}
template <typename Type>
Stack2<Type>::~Stack2()
{
	delete[] m_items;
}
template <typename Type>
Stack2<Type>& Stack2<Type>::operator=(const Stack2<Type>& st)
{
	if (this == &st)
	{
		return *this;
	}
	delete[] m_items;
	m_stackSize = st.m_stackSize;
	m_top = st.m_top;
	m_items = new Type[st.m_stackSize];
	for (int i = 0; i < m_top; i++)
	{
		m_items[i] = st.m_items[i];
	}
	return *this;
}
template <typename Type>
bool Stack2<Type>::IsEmpty()
{
	return 0 == m_top;
}
template <typename Type>
bool Stack2<Type>::IsFull()
{
	return m_top == m_stackSize;
}
template <typename Type>
bool Stack2<Type>::Push(const Type& item)
{
	if (m_top < m_stackSize)
	{
		m_items[m_top++] = item;
		return true;
	}
	else
	{
		return false;
	}
	
}
template <typename Type>
bool Stack2<Type>::Pop(Type& item)
{
	if (m_top > 0)
	{
		item = m_items[--m_top];
		return true;
	}
	else
	{
		return false;
	}
}



















#endif
