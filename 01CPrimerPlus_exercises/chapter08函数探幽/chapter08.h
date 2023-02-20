#ifndef CHAPTER08_H_
#define CHAPTER08_H_
#include <iostream>
#include <cstring>

template <typename T>
T * MaxN(T * arr, const int SIZE)
{
	T * max = &arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (*max < arr[i])
		{
			max = &arr[i];
		}
	}
	return max;
}
//template <> char * MaxN<char>(char* arr, const int SIZE)
//{
//	return arr + 1;
//}

class Chapter08
{
private:
	;
public:
	void ShowMax();
};



#endif