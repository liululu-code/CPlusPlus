/*
14.1 包含对象成员的类
	1. 通常，包含，私有继承和保护继承用于实现has-a关系。
	2.valarray类简介
		valarray类是由头文件<valarray>支持的。
		这是一个模板类，模板特性意味着声明对象时，必须指明具体的数据类型。		
		声明和初始化：
			double gpa[5] = { 3.3, 4.4, 5.5, 6.6, 7.7 };
			valarray<double> v1;		//an array of double, size 0
			valarray<int> v2(8);		//an array of 8 int elements
			valarray<int> v3(10, 8);	//an array of 8 int elements, each set to 10
			valarray<double> v4(gpa, 4);	//an array of 4 elements, initialized to the first elements of gpa
			valarray<int> v5 = { 11, 22, 33, 44 };
		一些方法：
			operator[]();	//访问各个元素
			size();			//返回包含的元素数
			sum();			
			max();
			min();
	3.接口和实现
		使用公有继承时，类可以继承接口，可能还有实现（基类的纯虚函数提供接口，不提供实现）。获得接口是is-a关系的组成部分。
		使用组合，类可以获得实现，但不能获得接口。不继承接口是has-a关系的组成部分。
	4.复习：可以将一个参数调用的构造函数用作从参数类型到类类型的隐式转换函数，但这通常不是一个好主意。可以使用explicit关闭隐式转换。
		explicit Student(int n) : name("Nolly"), scores(n) {}
	5.C++使用explicit防止单参数构造函数的隐式转换，使用const限制方法修改数据。这样做的根本原因是：在编译阶段出现错误优于在运行阶段出现错误。
	6.关于类数据成员初始化的顺序
		当初始化列表中包含多个项目时，这些项目被初始化的顺序为他们被声明的顺序，而不是他们在初始化列表中的顺序。
		一般情况下初始化顺序无所谓，但如果代码使用一个成员的值，作为另一个成员的初始化表达式的一部分时，初始化顺序就非常重要了。
14.2 私有继承
	1.使用私有继承时，基类的公有成员和保护成员都将成为派生类的私有成员。这意味着基类方法不会成为派生类公有接口的一部分，但可以在派生类的成员函数中使用它们。
	2.包含将对象作为一个命名的成员对象添加到类中，而私有继承将对象作为一个未命名的继承对象添加到类中。我们使用子对象（subobject）表示通过继承或包含添加的对象。
	3.要进行私有继承，使用关键字private来定义类。（实际上，private是默认值，省略访问限定符也将导致私有继承。）
		class Student : private std::string, private std::valarray<double>
		{
			public:
			...
		}
		使用多个基类的继承被称为多重继承（multiple inheritance, MI）。
		新的Student类不需要私有数据，因为两个基类已经提供了所需的数据成员。			//私有继承提供无名称的子对象成员，包含提供被显示命名的子对象成员。
		对于继承类，构造函数将使用成员初始化列表语法，它使用类名而不是成员名来标识构造函数：		//因为没有成员名
			Student(const char * str, const double * pd, int n) : std::string(str), std::valarray<double>(pd, n) {}		
		总之：使用包含时使用对象名调用方法，使用私有继承时，使用类名和作用域解析运算符来调用方法。
	4.访问基类对象
		由于采用私有继承时，积累对象没有名称，访问基类对象方法可以通过类名，但访问基类对象本身必须通过强制类型转换。
			const string & Student::Name() const
			{
				return (const string &) *this;
			}
	5.访问基类对象友元函数
		传递友元函数参数时，将参数类型强制转换为基类类型。
	6.使用包含还是私有继承建立has-a关系
		大多数程序员倾向于使用包含。
			首先，易于理解。
			其次，继承会引起很多问题。
			另外，包含能够包括多个同类的子对象。
		然而，继承所提供的特性确实比包含多。
			包含不能使用保护成员，但继承可以。
			继承可以重新定义虚函数，包含不能。
		通常，应使用包含建立has-a关系，如果新类需要访问原有类的保护成员，或需要重新定义虚函数，则应使用私有函数。
	7.保护继承
		使用保护继承后，基类的公有和保护成员都成为派生类的保护成员。
		保护继承与私有继承十分相似，区别在于，使用私有继承时，第三代派生类不能使用基类的接口，这是因为基类的公有方法在第二代派生类中变成了私有方法。而保护继承始终都是保护方法。
	8.使用using重新定义访问权限
		使用保护继承或私有继承时，要想让基类的方法在派生类外也可用，有两种方法
			一：定义一个使用该基类方法的派生类方法。类外通过访问派生类方法调用基类方法。
			二：使用using声明，指出派生类可以使用特定的基类成员，即使是私有继承。
				using std::valarray<double>::min;		//是基类valarray中的min()方法在派生类中就像是派生类的公有方法一样。
				注意：
					using声明只有成员名，没有圆括号，函数特征标和返回类型。
					using声明只适用与继承，而不适用于包含。
14.3 多重继承（multiple inheritance, MI）
	假设有基类Worker，Waiter和Singer都是Worker的派生类，SingingWaiter是Waiter和Singer的多重继承派生类。
	1.有多少Worker
		由于Waiter and Singer都继承了一个Worker组件，因此SingingWaiter中含有两个Worker组件。于是，以下赋值将出现二义性：
			SingingWaiter ed;
			Worker * pw = &ed;		//二义性，
			通常这种赋值将把基类指针设置为派生对象中的基类对象的地址。但ed中包含两个Worker对象，有两个地址可供选择，多以应使用类型转换来指定对象。
			Worker * pw1 = (Waiter *) &ed;
			Worker * pw2 = (Singer *) &ed;
		一般来说，SingingWaiter不需要两个Worker组件，虚基类可以实现这个功能。		//有时有些类需要多个基类组件
		虚基类
			虚基类使得从多个类（它们的基类相同）派生出的对象只继承一个基类对象。
				class Singer : virtual public Worker {...};
				class Waiter : public virtual Worker {...};		//public 和 virtual的先后次序无所谓
			现在，SingingWaiter可定义如下：
				class SingingWaiter : public Singer, public Waiter {...};		//两个public都不能省，否则按默认private算
			为什么不将虚基类设置为默认方式：
				一，一些情况下，可能需要基类的多个拷贝。
				二，将基类作为虚的要求程序完成更多的计算，为不需要的工具付出代价是不应当的。
				三，这样做有其缺点。
		新的构造函数规则
			使用非虚基类时，派生类的构造函数可以调用继承的基类的构造函数，基类的构造函数又可以调用它继承的基类的构造函数，逐层传递。
			但是虚基类不行，
				SingingWaiter(const Worker & wk, int p = 0, int v = 1) : Waiter(wk, p), Singer(wk, v) {}		//这样做无法将wk传递给Worker，编译器将调用Worker的默认构造函数
				将wk传递给Worker时，存在两种不同的路径（Waiter, Singer），冲突。C++在基类是虚的时，禁止信息通过中间类自动传递给基类。应该这样写：
					SingingWaiter(const Worker & wk, int p = 0, int v = 1) : Worker(wk), Waiter(wk, p), Singer(wk, v) {}		//Waiter and Singer构造函数要求有wk
					对于虚基类，只能这样做；但对于非虚基类，这样传递参数是非法的。
				警告：如果类有间接虚基类，除非只适用该虚基类的默认构造函数，否则必须显式地调用该虚基类的某个构造函数。
	2.哪个方法
		多重继承时，当继承的两个类存在相同的方法名时，可能导致函数调用的二义性。可以使用作用域解析运算符来澄清编程者的意图：
			SingingWaiter newhire("El Ec", 2005, 6, soprano);
			newhire.Singer::Show();			//使用作用域解析运算符
			更好的方法是在SingingWaiter中重新定义Show()：
				void SingingWaiter::Show()
				{
					Singer::Show();			//函数内部指明调用哪个函数
				}
		对于单继承，让派生类调用基类方法，基类方法再调用它的基类方法是可以的。但是对于多重继承，这种方法不行。
			void SingingWaiter::Show() { Singer::Show(); }			//方法无效，因为它忽略了Waiter组件			？？
			可以同时调用Waiter版本的Show()来弥补：
				void SingingWaiter::Show()
				{
					Singer::Show();
					Waiter::Show();									//这样就有效了？
				}
			然而，这将显式姓名和ID两次，因为Singer::Show() 和Waiter::Show() 都调用了Worker::Show()组件。
			解决方案：
				不同于单继承的递增调用（派生类的Show() 调用基类的Show(),基类在调用它的基类的Show() ），而是采用模块化方式，每一个类的方法只显示自己的内容。最后在SingingWaiter::Show()中将组件组合起来：
					void SingingWaiter::Show()
					{
						Worker::Show();
						Singer::Show();
						Waiter::Show();
					}
				注意：这种方式需要将某些辅助方法设置为保护类型（设置为私有类型就不能在派生类中调用了）
	3.混合使用基类和非基类
		当类通过多条虚途径和非虚途径继承某个特定的基类时，该类将包含一个表示所有的虚途径的基类子对象和分别表示各条非虚途径的多个基类子对象。
	4.虚基类和支配
		如果派生类从多个不同的类继承了多个同名方法，使用这个方法时如果没有用类名限定，将导致二义性。但如果使用的是虚基类，这样做不一定导致二义性。此时，派生类中的方法优先于直接或间接祖先类的同名方法。而且这与访问规则无关，不论是私有，保护还是公开，都遵循这一规则。
14.4 类模板
	1.定义类模板
		类声明
			template <class Type>		//Type是泛型标识符，也称类型参数
			或者
			template <typename Type>	//较新的C++，推荐使用这种。Type也可以缩写为T，大多数人使用的也就这两种写法
		类方法
			类方法可以使用模板成员函数，每个函数头都将以相同的模板声明打头。
				template <typename Type>
				bool Stack<Type>::push(const Type & item) {...}		//类限定符使用Stack<Type>::
			如果在类声明中定义了类方法（内敛定义），可以省略模板前缀和类限定符
		不论是类模板还是成员函数模板，都不是定义，只是说明了如何生成类和成员函数的定义。
		不能将模板成员函数放在独立的实现文件中，因为模板不是函数，不能单独编译。可以将所有模板信息放在同一个头文件中，并在使用这些模板的文件中包含该头文件。
	2.使用模板类
	3.深入探讨模板类
		对于模板类，可以在模板声明或模板函数定义内使用Stack，但在类外面，即指定返回类型或使用作用域解析运算符时，必须使用完整的Stack<Type>。
		对于模板头：
			template <typename T, int n>
			T为类型参数，int指出n的类型为int。这种指定特殊的类型而不是用作泛型名的参数成为非类型或表达式参数。
			表达式参数可以是整形，枚举，引用或指针。模板代码不能修改参数的值，也不能使用参数的地址。实例化模板时，用作表达式参数的值，必须是常量表达式。
			相比于采用new使用动态内存构建动态数组，采用表达式参数的使用的是为自动变量维护的内存栈，速度更快，尤其在使用很多小型数组时。
			表达式参数方法的缺点：每种数组大小都将生成自己的模板，下面的声明将生成两个独立的类变量。
				ArrayTP<double 12> eggWeights;
				ArrayTP<double 13> donuts;
				使用动态数组下面的声明只生成一个类声明，并将数组大小信息传递给类的构造函数。
					Stack<int> eggs(12);
					Stack<int> dunkers(13);
				另外，构造函数的方式更通用，这是因为数组大小是作为类成员（而不是硬编码）存储在定义中的。这样可以将一种尺寸的数组赋给另一种尺寸的数组，也可以创建允许数组大小可变的类。
		模板多功能性
			递归使用模板
				ArrayTP< ArrayTP<int, 5>, 10 > twodee;
				这使得twodee是一个包含10个元素的数组，其中每个元素都是一个包含5个int元素的数组。与之等价的常规数组声明如下：
					int twodee[10][5];
			使用多个类型参数
				template <typename T1, typename T2>
				class Pair {...};
			默认类型模板参数
				template <typename T1, typename T2 = int>
				class Topo {...};		//当省略T2的值时，编译器将自动使用int
				可以为类模板类型参数，非类型参数（表达式参数）提供默认值，但不能为函数模板参数提供默认值。
		模板的具体化
			隐式实例化
				到目前未知，所有的模板示例都是隐式实例化。它们声明一个或多个对象，指出所需的类型，编译器使用通用模板提供的方式生成具体的类定义。
					ArrayTP<double, 10> stuff;
			显式实例化
				template class ArrayTP<string, 100>;		//将ArrayTP<string, 100>声明为一个类
				虽然没有创建或提及类对象，编译器也将生成类声明（包括方法定义）。和隐式实例化一样，编译器根据通用模板生成具体化。
			显式具体化
				显式具体化是针对特定类型的定义。
					template <> class Classname<specialized-type-name> {...};	
					当这个显式具体化模板和通用模板都与实例化请求匹配时，编译器使用显式具体化模板。
			部分具体化
				部分具体化可以给类型参数之一指定具体的类型：
					template <typename T1, typename T2> class Pair {...};		//general template
					template <typename T1> class Pair<T1, int> {...};			//部分具体化，将T2具体化为int，如果指定所有的类型，将<>留空，将导致显式具体化
					如果有多个具体化可供选择，编译器将选择具体化程度最高的模板。
		成员模板
			可将其他模板类或模板函数作为其成员。（在这个模板类中声明中定义其他类声明，或函数声明和定义。）
		将模板用作参数-------------------------------//不行了不行了，以后再看吧。
		模板类和友元
			非模板友元
			约束模板友元
			非约束模板友元
		模板别名
*/



#include <iostream>
#include "chapter14.h"


void Chapter14::Run()
{
	//TestStack1();
	TestStack2();
}

void Chapter14::TestStack1()		//generate by ChatGPT
{
	Stack1<int> intStack;
	// 测试 Push 和 Pop
	intStack.Push(1);
	intStack.Push(2);
	intStack.Push(3);

	int item;
	while (intStack.Pop(item)) {
		std::cout << "弹出元素：" << item << std::endl;
	}

	// 测试 IsEmpty 和 IsFull
	std::cout << "intStack 空？" << intStack.IsEmpty() << std::endl;
	std::cout << "intStack 满？" << intStack.IsFull() << std::endl;

}
void Chapter14::TestStack2()		////generate by ChatGPT
{
	Stack2<int> s1; // 默认构造函数
	for (int i = 0; i < 10; ++i)
	{
		s1.Push(i); // 压入元素
	}
	std::cout << "Stack is full? " << s1.IsFull() << std::endl;
	while (!s1.IsEmpty())
	{
		int item;
		s1.Pop(item); // 弹出元素
		std::cout << item << " ";
	}
	std::cout << std::endl;

	Stack2<int> s2(5); // 带参数构造函数
	for (int i = 0; i < 5; ++i)
	{
		s2.Push(i);
	}
	std::cout << "Stack is full? " << s2.IsFull() << std::endl;
	while (!s2.IsEmpty())
	{
		int item;
		s2.Pop(item);
		std::cout << item << " ";
	}
	std::cout << std::endl;

	Stack2<int> s3(s1); // 拷贝构造函数
	while (!s3.IsEmpty())
	{
		int item;
		s3.Pop(item);
		std::cout << item << " ";
	}
	std::cout << std::endl;
}

