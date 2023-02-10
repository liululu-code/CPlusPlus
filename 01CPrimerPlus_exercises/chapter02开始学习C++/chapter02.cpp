/*
2.1 进入C++
	1.C++注释：//
	2.C++头文件名与C头文件名格式略有区别
	3.名称空间：using编译指令使得名称空间内的所有名称都可用，这是一种偷懒的做法，在大型项目存在潜在问题，更好的做法是使用哪个通过using声明哪个
	4.C++代码风格：
		#每个函数的开始花括号和结束花括号各占一行
		#与函数名称相关的圆括号周围没有空白 
2.2 C++语句
	1.对于声明变量，C++的做法是尽可能在首次使用前声明它
	2.cout 和 cin
2.3
2.4 函数
	1.main()函数返回值通常由操作系统接收，约定返回 0 表示运行成功，非零表示失败。
*/

#include "chapter02.h"
double Chapter02::CentigradeToFahrenheit(double degreeCentigrade)
{
	return degreeCentigrade * 1.8 + 32;
}