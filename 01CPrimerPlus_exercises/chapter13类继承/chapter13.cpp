/*
13.1 一个简单的基类
	1.C++提供了比修改代码更好的方法来扩展和修改类，这种方法叫做类继承
	2.继承的功能：
		可以在已有类的基础上添加功能
		可以给类添加数据
		可以修改类方法的行为
	3.即使购买的类只提供了类方法的头文件和编译后代码，仍可以使用库中的类派生出新的类。这种特性可以让在不公开具体实现的条件下将自己的类分发给别人，同时允许他们在类中添加新特性。
	4.派生类的实现
		code：
			class RatedPlayer : public TableTennisPlayer
			{
				...
			}
		description：
			使用public表明TableTennisPlayer是一个公有基类，这被称为公有派生。使用公有派生，基类的公有成员将成为派生类的公有成员。基类的私有部分也将成为派生类的一部分，但只能通过基类的公有和保护方法访问。
			RatePlayer类特征：
				派生类对象存储了基类的数据成员（派生类继承了基类的实现）
				派生类对象可以使用基类的方法（派生类继承了基类的接口）
			需要在继承特性中添加什么：
				派生类需要自己的构造函数
					构造函数必须给新成员（如果有的话）和继承的成员提供数据。
				派生类可以根据需要添加额外的数据成员和成员函数
	5.派生类构造函数
		创建派生类对象时，程序应先创建基类对象。这意味着基类对象应在程序进入派生类构造函数之前被创建。C++使用成员初始化列表语法完成这种工作。
			code1:
				RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht)
				{
					rating = r;		//可以写在成员初始化列表中，与 TableTennisPlayer(fn, ln, ht) 用 , 隔开：, rating(r)
				}
			description1:
				TableTennisPlayer(fn, ln, ht)是成员初始化列表，调用TableTennisPlayer构造函数创建基类对象。如果不显式调用基类构造函数，程序将自动调用默认构造函数。
				除非要使用默认构造函数，否则应显式调用正确的基类构造函数

			code2:
				RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) : TableTennisPlayer(tp), rating(r)
				{
				}
			description2:
		关于派生类构造函数的要点：
			首先创建基类对象
			派生类构造函数应通过成员初始化列表将基类信息传递给基类构造函数		//基类构造函数主要初始化继承的数据成员
			派生类构造函数应初始化派生类新增的数据成员					//派生类构造函数主要初始化新增的数据成员
			创建派生类对象时，程序先执行基类构造函数，然后执行派生类构造函数。对于析构函数，将首先执行派生类析构函数，然后自动执行基类析构函数
		除虚基类外，类只能将值传递会相邻的基类，但可以依此类推。
		派生类和基类之间的特性关系
			派生类对象可以使用基类的方法，只要方法不是私有的。
			基类指针可以在不进行显示转换的情况下指向派生类对象，基类引用可以在不进行显示转换的情况下引用派生类对象。反之不可。//基类小，即使基类指针指向派生类对象，但调用基类方法没有问题。
			基类指针或引用只能调用基类方法，不能调用派生类方法，即使指向的是派生类的对象。
			根据上述特性，基类引用定义的函数参数或指针参数可用于基类对象或派生类对象。		//将函数参数声明为基类，可传入基类和派生类两种对象，但只能通过这种方式调用基类方法
			引用兼容性属性也让您能够将基类对象初始化为派生类对象。	//这种情况可能调用复制构造函数将派生类中的基类数据成员复制给基类对象。
			同样，也可以将派生对象赋给基类对象。			//调用隐式赋值重载运算符
13.2 继承：is-a 关系
	1.C++有三种继承方式
		公有继承
			公有继承是最常用的方式，它建立一种is-a关系，即派生类对象也是一个基类对象，可以对基类对象执行的任何操作，也可以对派生类对象执行。
			公有继承不建立 has-a, is-like-a, is-implemented-as, uses-a 关系。
		保护继承
		私有继承
13.3 多态公有继承
	1.有两种机制可用于实现多态公有继承
		在派生类中重新定义基类的方法
			基类版本限定名为：Brass::ViewAcct()。派生类版本限定名为：BrassPlus::ViewAcct()。程序将使用对象类型来确定使用哪个版本。
		使用虚方法
			在方法声明中使用关键字 virtual。方法定义中不需要使用virtual。
			如果没有使用 virtual，程序将根据引用类型或指针类型选择虚方法。如果使用类virtual，程序将根据引用或指针指向的对象的类型来选择方法。
			因此，经常在类中将派生类会重新定义的方法声明为虚方法，方法在基类中被声明为虚的后，它在他派生类中自动成为虚方法。当然，在派生类声明中也使用关键字virtual指出哪些方法是虚方法非常好。
			基类中声明虚析构函数，可以保证在基类类型的指针指向派生类对象的情况下，使用delete释放这个指针时，能够正确释放派生类对象和基类对象占用的内存。如果析构函数不是虚的，则将只调用对应于指针类型的析构函数。
			注意：
				通常要在派生类中重新定义基类的方法，必须将基类方法声明为虚的。这样，程序将根据对象类型而不是引用或指针类型来选择方法版本。为基类声明一个虚析构函数也是一种惯例。
			在派生类中，使用作用域解析运算符来调用基类方法。			//Brass::ViewAcct();
13.4 静态联编和动态联编
	1.如果不使用显式类型转换，则向下强制转换是不允许的。（向下：基类转换为派生类）
	2.编译器对非虚方法使用静态联编，对虚方法使用动态联编。	//静态联编效率更高，动态联编灵活
		提示：如果要在派生类中重新定义基类的方法，则将它设置为虚方法，否则设置为非虚方法。		//实际设计类时方法属于那种情况并不那么明显，所以设计类并不是一个线性过程。
	3.虚函数注意事项：
		构造函数不能是虚函数。
		析构函数应当是虚函数，除非类不用做基类。通常应给基类提供一个虚析构函数，即使它并不需要析构函数。		//给类定义一个虚析构函数并非错误，即使这个类并不用作基类，这只是一个效率问题。
		友元不能是虚函数。因为友元不是类成员，只有成员才能是虚函数。
	4.重新定义继承的方法并不是重载。如果在派生类中重新定义函数，将不是使用相同的函数特征标覆盖基类声明，而是隐藏同名的基类方法，不论参数特征标如何，所以：
		如果重新定义基类的方法，应确保与原来的原型完全相同，但如果返回类型是积累引用或指针，则可以修改为指向派生类的引用或指针。这种特性被称为返回类型协变。
		如果基类声明被重载了，则应在派生类中重新定义所有的重载基类版本。
			如果方法内容不需要修改，则新定义可只调用基类版本：
				void BrassPlus::ViewAcct() const { Brass::ViewAcct(); }
13.5 访问控制：protected
	1.protected与private相似。在类外只能使用公有类成员来访问protected部分中的类成员。protected与private的区别只有在基类派生的类中才会表现出来。派生类的成员可以直接访问基类的protected成员，但不能直接访问基类的private成员。
	2.使用protected数据成员可以简化代码的编写工作，但存在设计缺陷。
		如果一个类的某些数据成员被设计成protected，则只能通过公有方法才能访问，但对于派生类来说，却可以直接访问。派生类会忽略基类的某些保护措施，直接访问protected数据。
		警告：最好对类数据成员采用私有访问控制，不要使用保护访问控制；同时使用基类方法使派生类能够访问基类数据。
	3.派生类可以调用protected方法，但这些方法并不是派生类对象的公有接口的组成部分。
13.6 抽象基类（abstract base class, ABC）
	1.C++使用纯虚函数提供未实现的函数。纯虚函数声明的结尾处为 =0 ，如下：
		virtual double Area() const = 0;	//a pure virtual function
		当类声明中包含纯虚函数时，则不能创建该类的对象。包含纯虚函数的类只能用作基类。要成为真正的ABC，必须至少包含一个纯虚函数。原型中的 =0 使虚函数成为纯虚函数。	//纯虚函数可以不加virtual
		C++允许纯虚函数有定义，只需要在实现文件中提供方法的定义即可。		//提供定义有意义吗？虚函数的声明就意味着要在派生类中重载这个函数。所以，我觉得没有
	2.ABC描述的是至少使用一个纯虚函数的接口，从ABC派生出的类，将根据派生类的具体特征，使用常规虚函数来实现这种接口。
	3.ABC理念
		ABC方法更具系统性，更规范。
		设计ABC之前，应先开发一个模型，指出编程问题所需的类以及它们之间的相互关系。
		一种学院派思想认为，如果要设计类型层次，则只能将那些不会被用作基类的类设计为具体的类，这种方法的设计更清晰，复杂程度更低。
		ABC要求具体派生类覆盖其纯虚函数，迫使派生类遵循ABC设置的接口规则。这种模型在基于组件的编程模式种很常见。在这种情况下，使用ABC使得组件设计人员能够制定”接口约定“，确保从ABC派生的所有组件都至少支持ABC指定的功能。
13.7 继承和动态内存分配
	1.如果基类使用动态内存分配，并重新定义赋值和复制构造函数，则会影响派生类的某些实现。
	2.第一种情况，派生类不使用new
		对于析构函数：
			首先知道，派生类的默认构造函数执行操作：执行自身代码后调用基类析构函数。由于派生类不使用new，因此使用默认析构函数即可。
		对于复制构造函数：
			首先知道，成员复制将根据成员数据类型采用相应的复制方式。复制类成员或继承的组件时，使用该类的复制构造函数完成。	//继承的基类成员，使用基类复制构造函数。
		对于赋值：
			自动使用基类的赋值运算符对基类组件进行赋值。
	3.第二种情况，派生类使用new
		这种情况下，必须显式定义析构函数，复制构造函数，赋值运算符。
		对于析构函数：
			派生类析构函数自动调用基类析构函数，故其自身职责是对派生类构造函数执行工作进行清理。
		对于复制构造函数：
			派生类复制构造函数只能访问派生类数据成员，因此它必须调用基类复制构造函数来处理共享的基类数据。	//一般情况下基类数据默认都是私有的
				调用基类复制构造函数的方式一般是通过成员初始化列表。
				HasDMA::HasDMA(const HasDMA & hs) : BaseDMA(hs)
				{
					...
				}
		对于赋值：
			派生类赋值运算符也可以显式调用基类赋值运算符完成对基类的成员的赋值。
				HasDMA & HasDMA::operator=(const HasDMA & hs)
				{
					...
					BaseDMA::operator=(hs);
					...
				}
		总结：
			当基类和派生类都采用动态内存分配时，上述三种函数都必须使用相应的基类方法来处理基类元素。
			对于析构函数，这是自动完成的。
			对于构造函数，通过在初始化成员列表中调用复制构造函数完成，如果不这样做，将自动调用基类的默认构造函数。
			对于赋值运算符，通过使用作用域解析运算符显示地调用基类的赋值运算符来完成。
	4.派生类使用基类的友元函数
		由于友元不是成员函数，因此不能使用作用域解析运算符来指出要是用哪个函数。这个问题的解决方法是使用强制类型转换，以使匹配原型时能够选择正确的函数。
			std::ostream & operator<<(std::ostream & os, const HasDMA & hs)		//基类中也存在类似的友元函数
			{
				os << (const BaseDMA &) hs;				//强制类型转换
				...
			}
13.8 类设计回顾
*/



#include <iostream>
#include "chapter13.h"
#include <cstring>

//class Port
Port::Port(const char* brand, const char* style, int bottles)
{
	m_brand = new char[std::strlen(brand) + 1];
	std::strcpy(m_brand, brand);
	std::strcpy(m_style, style);
	m_bottles = bottles;
}
Port::Port(const Port& p)
{
	m_brand = new char[std::strlen(p.m_brand) + 1];
	std::strcpy(m_brand, p.m_brand);
	std::strcpy(m_style, p.m_style);
	m_bottles = p.m_bottles;
}
Port::~Port()
{
	delete[] m_brand;
}
Port& Port::operator=(const Port& p)
{
	if (this == &p)
	{
		return *this;
	}
	delete[] m_brand;
	m_brand = new char[std::strlen(p.m_brand) + 1];
	std::strcpy(m_brand, p.m_brand);
	std::strcpy(m_style, p.m_style);
	m_bottles = p.m_bottles;
	return *this;
}
Port& Port::operator+=(int bottles)
{
	this->m_bottles += bottles;
	return *this;
}
Port& Port::operator-=(int bottles)
{
	if (this->m_bottles - bottles >= 0)
	{
		this->m_bottles -= bottles;
	}
	else
	{
		std::cout << "bottles less than 0" << std::endl;
	}
	return *this;
}
void Port::Show() const
{
	std::cout << "Brand: " << this->m_brand << std::endl;
	std::cout << "Kind: " << this->m_style << std::endl;
	std::cout << "Bottles: " << this->m_bottles << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Port& p)
{
	os << p.m_brand << ", " << p.m_style << ", " << p.m_bottles;
	return os;
}



//class VintagePoat
VintagePort::VintagePort() : Port()
{
	m_nickname = nullptr;
	m_year = 0;
}
VintagePort::VintagePort(const char* brand, int bottles, const char* nickname, int year) : Port(brand, "none", bottles)
{
	m_nickname = new char[std::strlen(nickname) + 1];
	std::strcpy(m_nickname, nickname);
	m_year = year;
}
VintagePort::~VintagePort()
{
	delete[] m_nickname;
}
VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if (this == &vp)
	{
		return *this;
	}
	Port::operator=(vp);
	delete[] m_nickname;
	m_nickname = new char[std::strlen(vp.m_nickname) + 1];
	std::strcpy(m_nickname, vp.m_nickname);
	m_year = vp.m_year;
	return *this;
}
void VintagePort::Show() const
{
	Port::Show();
	std::cout << "Nickname: " << m_nickname << std::endl;
	std::cout << "Year: " << m_year << std::endl;
}
std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
	operator<<(std::cout, Port(vp));
	os << ", " << vp.m_nickname << ", " << vp.m_year;
	return os;
}




void Chapter13::Run()
{
	//test Port
	Port bld = Port("Gallo", "tawny", 20);
	bld += 3;
	bld.Show();
	bld -= 2;
	std::cout << bld;
	std::cout << std::endl;
	Port bld2;
	bld2 = bld;
	bld2.Show();
	std::cout << bld2;
	//test VintagePort
	std::cout << std::endl << std::endl;
	VintagePort wsk = VintagePort("Wsk", 10, "WWW", 1980);
	wsk += 3;		//不同于wsk = wsk + 3;这个是+和=。如果本行改为wsk = (wsk += 3)，则错误。
	wsk.Show();
	wsk -= 2;
	std::cout << wsk;
	std::cout << std::endl;
	VintagePort wsk2;
	wsk2 = wsk;
	wsk2.Show();
	std::cout << wsk2;
}

