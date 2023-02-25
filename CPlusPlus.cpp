// CPlusPlus.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include "01CPrimerPlus_exercises/chapter02开始学习C++/chapter02.h"
#include "01CPrimerPlus_exercises/chapter03处理数据/chapter03.h"
#include "01CPrimerPlus_exercises/chapter04复合类型/chapter04.h"
#include "01CPrimerPlus_exercises/chapter05循环和关系表达式/chapter05.h"
#include "01CPrimerPlus_exercises/chapter06分支语句和逻辑运算/chapter06.h"
#include "01CPrimerPlus_exercises/chapter07函数C++的编程模块/chapter07.h"
#include "01CPrimerPlus_exercises/chapter08函数探幽/chapter08.h"
#include "01CPrimerPlus_exercises/chapter09内存模型与名称空间/chapter09.h"
#include "01CPrimerPlus_exercises/chapter10对象和类/chapter10.h"
#include "01CPrimerPlus_exercises/chapter11使用类/chapter11.h"

void FunChapter02();
void FunChapter03();
void FunChapter04();
void FunChapter05();
void FunChapter06();
void FunChapter07();
void FunChapter08();
void FunChapter09();
void FunChapter10();
void FunChapter11();
void FunChapter12();
//void FunChapter13();
//void FunChapter14();
//void FunChapter15();
//void FunChapter16();
//void FunChapter17();
//void FunChapter18();


int main()
{

    //FunChapter02();
    //FunChapter03();
    //FunChapter04();
    //FunChapter05();
    //FunChapter06();
    //FunChapter07();   //error
    //FunChapter08();     //不完整
    //FunChapter09();
    //FunChapter10();
    //FunChapter11();
    FunChapter12();
    //FunChapter13();
    //FunChapter14();
    //FunChapter15();
    //FunChapter16();
    //FunChapter17();
    //FunChapter18();

    return 0;

}
//void FunChapter18()
//{
//    Chapter18 myClass;
//
//}
//void FunChapter17()
//{
//    Chapter17 myClass;
//
//}
//void FunChapter16()
//{
//    Chapter16 myClass;
//
//}
//void FunChapter15()
//{
//    Chapter15 myClass;
//
//}
//void FunChapter14()
//{
//    Chapter14 myClass;
//
//}
//void FunChapter13()
//{
//    Chapter13 myClass;
//
//}
void FunChapter12()
{
    Chapter12 myClass;

}
void FunChapter11()
{
    Chapter11 myClass;
    myClass.Run();
}
void FunChapter10()
{
    Chapter10 myClass;
    myClass.Show();
}
void FunChapter09()
{
    Chapter09 myClass;
    myClass.TestNew();
}
void FunChapter08()
{
    Chapter08 myClass;
    myClass.ShowMax();

}
void FunChapter07()
{
    //Chapter07 myClass;
    //myClass.Mycalculate(3.5, 2.5);

}

void FunChapter06()
{
    Chapter06 myClass;
    myClass.ShowBOP();
}

void FunChapter05()
{
    Chapter05 myClass;
    myClass.ShowCar();
    myClass.ShowTotalNum();
}
void FunChapter04()
{
    Chapter04 myClass;
    //myClass.ShowSnack();
    //myClass.ShowArr();
    myClass.PizzaIO();
    //myClass.PizzaIOUseNew();
    //myClass.ShowArrUseNew();
    //myClass.ShowGrade();
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