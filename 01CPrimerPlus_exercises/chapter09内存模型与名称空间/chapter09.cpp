/*I
9.1 单独编译
	1.常放在头文件中的内容
		函数原型
		使用#deifne or const定义的符号常量
		结构声明
		类声明
		模板声明
		内联函数
		警告：在IDE中，不要将头文件加入到项目列表中，也不要再源代码文件中使用#include来包含其他源代码文件。（这里的项目列表可能指编译时的文件列表，头文件由#include管理，不需要单独编译。IDEA中一般自动处理好了，像vs2019中解决方案中虽然有头文件，但是编译时不编译头文件，仅仅只是在解决方案面板中显示头文件，方便修改）
	2.头文件预处理指令
		代码：
			#ifndef CHAPTER_H_
			#define CHAPTER_H_
			#endif
		说明：
			如果没有定义名称CHAPTER_H_，那么就定义CHAPTER_H_。
			如果定义过了CHAPTER_H_，跳转到#endif后面。
9.2 存储持续性、作用域和链接性
	1.自动存储持续性
	2.静态持续变量
		代码：
			int global = 2;						//static duration, external linkage
			static int oneFile = 3;				//static duration, internal linkage
			int main()
			{
				static int count;			//static duration, no linkage
			}
		说明：
			静态持续变量在整个程序执行期间都存在。
			所有静态变量都被编译器 0 初始化，不论是否显示初始化。接下来，如果显示初始化了变量，编译器在对这些变量赋值。
	3.静态持续性、外部链接性
		链接型为外部的变量通常简称为外部变量，它们的存储持续性为静态，作用域为整个文件。外部变量也称全局变量。
		外部变量首先需要定义，在其他文件中使用时需要声明（引用声明）。
		声明使用关键字extern，且不进行初始化，否则视为定义。（定义时使用extern，显示指出这是外部变量，会在其他文件中使用。在函数内部也可以使用，显示指出这是一个全局变量）
		在函数内部使用全局变量时，也可以这样：   ::value  ，这意味着value是全局变量，推荐使用这种方法。
	4.静态持续性、内部链接性
		代码：
			//file1
			int errors = 20;		//external declaration
			----------------------------------
			//file2
			static int errors = 5;	//known to file2 only,隐藏file1的error，省略static将导致重复定义
	5.静态存储持续性、无链接性
	6.说明符和限定符
		说明符：auto, register, static, extern, thread_local, mutable
			mutable：即使结构变量为const，但只要相应的成员变量被声明为mutable，也可以对成员变量进行修改。
		cv-限定符：const, volatile
			const：内存被初始化后，程序便不能对它进行修改。
				attention:
					const用于全局变量时，其链接性为内部的。这种规则为在头文件中定义常量提供了方便。当一个头文件被包含在两个文件中时，内部链接性防止多次定义。
					如果希望某个常量的链接性为外部，则可以使用extern关键字覆盖默认的内部链接性。
						extern const int states = 50;
						这种情况下，必须在所有使用该常量的文件中使用extern关键字来声明它。但是，依旧只有一个文件可对其进行初始化（所以，不能简单的在头文件中进行初始化？）。
			volatile：表明即使程序没有对内存单元进行修改，其值也可能发生变化。一般用于硬件，程序通信中。防止编译器让系统从寄存器读取多次，而不读取内存。
	7.函数和链接性
		默认情况下，函数存储持续性是静态的，链接性是外部的。可以使用static将链接性改为内部。
	8.存储方案与动态分配
		1.使用new初始化
			int *p = new int (3);	//*p set to 3
			int *pArr = new int [4] {1, 2, 3, 5};	
		2.new分配内存失败时，会引发std::bad_alloc异常。
		3.运算符new, new[], delete, delete[]调用函数
			void * operator new(std::size_t);
			void * operator new[](std::size_t);
			void * operator delete(void *);
			void * operator delete[](void *);
		4.定位new运算符
			char buffer[100];
			int *p1 = new (buffer) int[3];	//从buffer地址开始申请三个int空间内存
			int *p2 = new (buffer) int [4];	//从buffer地址开始申请三个int空间内存，不跟踪哪些内存已分配，直接覆盖，可以使用内存偏移分配管理内存。
9.3 名称空间
	1.创建和添加名称空间
		创建：
			namespace Jack	
			{
				double pail;
				void Fun();				//function declaration
				struct Well {...}
			}
		添加：
			namespace Jack
			{
				int pal;
				void Fun()
				{
					std::cout << "Add Function definition" << std::endl;		//function definition
				}
			}
		说明：
			名称空间是全局的，可以位于另一个名称空间中，但不能位于代码块中。默认情况下，名称空间名称的链接性是外部的（除非它引用了常量）。（常量？）
			除了用户定义的名称空间外，还存在一个全局名称空间，这个名称空间内的对象链接性都是外部的，作用域都是全局的。全局变量都位于这个名称空间内。
			任何名称空间中的名称都不会与其他名称空间中的名称发生冲突。名称空间中的声明和定义规则同全局声明和定义规则相同。
			名称空间是开放的，可以把名称添加到已有的名称空间中。
			导入名称空间里的函数时，只需导入函数名即可：
				using Jack::Fun;
				由于导入没有声明函数返回类型或函数特征标，因此所有重载函数都将被导入。
	2.using声明和using编译指令
			using声明使特定的标识符可用，using使整个名称空间可用。
				using Jack pail;	//a using declaration
				using namespace Jack;			//make all the names in Jack available globally
			using声明将名称添加到局部声明区域，作用方式与声明一个变量相似，覆盖同名全局变量，不允许声明其他同名变量。
			using编译指令导入一个已经在函数中声明的名称，则名称空间中的名称被隐藏，就想隐藏同名的全局变量一样。
			一般来说，使用using声明比using编译指令安全，因为它只导入需要的名称，如果与局部变量发生冲突，编译器会报错。而使用using编译指令，编译器不会报错。另外，由于名称空间的开发性，使得名称空间的名称可能分散在许多地方，难以知道导入了哪些名称。所以一般推荐使用using声明。
	3.其他特性
		嵌套名称空间，名称空间中使用using声明和using编译指令，
			代码：
				namespace Jack
				{
					namespace bags
					{
						int price;
					}
					using std::cin;
					using namespace Name;		//Name 是一个名称空间
				}
			说明：
				由于可以在名称空间中声明名称空间，所以
					using namespace Jack;
					等价于
					using namespace Jack;
					using namespace Name;
				还可以为名称空间创建别名
					namespace J = Jack;
					namespace JN = Jack::Name;		//简化对嵌套名称空间的书写
	4.未命名的名称空间
		代码：
			namespace 
			{
				int icecream;
			}
		说明：
			由于该名称空间没有名字，所以不能在其他文件中使用该名称空间中的名字。这提供了链接性为内部的静态变量的可替代品。
	5.名称空间的使用指导原则
		使用名称空间里的变量，而不是用外部全局变量
		使用名称空间里的变量，而不是用静态全局变量		//全局变量不就是静态？那外部全局变量和静态全局变量，有什么区别(⊙o⊙)？
		如果开发了一个函数库或类库，应将其放在一个名称空间中的。实际上，C++当前提倡将标准函数库放在名称空间std中。
		仅将using编译指令作为从旧代码转换为使用名称空间的权宜之计。
		不要在头文件中使用using编译指令。	//掩盖了那些名称可用
		导入名称时，首选使用作用域解析运算符或using声明的方法。
		对于using声明，首选将作用域设置为局部，而不是全局。
*/
/*
3.下面是一个结构声明：
	struct Chaff
	{
		char dross[20];
		int slag;
	};
	编写一个程序,使用定位new运算符将一个包含两个这种结构的数组放在一个缓冲区中。然后,给结构的成员赋值(对于char数组,使用函数strcpy()),并使用一个循环来显示内容。一种方法是像程序清单9.10那样将一个静态数组用作缓冲区:另一种方法是使用常规new运算符来分配缓冲区。			//TestNew()
*/
#include <iostream>
#include <cstring>
#include "chapter09.h"

void Chapter09::TestNew()
{
	char arr[50];	//bigger than 24 * 2
	Chaff * cf1 = new(arr) Chaff;
	strcpy_s(cf1->dross, "chaff first");
	cf1->slag = 1;
	Chaff* cf2 = new(arr + sizeof(Chaff)) Chaff;
	strcpy_s(cf2->dross, "chaff second");
	cf2->slag = 2;
	Chaff* pCf = cf1;
	for (int i = 0; i < 2; i++)
	{
		std::cout << pCf->dross << std::endl;
		pCf++;
	}

	char* pArr = new char[50];
	Chaff* cf3 = new(pArr) Chaff;
	strcpy_s(cf3->dross, "chaff third");
	cf3->slag = 3;
	Chaff* cf4 = new(pArr + sizeof(Chaff)) Chaff;
	strcpy_s(cf4->dross, "chaff forth");
	cf4->slag = 4;
	Chaff* pCf2 = cf3;
	for (int i = 0; i < 2; i++)
	{
		std::cout << pCf2->dross << std::endl;
		pCf2++;
	}
	delete[] pArr;
}
