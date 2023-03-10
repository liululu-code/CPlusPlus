/*
10.1 过程性编程和面向对象编程
	1.OOP特性：
		抽象，封装和数据隐藏，多态，继承，代码的可用性
10.2 抽象和类
	1.通常，C++程序员将接口（类定义）放在头文件中，将实现（类方法的代码）放在源文件中
	2.不必在类声明中使用关键字private，因为这是类对象的默认访问控制。若要强调数据隐藏，可显式使用private。
	3.类成员函数
		定义成员函数时，使用作用域解析运算符（::）来标识函数所属的类。
		类方法可以访问类的private组件
		采用函数调用的意义，不必每次重新输入计算代码，可以确保执行的计算完全相同。易于修改代码。
		定义位于类声明中的函数都将自动成为内联函数，如果愿意，也可以在类声明之外定义成员函数，但需使用inline限定符。
		内联函数的特殊规则要求在每个使用他们的文件中都对其进行定义，确保内联定义对多文件程序中的所有文件都可用。最简单的方法是，将内联定义放在定义类的头文件中（声明与定义都放在头文件中，仅对与内联函数，对于其他函数会导致多重定义）。
		如果在类声明中定义方法，等同于 将方法替换为原型，然后在类声明后面将定义改写为内联函数。（这也是可以在类声明之外使用inline定义内联函数的理由）
		设计一个类时后，类设0计人员只能修改类的实现细节，而不能修改接口。（否则会导致大量代码出错）。
10.3 类的构造函数和析构函数
	1.构造函数
		构造函数没有声明类型（返回类型），原型位于类声明的公有部分，程序声明对象时，将自动调用构造函数
		构造函数的函数名与类名相同
		类成员名和类方法参数名
			不要将类成员名称用作构造函数的参数名，否则会导致错误。	//也不要用于其他方法的参数名
				一般常见的做法是在数据成员名前使用 m_ 前缀
				另一种做法是在成员名后使用后缀 _
		使用构造函数
			显式调用构造函数：
				Stock food = Stock("world Cabbage", 250, 1.24);			//Stock是一个类，包含三个数据成员。
			隐式调用构造函数：
				Stock food("world Cabbage", 250, 1.24);				//与显式调用等价
			无法使用对象来调用构造函数，因为在调用构造函数之前，对象是不存在的。
			但可以使用构造函数重新为对象赋值，这种方式会生成一个临时对象。
				food = Stock("temp class", 200, 1.4);			//先调用构造函数生成一个临时对象，然后把临时对象复制到food对象中
				注意：
					与显式调用构造函数很相似，但显示调用是初始化。显式调用可能会创建临时对象，也可能不会，但是赋值一定会创建临时对象。
		默认构造函数
			当且仅当没有定义任何构造函数时，编译器才会提供默认构造函数。如果定义了非默认构造函数，程序员就必须手动提供默认构造函数。否则编写使用默认构造函数的代码时将会出错。
				Stock food;			//使用默认构造函数，如果不提供，就会出错
			定义默认构造函数
				一种是给已有构造函数所有参数提供初始值
					Stock(const string & str = "Error", int n = 0, double pr = 0.0);	//声明时这样声明，定义方法时不写具体参数
				另一种是通过函数重载定义一个没有参数的构造函数
					Stock();
				由于只能由一个默认构造函数，因此不要同时使用以上两种方式。
				通常应初始化所有对象，以确保所有成员一开始就有已知的合理值。即设计类时，通常应提供对所有成员做隐式初始化的默认构造函数。推荐使用Stock();这种形式。
	2.析构函数
		析构函数的函数名在类名前加 ~ ，析构函数没有返回值和声明类型，析构函数也没有参数。因此析构函数的原型只有一种：
			~Stock();		//Stock是类名
	3.C++列表初始化用于类：
		Stock food = {"list inistation", 100, 2.0};		//ok
		Stock food {"list inistation", 100, 2.0};		//ok
		Stock food {};									//call default constructor
	4.const成员函数
		代码：
			const Stock food = Stock("world Cabbage", 250, 1.24);
			food.Show();			//error!
		说明：
			Show()函数无法确保调用对象不被修改。调用对象和const一样，不能被修改。
		解决方案：
			将const关键字放在函数的括号后面，也就是说，Show()函数的声明应该这样写：
				void Show() const;		//声明
				void Stock::Show() const		//定义开头
		以这种方式声明和定义的函数被称为const成员函数。只要类方法不声明为const对象，就应该将其声明为const。
	5.如果一个类含有接收一个参数的构造函数，允许使用赋值语法将一个值赋给对象。
		Stock fo = 2;	//类似这种形式
		这种特性可能导致问题，不推荐使用。
10.4 this指针
	1.每个成员函数（包括构造函数和析构函数）都有一个this指针，this指针只想调用对象。如果方法需要引用整个调用对象，可以使用表达式 *this 。如果在函数后面使用this限定符，this将被限定为const，不能使用this指针修改对象的值。
10.5 对象数组
	1.初始化对象数组
		可以用构造函数初始化对象数组，如果类包含多个构造函数，可以对不同的元素使用不同的构造函数。
		Stock stocks[10] = 
		{
			Stock("first", 1, 1.1);
			Stock("second", 2, 2.2);
			Stock();
		}										//剩余的7个对象将使用默认的构造函数进行初始化
10.6 类作用域
	1.在类中定义的名称（如类数据成员和类成员函数名）的作用域为整个类，在类外是不可知的。类作用域意味着不能从外部直接访问类的成员，要访问只能通过对象。
	2.声明作用域为类的常量，有两种方式
		一是在类中定义一个枚举，在类声明中定义的枚举的作用域为整个类。
			enum {Months = 12};			
			以这种方式声名枚举并不会创建类数据成员，所有对象中都不包含枚举，Months只是一个符号名称，在作用域为整个类的代码中遇到它时，编译器将用12替换它。
			由于这里只是想创建符号常量，并不创建枚举型变量，因此这里不需要提供枚举名。
		二是使用关键字static
			static const int Months = 12;
			该常量将于其他静态变量存储在一起，而不存储在对象中。（该常量的作用域是类？）
	3.关于枚举
		传统枚举方式的问题--常规枚举
			enum egg {SMALL, MEDIUM, LARGE};
			enum apple {SMALL, MEDIUM, LARGE};
			这将无法编译，因为egg SMALL 和 apple SMALL 位于相同的作用域，他们将发生冲突。
		C++11新枚举--作用域内枚举
			enum class egg {SMALL, MEDIUM, LARGE};
			enum class apple {SMALL, MEDIUM, LARGE};
			此时使用枚举名来限定枚举量：
				egg choice = egg::SMALL;
				apple iphone = apple::SMALL;
		需要时，常规枚举将自动转换为整形。但作用域内枚举不会自动转换类型。
		默认情况下，作用域内枚举的底层类型为int。常规枚举的底层类型如果没有指定，由编译器选择。
			enum class : short egg {SMALL, MEDIUM, LARGE};		// :short 将底层类型指定为short，底层类型必须是整形。也可以使用这种语法指定常规枚举的底层类型。
10.7 抽象数据类型 栈 的简单实现
*/

//这一练习题都是类的基本操作，前几章都有了，用类实现数据结构接口，再等等吧。
#include "chapter10.h"
#include <iostream>


Chapter10::Chapter10()
{
	m_val = 0;
}


void Chapter10::Show()
{
	std::cout << m_val << std::endl;
}