/*
6.1 if语句
	1.错误防范
		if (3 == value)	//这样写，避免少写=,难以检查错误
6.2 逻辑表达式
6.3 字符函数库cctype，须包含头文件<cctype>
6.4 ?: 运算符
6.5 switch语句
6.6 break 和 continue 语句
6.7 读取数字循环
	1.错误输入和EOF都将导致cin返回false，并且设置输入标记关闭输入。使用cin.clear()方法重置输入。
	2.处理非数子错误输入示例：
		while (!cin >> nums[i])
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Enter a number: ";
		}
6.8 简单文件输入/输出
	1.输出到文件
		包含头文件<fstream>
		创建一个ofstream对象
		将该ofstream对象同一个文件关联起来
		就像使用cout那样使用创建的ofstream对象
			ofstream fout;
			fout.open("test.txt");	//存在该文件便打开文件，并丢弃原始内容。不存在便新建文件。
			fout << "Hello world!";
			fout.close()；	//使用完文件应使用close()将其关闭
	2.从文件输入
		包含头文件<fstream>
		创建一个ifstream对象
		将该ifstream对象同一个文件关联起来
		就像使用cin那样使用创建的ifstream对象
			ifstream fin;
			fin.open("test.txt");
			if (!fin.is_open())				//文件未成功打开
			{
				exit(EXIT_FAILURE);			//exit()原型在头文件<cstdlib>中定义，EXIT_FAILURE也是
			}
			string str;					//char arr[100]
			getline(fin, str);			//fin.getline(arr, 100);
			while (fin.good())				//good()方法用于检查最后一次输入是否成功，输入后应立即应用这种测试
				表达式getline(fin, str)的结果为fin.而在需要bool值时，fin的结果为fin.good()，故可精简为
					while (getline(fin, str)) {...}

		
*/
#include <cctype>

//----------------------------------------------------------------//
/*
加入Benevolent Order of Programme后,在BOP大会上。人们便可以通过加入者的真实姓名、失衔或秘密BOP姓名来了解他(她)。请编写一个程序,可以使用真实姓名、头衔、秘密姓名或成员偏好来列出成员。编写该程序时,请使用下面的结构:								//ShowBOP()
	***使用new为结构分配内存
		//Benevolent Order of Programmers name structure 
		struct Bop { 
		char fullname[strsize];		// real name 
		char title[strsize];			// job title 
		char bopname[strsize];		// secret BOP name 
		int preference;				//0 - fullname, 1 - title, 2 - bopname 
		};
	***从文件"BOP.txt"中读取所有数据
	该程序创建一个由上述结构组成的小型数组,并将其初始化为适当的值。另外,该程序使用一个循环, 让用户在下面的选项中进行选择: 
		a. display by name			b. display by title 
		c. display by bopname		d. display by preference 
		q. quit 
	注意。“display by preference”并不意味着显示成员的偏好。而是意味着根据成员的偏好来出成员。
	例如,如果偏好号为1,则选择d将显示程序员的头衔。该程序的运行情况如下: 
		Benevolent Order of Programmers Report 
		a. display by name			b. display by title 
		c. display by bopname		d. display by preference 
		g. guit 
		Enter your choice: a 
		Wimp Macho 
		Raki Rhodes 
		Celia Laiter 
		Hoppy Hipman 
		Pat Hand 
		Next choice: d 
		Wimp Macho
		title Raki Rhodes
		bopname Celia Laiter
		Hoppy Hipman
		title Pat Hand
		Next choice: q
		Bye !

*/
#include "chapter06.h"
#include <fstream>
#include <string>
#include <iostream>


void Chapter06::FileTest()
{
	//write file 
	std::ofstream fout;
	std::ifstream fin;
	fout.open("test.txt");
	fout << "Hello world!";
	fout.close();
	//read file
	fin.open("test.txt");
	std::string str;
	if (!fin.is_open())
	{
		exit(EXIT_FAILURE);
	}
	while (std::getline(fin, str));
	std::cout << str;
	fin.close();
}
void Chapter06::BOPMenu()
{
	std::cout << "a.display by name" << "\t\t" << "b.display by title" << std::endl;
	std::cout << "c.display by bopname" << "\t\t" << "d.display by preference" << std::endl;
	std::cout << "q.quit" << std::endl;
}
void Chapter06::ShowContent(char choice, const int nums)
{
	Bop* pBOP = new Bop[nums];
	std::fstream fin;
	fin.open(".\\01CPrimerPlus_exercises\\chapter06分支语句和逻辑运算\\BOP.txt");
	if (!fin.is_open())
	{
		//std::cout << "failed open.";
		exit(EXIT_FAILURE);
	}
	//else
	//{
	//	std::cout << "open!!!";
	//}
	for (int i = 0; i < nums; i++)
	{
		fin.getline(pBOP[i].fullname, STR_SIZE).getline(pBOP[i].title, STR_SIZE);	//将下面两句合成一句
		//fin.getline(pBOP[i].fullname, STR_SIZE);
		//fin.getline(pBOP[i].title, STR_SIZE);
		std::getline(fin, pBOP[i].bopname);
		(fin >> pBOP[i].preference).get();		//使用get()读取数字后的换行符，防止读取空行关闭输入流
	}

	switch (choice)
	{
	case 'a':
		for (int i = 0; i < nums; i++)
		{
			std::cout << pBOP[i].fullname << std::endl;
		}
		break;
	case 'b':
		for (int i = 0; i < nums; i++)
		{
			std::cout << pBOP[i].title << std::endl;
		}
		break;
	case 'c':
		for (int i = 0; i < nums; i++)
		{
			std::cout << pBOP[i].bopname << std::endl;
		}
		break;
	case 'd':
		for (int i = 0; i < nums; i++)
		{
			switch (pBOP[i].preference)
			{
			case 0:
				std::cout << pBOP[i].fullname << std::endl;
				break;
			case 1:
				std::cout << pBOP[i].title << std::endl;
				break;
			case 2:
				std::cout << pBOP[i].bopname << std::endl;
				break;
			default:
				break;
			}
		}
		break;
	default:
		break;
	}
	fin.close();
	delete [] pBOP;
}
void Chapter06::ShowBOP()
{
	const int BOP_NUMS = 5;
	BOPMenu();
	std::cout << "Enter your choice: ";
	char choice;
	(std::cin >> choice).get();
	ShowContent(choice, BOP_NUMS);

}


