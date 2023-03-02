/*
15.1 友元			//可从外部访问类的私有成员
	1.友元类
		TV和遥控器的关系，不是is-a，不是has-a。遥控器可以改变TV的状态，所以可将Romote类作为TV类的一个友元类。
			只要在TV类中包含下面语句就可以将Remote类作为友元类。
				friend class Remote;
			如果不使用友元类，必须将TV类的私有部分设置为公有，或者创建一个笨拙的，大型的类来包含电视机和遥控器。
	2.友元成员函数		//使特定的类成员成为另一个类的友元，而不是整个类	
		这样做稍微有点麻烦，必须小心各种声明和定义的排列顺序。如果要将Remote类的SetChan方法作为TV类的友元，可按照下列顺序排列：
			class TV;			//前向声明
			class Remote {...};
			class TV {...};			//类声明内声明 friend void Remote::SetChan(TV & t, int c);
			//put Remote method definitions here			//如果Remote类中有方法调用了TV类的成员，则将方法定义放在TV类声明之后。如果该方法要当作内敛函数，可以使用inline。内联函数的链接性是内部的，这意味着内联函数的定义必须在使用函数的文件中。
		当然，如果要让整个类成为友元，并不需要前向声明。因为友元语句本身已经指出这是一个类了。
	3.其他友元关系
		互为友元，注意顺序。类的顺序问题不大（由friend class指出这是一个类了），对于方法可参考友元成员函数顺序。保证编译器有足够的信息编译该方法。
	4.共同的友元		
		两个类的共同的友元函数，函数可能需要传入两个类的参数，这时需要使用前向声明
			class TV;			//前向声明，保证共同的友元函数知道TV是一个类
			class Remote {...};		//在Remote和TV类中声明共同的友元函数
			class TV {...};	
15.2 嵌套类
	1.作用域和访问控制
		嵌套类声明的位置决定了类的作用域或可见性。类可见后，访问控制规则（公有、私有、保护、友元）将决定程序对嵌套类成员的访问权限。
	2.模板中的嵌套
		与普通类的嵌套非常相似，区别只在于具体参数用类型参数代替。
15.3 异常
	1.调用abort()
		abort()原型位于头文件cstdlib中，它向标准错误流（cerr使用的错误流）发送消息abnormal program temination，然后终止程序。它还返回一个随实现而异的值，abort()是否刷新文件缓冲区取决于实现。如果愿意，也可以使用exit()，该函数刷新文件缓冲区，但不显式消息。
	2.返回错误码
		不适用异常，通过程序返回的方式返回错误码。
	3.异常机制
		try块标识其中特定的异常可能被激活的代码块，它后面跟一根或多个catch块。
		catch关键字表示捕获异常。catch后面的括号表示异常处理程序要响应的异常类型，花括号表示要指出的措施。
		throw关键字表示要引发异常。
		如果函数引发了异常，但没有try块或没有匹配的处理程序时，默认情况下，函数最终将调用abort()函数。
	4.将对象用作异常类型
		使用对象的优点：
			可以用不同的异常类型来区分不同的函数在不同情况下引发的异常。
			对象可以携带信息，catch块可以根据这些信息提供解决方案。
	5.异常规范和C++11		
		C++98添加，C++11摒弃，以后可能从标准中删除，不建议使用：
			double marm(double) throw();		//throw()部分就是异常规范，
		C++11支持一种特殊异常，即可使用关键字noexcept指出函数不会引发异常：
			double marm(double) noexcept;		
	6.栈解退
		发生异常时，函数不会逐层退出，而是直接退回到使用try块的地方，中间函数的析构函数不会被自动调用。栈解退技术保证析构函数被调用。
	7.其他异常特性
		throw抛出的是异常对象的临时拷贝，所以即使catch中使用对象引用，引用的也是异常对象的临时拷贝。引用的好处是可以使用基类引用执行派生类对象。
		也因此，catch中的异常对象的排列顺序应与继承顺序相反，先捕获派生类对象，最后捕获基类对象。
		使用省略号表示异常类型，可以捕获任何异常
			catch (...) {...}		//catches any type of exception
	8.exception类
		exception类被定义在exception头文件中，C++可以把它用作其他异常类的基类，这个类中有一个名为what()的虚成员函数，它返回一个字符串。
		stdexcept异常类
			头文件stdexcept中定义了几个异常类，他们都是以公有方式从execption类派生过来的：
				logic_error类			//一般表示可以通过编程修复的问题
				runtime_error类			//无法避免的问题
				它们之间的区别在于：不同的类名让您能够处理不同的问题。当然，使用积累引用也可以一起处理他们。
				这两个类的构造函数接受一个string对象作为参数，该参数作为方法what()以char *方式返回的字符数据。
				logic_error类描述了典型的逻辑错误，其派生类有：
					domain_error;
					invalid_error;
					length_error;
					out_of_bounds;
				run_time类描述了可能在运行期间发生但难以预计和防范的错误，其派生类：
					range_error;
					overflow_error;
					underfloe_error;
		bad_alloc异常和new
			对于new分配引起的问题，C++让new引发bad_alloc异常。头文件new中包含bad_alloc的声明。
		空指针和new
			除了异常，C++还提供了一种在失败时返回空指针的new，用法如下：
				int *pi = new (std::nothrow) int;
				int *pa = new (std::nothrow) int[500];
	9.异常，类和继承
		异常类之间可以派生，包含，嵌套。
	10.异常何时会迷失方向
		两种异常会导致程序异常终止：
			未捕获异常
				程序先调用terminate(), terminate()默认调用函数（abort()）,可以使用set_terminate()修改默认调用函数。terminate() and set_terminate()都是在头文件exception中声明的。
			意外异常
				当函数引发了其异常规范中没有的异常时，程序调用unexpected(), unexpected()默认调用terminate(),terminate()调用默认调用函数（abort()）。也存在set_unexpected()，位于头文件exception中。
					与set_terminate()相比，set_unexpected()略有不同。
	11.有关异常的注意事项
		应在设计程序时就加入异常处理功能。
		对于new动态分配，如果在delete释放内存前引发了异常，将导致内存泄露哦。解决方式是使用智能指针模板。
		要开发出优秀的软件，必须花时间了解库和类中的复杂内容，就像必须花时间学习C++本身一样。
15.4 RTTI
	1.RTTI的用途
		由于基类指针可以指向基类及其派生类的对象，如何知道RTTI指向的是那种对象呢？这就需要使用RTTI。
	2.RTTI的原理
		C++有三个支持RTTI的元素：
			dynamic_cast		//使用一个指向基类的指针来生成一个只想派生类的指针，否则，该运算符返回0，即空指针
			typeid			//返回一个指出对象的类型的值
			type_info		//存储了有关特定类型的信息
			只能将RTTI用于包含虚函数的层次结构。	//只有对于这种类层次结构，才应该将派生对象的地址赋给基类指针
		dynamic_cast：
			baseClass * pb = dynamic_cast<subClass *> (psb);	//pb基类，psb派生类。能转换，返回指针，否则返回0，即空指针。
			最常用的RTTI组件，回答“是否可以安全的将对象的地址赋给特定类型的指针”，这比回答“指针指向的是哪种类型的对象”更通用，也更有用。
			也可以将dynamic_cast用于引用类型，此时当请求不正确时，引发bad_cast异常，这种异常是从exception派生过来的，在头文件typeinfo中定义。
				try { baseClass & bc = dynamic_cast<subClass &> (sb); }
				catch (bad_cast &) {...};
		typeid and type_info:
			typeid能够确定两个对象是否为同种类型，它返回一个对type_info对象的引用。
				typeid(className) == typeid(*pclass)
				如果pclass是一个空指针，程序引发bad_typeid异常，该异常由execption类派生而来，在头文件typeinfo中声明。
			type_info类的实现随厂商而已，但包含一个name()成员，该函数返回一个随实现而异的字符串：通常（不一定）是类的名称。下面的语句将返回指针pg指向的对象所属的类定义的字符串：
				std::cout << typeid(*pg).name();
15.5 类型转换运算符		
	1.C++创始人认为C语言中类型转换过于松散，于是添加了4个类型转换运算符，使转换过程更规范：
		dynamic_cast			//语法都与dynamic_cast相同
		const_cast				//对const or volatile类型进行转换
		static_cast				//可用于基类向派生类转换
		reinterpret_cast		//用于天生危险的类型转换，比如可以将int前两个字节转换为short类型
*/
#include <iostream>
#include "chapter15.h"
#include <new>


void Chapter15::Run()
{
	std::cout << "test";
	
}
