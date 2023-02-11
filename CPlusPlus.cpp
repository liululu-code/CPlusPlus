// CPlusPlus.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "01CPrimerPlus_exercises/chapter02开始学习C++/chapter02.h"
#include "01CPrimerPlus_exercises/chapter03处理数据/chapter03.h"

void Fun_Chapter02();
void Fun_Chapter03();

int main()
{
    //Fun_Chapter02();
    //Fun_Chapter03();

}

void Fun_Chapter03()
{
    Chapter03 myClass;
    myClass.HKPLToMPG();
}

void Fun_Chapter02()
{
    Chapter02 myClass;
    myClass.CentigradeToFahrenheit();
}