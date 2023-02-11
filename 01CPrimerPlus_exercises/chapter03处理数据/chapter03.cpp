/*
3.1 简单变量
	1.变量命名
		变量：首字母小写，其他大写（驼峰法）。全局变量可加前缀gl_
		常量：全字母大写，下划线分隔单词，MAX_SIZE
		函数：首字母全大写（帕斯卡命名法）
		类：
			类名：首字母全大写（帕斯卡命名法）
			类数据名：加前缀m_ ，避免数据成员与函数参数同名
	2.整形：short, int, long, long long, 和无符号整形：unsigned = unsigned int, unsigned char, unsigned short, unsigned long, unsigned long long,
		运算符：sizeof
		头文件：<climits>
			int value = 1;	//C initialization
			int value(1);	//alternative C++ syntax
			more:
				int value = {1};
				int value{1};
				int value{};	//set value to 0
			推荐声明变量时初始化，避免以后忘记赋值
		int是计算机最“自然”的长度，通常将类型定义为int。考虑到正负，取值范围，可移植性，可选择其他类型。
		C++支持10进制，8进制，16进制 字面值
			int value = 10;
			int value = 012;
			int value = 0xA;
	3.关于转义：在可以使用数字转义序列或符号转义序列（如\0x8和\b）时，使用符号序列。数字与特定编码方式（如ASCII码）相关，符号适用于任何编码方式，可读性更强。
	4.wchar_t, chat16_t, chat32_t;与Unicode,ISO10646		//以后再说
3.2 const限定符
	1.const相比#define的优点
		能指定类型
		能通过作用域规则限定作用域
		能应用于更复杂的类型
3.3 浮点数
	1.浮点类型float, double, long double
		头文件：<cfloat>
3.4 算数运算及运算中的类型自动转换

*/
#include <climits>	//整形范围头
#include <cfloat>	//浮点数范围
//---------------------------------------------------//
#include "chapter03.h"
#include <iostream>
/*
7.编写一个程序,要求用户按欧洲风格输入汽车的耗油量(每100公里消耗的汽油量(升)),然后将其转换为美国风格的耗油量——每加仑多少英里。
	注意,除了使用不同的单位计量外,美国方法(距离/ 燃料)与欧洲方法(燃料/距离)相反。
	100公里等于62.14英里,1加仑等于3.875升。因此,19mpg大约合12.41/100km,127mpg大约合8.71/100km。
*/
void Chapter03::HKPLToMPG()	//litre to gallon
{
	const double HKTOM = 62.14 / 100;
	const double LTOG = 3.875;
	double litreConsumption;
	std::cout << "Enter litre consumption per hundred kilometers: ";
	std::cin >> litreConsumption;
	double mile = 100 / litreConsumption * HKTOM * LTOG;
	std::cout << mile << "miles per gallon.";

}

