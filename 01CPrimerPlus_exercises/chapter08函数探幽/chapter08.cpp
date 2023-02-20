/*
8.1 C++内联函数
	1.内联函数的运行比常规函数快，但代价是占用更多内存。一般对于函数定义占一行或两行的简单函数使用内联函数。
	2.内联函数定义与声明方式：
		在函数定义前加上关键字inline。
		在函数声明前加上关键字inline。
		通常的做法是省略原型，将整个定义放在本应提供原型的地方。
8.2 引用变量
	1.引用是已定义的变量的别名，一边用作函数形参。
	2.引用变量必须在声明时进行初始化。
	3.引用，临时变量，const变量，const函数
		如果不对变量进行修改，又想使用引用，应使用const。
		如果实参与引用参数（形参）不匹配，同时仅当参数为const引用是，C++会生成中间临时变量，将临时变量的值赋给引用参数，修改引用参数不改变实参的值。
		应尽可能使用const
			避免无意中修改数据的编程错误。
			使用const能处理const和非const实参，否则只能处理非const实参。
			使函数能够正确生成并使用临时变量。
		函数返回类型为引用时，一般用于返回传递给函数的引用变量。
		返回引用时，应避免返回函数终止时不在存在的内存单元。同样，也应避免返回指向临时变量的值的指针。为避免这种问题，一般返回作为参数传递给函数的引用，或者返回使用new分配的新的存储空间。
		函数返回类型为const时，是不可修改的左值。即	fun(a,b) = c; //not allowed
	4.String类定义了一种char *到String的转换功能，这使得可以使用C风格字符串初始化String对象。
	5.基类引用可以指向派生类对象，无需进行强制类型转换。
	6.何时使用引用参数
		使用引用的主要原因一般为
			需要修改调用函数中的数据对象（实参）
			提高程序运行速度
		什么时候使用引用
			不修改传递的值时：
				数据对象很小，按值传递（内置类型，小型结构）
				数组，使用const指针
				较大结构，使用const指针或const引用
				类对象，使用const引用。（传递对象参数的标准方式时按引用传递）
			修改传递的值时：
				内置类型，使用指针
				数组，使用指针
				结构，使用引用或指针
				对象，使用引用
		以上是一些指导原则，根据实际情况也可能有其他选择。
8.3 默认参数
8.4 函数重载
	1.函数重载时，重载哪个函数看的是函数参数列表，也称函数特征标。
	2.对于可以进行自动类型转换的参数，将调用最匹配的版本。
	3.仅当函数基本上执行相同的任务，但使用不同的数据类型时，推荐使用函数重载。
8.5 函数模板
	1.建立一个函数模板
		声明：
			template <typename AnyType> void Swap(AnyType &a, AnyType &b);
		定义：
			template <typename AnyType>
			void Swap(AnyType &a, AnyType &b)		//template <typename AnyType> void Swap(AnyType &a, AnyType &b)	一行也可以
			{
				AnyType temp;
				temp = a; a = b; b = temp;
			}
		说明：
			template 和 typename 是必须的，也可以使用class（C++98之前版本）替换typename，此外不能更改。AnyType是自定义名称，一般使用 T 简写。
			以上是函数定义，每一个函数定义和声明前面必须加上template <typename AnyType>指出这是函数模板。
		实际使用：
			int a = 2, b = 3;
			Swap(a, b);
	2.常见的情形是，将函数模板放在头文件中，并在需要使用模板的文件中包含头文件。 
	3.重载函数模板
		template <typename AnyType> void Swap(AnyType &a, AnyType &b, int n) {...}	//重载实例
		对于模板，通用类型可以有多个，具体类型可以有多个，如：
			template <typename T1, typename T2> void Add(T1 &a, T2 &b) {...}
	4.模板的局限性
		对于Swap()函数，当a, b为数组是，= 运算便得不到预期结果。
		有两种解决方案
			重载运算符。
			为特定类型提供具体化的模板定义。
	5.显式具体化
		显式具体化的原型：
			template <> void Swap<job>(job &a, job &b)	//job是可选的，因为函数参数类型表示这是job的一个具体化，template <> void Swap(job &a, job &b)，我觉得写上更清晰
		定义：
			template <> void Swap<job>(job &a, job &b) {...}
		对于给定的函数名，可以有非模板函数，模板函数，显式具体化模板函数以及它们的重载版本。
		调用优先级：非模板函数 > 显式具体化模板函数 > 模板函数
	6.实例化与具体化
		1)隐式实例化
			在代码中包含函数模板本身并不会生成函数定义，它只是一个用于生成函数定义的方案。
			但是调用函数必须有函数定义，当函数调用Swap(i, j)时，编译器根据模板生成特定类型的函数定义。也说生成Swap()的一个实例，这个实例使用int 类型（假设i,j为int）。
			模板并非函数定义，但使用int类型的实例是函数定义，这种实例化方式被称为隐式实例化。编译器之所以知道提供这种定义，是因为程序提供了int参数。
			总结：编译器根据函数模板自动生成的特定类型的函数定义即为隐式实例化。
		2)显式实例化
			声明语法：
				template void Swap<int>(int, int);	//这个声明的意思是，使用Swap()模板生成int类型的函数定义
			显示实例化与显示具体化的区别：
				显示具体化必须提供相应的模板定义，其声明的意思是，不要使用函数模板生成函数定义，而应使用显式具体化模板函数生成函数定义。
				显示实例化只需提供声明，让编译器按照声明类型使用模板函数生成特定类型的实例（定义）。
			警告：试图在同一个文件中使用同一种类型的显式实例化和显式具体化将出错。（没病一般不会提供两个）
		3)还可以在程序中使用函数来创建显示实例化
			代码：
				template <typename T> T Add(T a, T b) {return a + b;}	//按值传递
				int m = 1;
				double n = 3.0;
				cout << Add(m, n);		//error!
			说明：
				这里模板与函数参数调用不匹配，无法使用模板隐式实例化。
				但通过使用 Add<double>(m, n)可强制为double类型实例化，并将int类型参数强制转化为double类型。
			注意：
				如果参数传递类型为按引用传递，则不能进行强制类型转换，因为int型的应用变量无法指向double类型数据。
	7.函数调用使用哪个函数版本
		1)编译器决定：
			根据匹配规则自动选择最佳匹配的函数
		2)自己决定：	
			对于template <typename T> T Add(T a, T b); 和 int Add(int a, int b);
			Add(1, 2);	//调用Add函数
			Add(1.0, 2.0);	//call 模板函数
			Add<>(1, 2);	//call 模板函数
			Add<int>(1.0, 2.0);	//call 模板函数，显式实例化的强制转换
	8.函数模板发展中的一些问题及解决方案
		1）不确定函数中间值类型
			代码：
				template <typename T1, typename T2>
				void Add(T1 a, T2 b)
				{
					...
					?type? x = a + b;	//x的类型无法判断
					
				}
			说明：	
				新增关键字decltype
				decltype x = a + b;		//make x the same type as a + b
		2)不确定返回值的类型
			代码：
				template <typename T1, typename T2>
				?type? Add(T1 a, T2 b)
				{
					...
					return a + b;	//不确定返回值类型
					
				}
	
			说明：
				首先，不能将返回值类型设置为decltype(x+y)，因为此时还未声明参数x and y，他们不再作用域内，编译器看不到它们，也无法使用它们。
				新增后置返回类型语法->decltype
					template <typename T1, typename T2>
					auto Add(T1 a, T2 b) ->decltype
					{
						...
						return a + b;	//不确定返回值类型
					
					}
				此时auto是一个占位符，表示后置返回类型提供的类型，这是auto的新用法。
				现在decltype在参数生命后面，因此x and y位于作用域内，可以使用decltype。
*/
//--------------------------------------------------//
/*
6.编写模板函数MaxN(),它将由一个T类型元素组成的数组和一个表示数组元素数目的整数作为参数,并返回数组中最大的元素。在程序对它进行测试,该程序使用一个包含6个int元素的数组和一个包含4个double元素的数组来调用该函数。程序还包含一个具体化,它将char指针数组和数组中的指针数量作为参数,并返回最长的字符串的地址。如果有多个这样的字符串,则返回其中第一个字符串的地址。使用由5个字符串指针组成的数组来测试该具体化。
	所有输入都从文件input.txt中读取				//ShowMax()
*/
#include "chapter08.h"
#include <iostream>
#include <fstream>
//传递char指针数组不知道怎么搞
void Chapter08::ShowMax()
{
	int intArrSize, doubleArrSize;
	//int charPointerArrSize;
	std::ifstream fin;
	fin.open(".\\01CPrimerPlus_exercises\\chapter08函数探幽\\input.txt");	//open file
	if (!fin.is_open())
	{
		std::cout << "failed open!" << std::endl;
		exit(EXIT_FAILURE);
	}

	(fin >> intArrSize).get();				//get intArrSize
	int* intArr = new int[intArrSize];
	for (int i = 0; i < intArrSize; i++)
	{
		fin >> intArr[i];					//read file
	}
	fin.get();
	std::cout << "Max int: " << *(MaxN(intArr, intArrSize)) << std::endl;		//get max int value

	(fin >> doubleArrSize).get();		//get doubleArrSize
	double* doubleArr = new double[doubleArrSize];
	for (int i = 0; i < doubleArrSize; i++)
	{
		fin >> doubleArr[i];
	}
	fin.get();
	std::cout << "Max double: " << *(MaxN(doubleArr, doubleArrSize)) << std::endl;		//get max double value

	//(fin >> charPointerArrSize).get();
	//char (*charPointerArr)[20] = new char[charPointerArrSize][20];		//列为20的动态数组分配内存
	//for (int i = 0; i < doubleArrSize; i++)
	//{
	//	fin.getline(charPointerArr[i], 20);
	//}
	//std::cout << "Max string: " << MaxN<char>(*charPointerArr, charPointerArrSize) << std::endl;




	delete[] intArr;
	delete[] doubleArr;
	//delete[] charPointerArr[20];	//释放二维数组，好像也不对
	
	fin.close();
}
