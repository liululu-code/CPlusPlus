/*
7.1 复习函数的基本知识
7.2 函数参数和按值传递
7.3 函数和数组
	1.const与指针：
		int val = 1;	//变量
		const int CONSTANT = 2;		//常量
		int * pVal1 = &val;	//valid，可用指针修改变量，*pVal1的值为int型
		//int * pConstant1 = &CONSTANT;	//invalid，错误
		const int * pVal2 = &val;		//valid，不能用指针修改变量，*pVal2的值为const int型，但是可以修改pVal2的指向，即可以 pVal2 = &constant;
		int * const PVAL_3 = &val;		//valid，可用指针修改变量，但不能修改指针指向
		const int *pConstant2 = &CONSTANT;	//valid，不能用指针修改（毫无疑问），
		const int * const P_CONSTANT_3 = &CONSTANT;	//valid，不能用指针修改变量，不能修改指针指向
	2.要尽可能使用const
		可以避免由于无意间修改数据而导致的编程错误。
		使用const使得函数能够处理const和非const实参，否则将只能接受非const实参。如果条件允许，应将指针形参声明为指向const的指针。
7.4 函数和二维数组
	1.数组指针，指针数组，二维数组作为函数参数传递
		int data[3][4] = {...};
		int total = Sum(data, 3);	//函数参数该如何定义呢
			//data应是一个指针，指向有4个int型变量的数组
			int Sum(int (*arr)[4], int row);	//数组指针，指针指向有4个int型变量的数组
				//int *arr[4];		//指针数组，这个数组的成员是4个指向int型变量的指针
			int Sum(int arr[][4], int row);		//另一种定义方式，可读性更强，更简单
7.5 函数和C-风格字符串
	1.处理字符串中字符的标准方式
		while (*str)
		{
			statements;
			str++;
		}
	2.返回C风格字符串的函数：char * ReturnCStyle(...){...};
7.6 函数和结构
7.7 函数和string对象
7.8 函数和array对象
	1.array对象在函数中的传递
		std::array<double, 4> expenses;	//声明array对象
		Show(expenses);	//如何定义函数呢？
			void Show(std::array<double, 4> da);	//按值传递
			void Show(std::array<double, 4> * pDa);	//按指针传递
				cin >> (*pDa)[1];	//按指针传递时，引用方式与数组有所不同
7.9 递归
7.10 函数指针
	1.基础知识
		函数名即为函数地址
		double (*pf)(int); //pf即为函数指针
	2.使用函数指针传递，调用函数
		double Pam(int);	//fuction
		double (*PFun)(int);	//function pointer
		PFun = Pam;
		Pam(4); //等价于 (*PFun)(4);	等价于PFun(4);
		void Estimate(int lines, double (*PFun)(int));	//使用：Estimate(4, Pam);	//直接传递函数名就可以
	3.深入探讨函数指针
		const double * Fun1(const double arr[], int n);
		const double * Fun2(const double [], int);
		const double * Fun3(const double *, int);
		
		const double * (*PFun1)(const double *, int) = Fun1;	//声明指向函数的指针并初始化为Fun1，或auto PFun1 = Fun1;
		//auto PFun2 = Fun2;	//自动类型推断
		const double * (*PArr[3])(const double *, int) = { Fun1, Fun2, Fun3 };		//声明拥有三个指向函数的指针的指针数组
	4.使用typedef简化
		typedef const double * (*PFun)(const double *, int); //PFun now a type name
		PFun P1 = Fun1;	//P1 points to the Fun1() function
*/
//--------------------------------------------------//
/*
10.设计一个名为calculate()的函数,它接受两个double值和一个指向函数的指针,而被指向的函数接受两个double参数,并返回一个doublke值。calculate()函数的类型也是doublc,并返回被指向的函数使用calculate()的两个double参数计算得到的值。例如,假设add()函数的定义如下: 
		double add(double x,double y)
		{
			return x + y; 
		}
	则下述代码中的函数调用将导致calculate()把25和104传递给add()函数,并返回add()的返回值(12.9): 
		double q = calculate(2.5, 10.4, add); 
	请编写一个程序,它调用上述两个函数和至少另一个与add()类似的函数。该程序使用循环来让用户成对地输入数字。对于每对数字,程序都使用calculaie()来调用add()和至少一个其他的函数。如果读者爱曾险,可以尝试创建一个指针数组,其中的指针指向add()样式的函数,并编写一个循环,使用这些指针连续让calculate()调用这些函数。提示:下面是声明这种指针数组的方式,其中包含三个指针: 
		double (tpf[3])(double, double); 
	可以采用数组初始化语法,并将函数名作为地址来初始化这样的数组。

*/
#include <iostream>
#include "chapter07.h"
//本章代码运行失败，并非代码错误，只是传递函数的指针无法在类中使用，或者说我不会，在main()函数中运行正常
double Chapter07::Add(double x, double y)
{
	return x + y;
}
double Chapter07::Calculate(double x, double y, double (*PFun)(double, double))
{
	std::cout << (*PFun)(x, y);
	return (*PFun)(x, y);
}
double Chapter07::Mycalculate(double x, double y)
{
	//double (*PFun)(double, double);
	//PFun = Add;		//error!  将函数指针指向类成员函数好像不行，在main()函数中测试没有问题
	//return Calculate(x, y, PFun);
	return 1.0;	//函数必须返回一个值
}