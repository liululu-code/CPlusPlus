/*
4.1 数组
4.2 字符串
	1.确定存储字符所需最短数组时，别忘了将结尾空字符计算在内。
	2.字符串输入
		cin: cin使用空白（空格，制表符，换行符）确定字符串结束位置，这意味着cin在输入时只能读取一个单词。
		面向行的输入
			cin.getline(name, ARRAYSIZE);	//最多保存ARRAYSIZE - 1个字符，读取指定数目字符或遇到换行符停止读取
			cin.get(name, ARRAYSIZE);	////最多保存ARRAYSIZE - 1个字符
			区别：getline()丢弃换行符。get()将换行符保留在输入序列中，要读取掉换行符可以这样使用：cin.get(name, ATTAYSIZE).get();
				get()相对于getline()更仔细，可通过下一个字符是不是换行符判断是否成功读取了整行。但getline()使用更简单一些。
		空行和其他问题
			当读取空行时,get()（不是getline()）读取空行后，会设置失效位，并关闭后面的输入，但可以用cin.clear()恢复。
			当输入字符数过多时，get()和getline()会把余下的字符留在输入队列中，getline()还会设置失效位，关闭后面输入。
		混合输入字符串和数字：先输入数字后，输入队列中会留下换行符，解决方法如下
			cin >> num;	//input num
			cin.get();	//or cin.get(ch);
			//or
			(cin >> num).get();
4.3 String类简介
	1.要使用String类，必须包含头文件<string>，同时string类位于名称空间std中，必须使用using编译指令或std::string来引用它。
	2.str3 = str1 + str2;	//valid，对于面向对象，可重载操作符的语言来说一般都可以这样使用。
	3.计算字符串长度
		int len1 = str1.size(); //obtain length of str1
		int len2 = strlen(charr1); //botain length of charr1
	4.将一行输入读取到数组中
		cin.getline(charr, 20);	//valid
		getline(cin, str);	//valid
	5.其它形式的字符串字面值
		对于wchar_t, char16_t, char32_t, C++分别使用前缀L,u,U表示，如：
			wchar_t title[] = L"Happy New Year!";
			char16_t name[] = u"Happy New Year!";
			char32_t cat[] = U"Happy New Year!";
		另一种类型是原始字符串
			cout << R"(Jim "King" Tutt uses "\n" instead of endl.)" << '\n';	//display Jim "King" Tutt uses "\n" instead of endl.
			cout << R"+*("(Who wouldn't?)", she whispered.)+*" << endl;		//display "(Who wouldn't?)", she whispered.     自定义格式"+*( 与 )*+" 中间可换其他符号
4.4 结构
	1.C++允许在定义结构变量时省略关键字struct
		struct Student stu1;	//C-style
		Student stu2;		//valid in C++
	2.结构中的位字段
		struct Register
		{
			unsigned int SN : 4;	//4 bits for SN value
			undigned int : 4;		//4 bits unused,使用没有名称的字段提供间距
			bool goodIn : 1;
			bool goodTorgle : 1;
		}
		位运算一般用于低级编程中，一般来说，可以用按位运算符代替这种方式。
4.5 共用体
	1.共用体一般用来节省内存，常用于嵌入式或操作系统开发中。
4.6 枚举
4.7 指针和自由存储空间
	1.使用new来分配内存
		typeName * pointerName = new typeName;
		new从被称为堆（heap）或自由存储区（free store）的内存中分配内存。
	2.使用delete释放内存
		int * ps = new int;
		delete ps;	//释放ps指向的内存，ps指针依然可以指向新的内存
		成对使用new 和 delete，不要释放同一个内存块两次。
	3.使用new创建动态数组
		typeName * pointerName = new typeName [num_elements];
		delete pointerName [];
4.8 指针，数组和指针算数
	1.使用new创建动态结构
4.9 数组、结构和指针组合定义
4.10 数组的替代品
	1.模板类vector
		要使用vector对象，必须包含头文件<vector>
		vector位于名称空间std中，因此您可使用using编译指令，using声明，或std::vector
		模板使用不同的语法来指出它存储的类型，使用不同的语法来指定元素数目
		vector<typeName> vt(n_elem);	//创建一个名为vt的vector对象，它包含n_elem个类型为typeName的元素
	2.模板类array（C++11）
		与vector相似，须包含头文件<array>，位于名称空间std中
		array对象长度固定，静态内存分配，效率与数组相同，比vector高。
		array<typeName, n_elem> arr;	//systax, n_elem不能是变量
	3.区别：
		vector动态分配内存，array静态分配内存，相对于数组，他俩是对象，具有对象应有的属性。
	


*/
#include <string>	//make string class available
#include <cstring>	//C-style string library
#include <vector>
#include <array>
//-----------------------------------------------------//
#include <iostream>
#include "chapter04.h"

/*
5.结构CandvBar包含3个成员。第一个成员存储了糖块的品牌:第二个成员存储糖块的重量(可以有小数);第三个成员存储了糖块的卡路里含量(整数)。请编写一个程序,声明这个结构,创建一个名为snack 的 CandyBar变量,并将其成员分别初始化为“Mocha Munch”、23和350。初始化应在声明snack 时进行。最后,程序显示snack变量的内容。//ShowSnack()
6.结构 CandyBar包含3个成员,如编程练习5所示。请编写一个程序,创建一个包含3个元素的CandyBar数组,并将它们初始化为所选择的值,然后显示每个结构的内容。	//ShowArr()
7.William Wingate从事比萨饼分析服务。对于每个披萨饼,他都需要记录下列信息: 
	披萨饼公司的名称,可以有多个单词组成。
	披萨饼的直径。 
	披萨饼的重量。
  请设计一个能够存储这些信息的结构,并编写一个使用这种结构变量的程序,程序将请求用户输入上述信息,然后显示这些信息。请使用cin(或它的方法)和cout。	//PizzaIO()
8.完成编程练习7,但使用new来为结构分配内存,而不是声明一个结构变量。另外,让程序在请求输入比萨饼公司名称之前输入比萨饼的直径。	//PizzaIOUseNew()
9.完成编程练习6,但使用new来动态分配数组,而不是声明一个包含3个元素的CandyBar数组。	//ShowArrUseNew()
10.编写一个程序,让用户输入三次40码跑的成绩(如果您愿意,也可让用户输入40米跑的成绩), 并显示次数和平均成绩。请使用一个array对象来存储数据(如果编译器不支持array类,请使用数组)。	//ShowGrade()

*/
void Chapter04::ShowSnack()
{
	CandyBar snack = { "Mocha Munch", 2.3, 350 };
	std::cout << "brand: " << snack.brand << "\nweight: " << snack.weight << "\ncalorie: " << snack.calorie;
}
void Chapter04::ShowSnack(CandyBar& s)
{
	std::cout << "\nbrand: " << s.brand << "\nweight: " << s.weight << "\ncalorie: " << s.calorie;
}
void Chapter04::ShowArr()
{
	CandyBar arr[3] = {
		{"First", 1.1, 100},
		{"Second", 2.2, 200},
		{"Third", 3.3, 300},
	};
	ShowSnack(arr[0]);
	ShowSnack(arr[1]);
	ShowSnack(arr[2]);

}
void Chapter04::ShowPizza(Pizza& pz)
{
	std::cout << "brand: " << pz.brand << "\ndiameter: " << pz.diameter << "\nweight: " << pz.weight;
}
void Chapter04::PizzaIO()
{
	Pizza pz;
	std::cout << "Enter pizza brand: ";
	std::cin >> pz.brand;
	std::cout << "Enter pizza diameter: ";
	std::cin >> pz.diameter;
	std::cout << "Enter pizza weight: ";
	std::cin >> pz.weight;
	ShowPizza(pz);
}
void Chapter04::PizzaIOUseNew()
{
	Pizza* pz = new Pizza;
	std::cout << "Enter pizza diameter: ";
	std::cin >> pz->diameter;
	std::cout << "Enter pizza brand: ";
	std::cin >> pz->brand;
	std::cout << "Enter pizza weight: ";
	std::cin >> pz->weight;
	ShowPizza(*pz);
	delete pz;
}
void Chapter04::ShowArrUseNew()
{
	CandyBar* arr = new CandyBar[3]{
		{"First", 1.1, 100},
		{"Second", 2.2, 200},
		{"Third", 3.3, 300},
	};
	ShowSnack(arr[0]);
	ShowSnack(arr[1]);
	ShowSnack(arr[2]);
}
void Chapter04::ShowGrade()
{
	const int TIMES = 3;
	std::array<double, 3> grades;
	double average, sum = 0;
	for (int i = 0; i < TIMES; i++)
	{
		std::cout << "Enter grade " << i + 1 << ": ";
		std::cin >> grades[i];
		sum += grades[i];
	}
	average = sum / TIMES;
	std::cout << "input " << TIMES << " times" << std::endl;
	std::cout << "average grade is " << average;
}
