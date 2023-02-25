/*
11.1 运算符重载
	1.要重载运算符，需要使用被称为运算符函数的特殊函数形式
		operator op(argument-list)		//op must be valid C++ operator
11.2 运算符重载示例
	1.使用运算符重载函数时，应返回对象。对于其他函数也是一样。返回引用可能导致函数结束时引用对象被删除，引用将指向一个不存在的对象。
	2.调用运算符重载的方式，两种：
		total = coding.operator+(fixing);		//total,coding and fixing are object
		total = coding + fixing;
		运算符左侧的对象是调用对象，运算符右侧的对象是作为参数被传递的对象。
		t4 = t3 + t2 + t1;		//t4 = t3.operator+(t2.operator+(t1));		//返回对象，可以这么做。

	3.重载限制
		重载后的运算符必须有一个操作数是用户定义的类型，防止用户为标准类型重载运算符，保证程序不出错。
		使用运算符时，不能违背原有的句法规则。例如不能将两个操作数的运算符重载为一个操作数的运算符。同样，不能修改运算符的优先级。
		不能创建新的运算符。
		不能重载下面的运算符：
			sizeof
			.			//成员运算符
			.*			//成员指针运算符
			::			//作用域解析运算符
			?:			//条件运算符
			typeid		//一个RTTI运算符
			const_cast			//强制类型转换运算符
			dynamic_cast		//强制类型转换运算符
			reinterpret_cast	//强制类型转换运算符
			static_cast			//强制类型转换运算符
		下面的运算符只能通过成员函数进行重载			//不能通过友元函数，还有其他的吗
			=
			()
			[]
			->
11.3 友元			//友元有3种，友元函数、友元类、友元成员函数。本章只介绍友元函数			
	1.友元函数产生原因
		在类重载二元运算符时，当重载运算符函数的两个参数不是同一类型时，通常需要友元函数。
			A = B * 3.2;	// A = B.operator*(3.2);
			A = 3.2 * B;	// error
		解决方案：
			使用非成员函数，转换成 
				A = operator*(3.2, B);
			函数原型
				Time operator*(double, const Time &);	//Time is a class
			但是非成员函数无法访问类的私有数据，只能通过定义一种特殊的函数-友元函数，达到目的。
	2.创建友元函数
		格式：
			friend Time operator*(double m, const Time & t);		//declaration, must be included in class declaration
			Time operator*(double m, const Time & t) {...};		//definition
				//{ return t * m; }， 这样定义时，可以不将函数声明为友元函数。但声明为友元函数的好处是，它将正式作为类接口的组成部分，如果以后需要函数直接访问私有数据，直接修改友元函数定义即可，而不必修改原型。
		说明：
			将函数原型放在类声明中，并在原型声明前加上关键字friend
			函数定义不要使用类限定符，因为它不是成员函数。不要在定义中使用关键字friend
			类的友元函数是非成员函数，不能通过成员运算符 . 来调用。但访问权限和成员函数相同。
	3.重载<<运算符示例
		1.cout 之所以能够自动识别各种基本类型，原因就在于ostream类（cout 是ostream类的一个对象）声明中包含了各种基本类型的重载operator<<()定义。要使cout 能够识别基本类型，修改ostream文件是一个方法，但这样做会在标准接口上浪费时间，不推荐。一般使用友元函数对自定义的类重载运算符。（也只能使用友元函数）。
		2. << 的重载
			代码：
				ostream & operator<<(ostream & os, const Time & t)
				{
					os << t.hours << " hours, " << t.minutes << " minutes";
					return os;
				}
			说明：
				函数使用两个类对象，因此表面上应当是两个类的友元函数，但由于函数只是将os对象当成一个整体，并没有直接访问私有数据成员，因此只需要是Time类的友元就可以了。
11.4 重载运算符：作为成员函数还是非成员函数
11.5 再谈重载：一个矢量类
11.6 类的自动转换和强制类型转换
	1.只接受一个参数的构造函数定义了从参数类型到类类型的转换。如果使用关键字explicit限定了这种构造函数，则它只能用于显示转换。（对于两个参数的，如果后一个参数提供默认值，也可以自动转换）
		StoneWt myCat;
		myCat = 19.6;		//use StoneWt(double) to convert 19.6 to StoneWt
		explicit StoneWt(double n);		//不能自动转换
	2.编译器何时利用构造函数进行自动转换
		如果构造函数声明中使了explicit，则只能用于显式强制类型转换，否则可用于一下隐式转换：
			将StoneWt对象初始化为double值时。
			将double赋给StoneWt对象时。
			将double值传递给接受StoneWt对象参数的函数时。
			返回值是StoneWt对象的函数试图返回double值时。
			上述情况下，其他内置类型可以转换为double型时。
		转换时应避免二义性，比如int型即可转换为double型，也可转换为long型，如果构造函数同时包含这两种转换，会出错。
	3.转换函数
		只能使用转换函数将StoneWt对象转换为double值，转换函数是用户定义的强制类型转换。如果没有定义相应的转换函数就进行转换，编译器将生成错误信息。
		创建转换函数：
			operator typeName();		//typeName是要转换的类型
			说明：
				转换函数必须是类方法。
				转换函数不能指定返回类型。
				转换函数不能有参数。
			示例：
				StoneWt::operator double() const
				{
					return pounds;				//pounds是类私有成员。
				}
		当类定义了两种或更多转换函数时，可能导致二义性，导致出错，但仍可以使用显示强制类型转换来指出要使用哪个转换函数。
		提供自动的，隐式的转换函数所存在的问题是：当用户不希望进行转换时，转换函数也可能进行转换。
			解决方案：将转换运算符声明为显示的，使用explicit
				explicit operator double() const;		//reclaration
			警告：应谨慎使用隐式转换函数，通常，最好选择仅在被显示地调用时才会执行的函数。
		小心自动转化函数和友元函数重载运算符冲突。
		将double量和StoneWt量相加，有两种方式
			一：自动类型转换
				operator+(const StoneWt &, const StoneWt &);	//double convert to StoneWt
			二：重载加法运算符
				StoneWt operator+(double x);
				friend StoneWt operator+(double x, StoneWt & s);
			第一种方法程序更短，程序员工作小，出错的机会也小，但每次转换都要调用构造函数，增加时间和内存开销。
			第二种方法正相反，程序员工作多一点，但运行速度更快。
			应结合实际需要选择使用哪种方式。
*/
/*
7.复数有两个部分组成，实数部分和虚数部分，复数的一种书写方式是：（3.0，4.0），其中，3.0是实数部分，4.0是虚数部分。假设a = (A, Bi), c = (C, Di)，则下面是一些复数运算。
	加法：a + c = (A + C, (B + D)i).
	减法：a - c = (A - C, (B - D)i).
	乘法：a * c = (A * C - B * D, (A * D + B * C)i).
	乘法：x * c = (x * C, x * Di).
	共轭：~a = (A, -Bi).
	请定义一个复数类，以便下面的程序能够使用它来获得正确的结果。
		#include <iostream>
		using namespace std;
		#include "complex0.h"
		int main()
		{
			complex a(3.0, 4.0);
			complex c;
			cout << "Enter a complex number (q to quit): \n";
			while (cin >> c)
			{
				cout << "c is " << c << endl;
				cout << "complex conjugate is " << ~c << endl;
				cout << "a is " << a << endl;
				cout << "a + c is " << a + c << endl;
				cout << "a - c is " << a - c << endl;
				cout << "a * c is " << a * c << endl;
				cout << "2 * c is " << 2 * c << endl;
				cout << "Enter a complex number (q to quit): \n";

			}
			cout << "Done!\n";
			return 0;
		}
	注意，必须重载运算符<< and >> 。标准C++使用头文件complex提供了比这个示例更广泛的复数支持，因此应将自定义的头文件命名为complex0.h，以免发生冲突，应尽可能使用const。
	下面是该程序的运行情况：
		Enter a complex number (q to quit):
		real: 10
		imaginary: 12
		c is (10, 12i);
		complex conjugate is (10, -12i)
		a is (3, 4i)
		a + c is (13, 16i)
		a - c is (-7, -8i)
		a * c is (-18, 76i)
		2 * c is (20, 24i)
		Enter a complex number (q to quit):
		real: q
		Done!
	请注意，经过重载后，cin >> c 将提示用户输入实数和虚数部分。

*/

#include <iostream>
#include "chapter11.h"

void Chapter11::Run()
{
	using std::cout;
	using std::cin;
	using std::endl;
	Chapter11 a(3.0, 4.0);
	Chapter11 c;
	cout << "Enter a complex number (q to quit): \n";
	while (cin >> c)
	{
		cout << "c is " << c << endl;
		cout << "complex conjugate is " << ~c << endl;
		cout << "a is " << a << endl;
		cout << "a + c is " << a + c << endl;
		cout << "a - c is " << a - c << endl;
		cout << "a * c is " << a * c << endl;
		cout << "2 * c is " << 2 * c << endl;
		cout << "Enter a complex number (q to quit): \n";

	}
	cout << "Done!\n";
}

Chapter11::Chapter11()
{
	
}
Chapter11::Chapter11(double real, double imaginary)
{
	m_real = real;
	m_imaginary = imaginary;
}
//operator overloading
Chapter11 Chapter11::operator+(const Chapter11& complexValue) const
{
	return Chapter11(this->m_real + complexValue.m_real, this->m_imaginary + complexValue.m_imaginary);
}
Chapter11 Chapter11::operator-(const Chapter11& complexValue) const
{
	return Chapter11(this->m_real - complexValue.m_real, this->m_imaginary - complexValue.m_imaginary);

}
Chapter11 Chapter11::operator*(const Chapter11& complexValue) const
{
	return Chapter11(this->m_real * complexValue.m_real - this->m_imaginary * complexValue.m_imaginary, this->m_real * complexValue.m_imaginary + this->m_imaginary * complexValue.m_real);
}
Chapter11 Chapter11::operator*(double x) const
{
	return Chapter11(this->m_real * x, this->m_imaginary * x);
}

//friends
Chapter11 operator*(double x, const Chapter11& complexValue)
{
	return Chapter11(x * complexValue.m_real, x * complexValue.m_imaginary);
}
Chapter11 operator~(const Chapter11& complexValue)
{
	Chapter11 temp(complexValue.m_real, -complexValue.m_imaginary);
	return temp;
}
std::istream& operator>>(std::istream& is, Chapter11& complexValue)
{
	std::cout << "real: ";
	std::cin >> complexValue.m_real;
	if (!std::cin.good())				//当输入不为数字时，std::cin.good返回false，并阻断输入流
	{
		return is;
	}
	std::cout << "imaginary: ";
	std::cin >> complexValue.m_imaginary;
	return is;
}
std::ostream& operator<<(std::ostream& os, const Chapter11& complexValue)
{
	std::cout << "(" << complexValue.m_real << ", " << complexValue.m_imaginary << "i)";
	return os;
}