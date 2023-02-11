// CPlusPlus.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "01CPrimerPlus_exercises/chapter02开始学习C++/chapter02.h"
#include "01CPrimerPlus_exercises/chapter03处理数据/chapter03.h"
#include "01CPrimerPlus_exercises/chapter04复合类型/chapter04.h"

void FunChapter02();
void FunChapter03();
void FunChapter04();

int main()
{
    //FunChapter02();
    //FunChapter03();
    FunChapter04();

    return 0;

}
void FunChapter04()
{
    Chapter04 myClass;
    //myClass.ShowSnack();
    //myClass.ShowArr();
    //myClass.PizzaIO();
    //myClass.PizzaIOUseNew();
    //myClass.ShowArrUseNew();
    myClass.ShowGrade();
}

void FunChapter03()
{
    Chapter03 myClass;
    myClass.HKPLToMPG();
}

void FunChapter02()
{
    Chapter02 myClass;
    myClass.CentigradeToFahrenheit();
}