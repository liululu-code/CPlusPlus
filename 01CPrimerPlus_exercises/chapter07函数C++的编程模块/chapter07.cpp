/*
7.1 ��ϰ�����Ļ���֪ʶ
7.2 ���������Ͱ�ֵ����
7.3 ����������
	1.const��ָ�룺
		int val = 1;	//����
		const int CONSTANT = 2;		//����
		int * pVal1 = &val;	//valid������ָ���޸ı�����*pVal1��ֵΪint��
		//int * pConstant1 = &CONSTANT;	//invalid������
		const int * pVal2 = &val;		//valid��������ָ���޸ı�����*pVal2��ֵΪconst int�ͣ����ǿ����޸�pVal2��ָ�򣬼����� pVal2 = &constant;
		int * const PVAL_3 = &val;		//valid������ָ���޸ı������������޸�ָ��ָ��
		const int *pConstant2 = &CONSTANT;	//valid��������ָ���޸ģ��������ʣ���
		const int * const P_CONSTANT_3 = &CONSTANT;	//valid��������ָ���޸ı����������޸�ָ��ָ��
	2.Ҫ������ʹ��const
		���Ա�������������޸����ݶ����µı�̴���
		ʹ��constʹ�ú����ܹ�����const�ͷ�constʵ�Σ�����ֻ�ܽ��ܷ�constʵ�Ρ������������Ӧ��ָ���β�����Ϊָ��const��ָ�롣
7.4 �����Ͷ�ά����
	1.����ָ�룬ָ�����飬��ά������Ϊ������������
		int data[3][4] = {...};
		int total = Sum(data, 3);	//������������ζ�����
			//dataӦ��һ��ָ�룬ָ����4��int�ͱ���������
			int Sum(int (*arr)[4], int row);	//����ָ�룬ָ��ָ����4��int�ͱ���������
				//int *arr[4];		//ָ�����飬�������ĳ�Ա��4��ָ��int�ͱ�����ָ��
			int Sum(int arr[][4], int row);		//��һ�ֶ��巽ʽ���ɶ��Ը�ǿ������
7.5 ������C-����ַ���
	1.�����ַ������ַ��ı�׼��ʽ
		while (*str)
		{
			statements;
			str++;
		}
	2.����C����ַ����ĺ�����char * ReturnCStyle(...){...};
7.6 �����ͽṹ
7.7 ������string����
7.8 ������array����
	1.array�����ں����еĴ���
		std::array<double, 4> expenses;	//����array����
		Show(expenses);	//��ζ��庯���أ�
			void Show(std::array<double, 4> da);	//��ֵ����
			void Show(std::array<double, 4> * pDa);	//��ָ�봫��
				cin >> (*pDa)[1];	//��ָ�봫��ʱ�����÷�ʽ������������ͬ
7.9 �ݹ�
7.10 ����ָ��
	1.����֪ʶ
		��������Ϊ������ַ
		double (*pf)(int); //pf��Ϊ����ָ��
	2.ʹ�ú���ָ�봫�ݣ����ú���
		double Pam(int);	//fuction
		double (*PFun)(int);	//function pointer
		PFun = Pam;
		Pam(4); //�ȼ��� (*PFun)(4);	�ȼ���PFun(4);
		void Estimate(int lines, double (*PFun)(int));	//ʹ�ã�Estimate(4, Pam);	//ֱ�Ӵ��ݺ������Ϳ���
	3.����̽�ֺ���ָ��
		const double * Fun1(const double arr[], int n);
		const double * Fun2(const double [], int);
		const double * Fun3(const double *, int);
		
		const double * (*PFun1)(const double *, int) = Fun1;	//����ָ������ָ�벢��ʼ��ΪFun1����auto PFun1 = Fun1;
		//auto PFun2 = Fun2;	//�Զ������ƶ�
		const double * (*PArr[3])(const double *, int) = { Fun1, Fun2, Fun3 };		//����ӵ������ָ������ָ���ָ������
	4.ʹ��typedef��
		typedef const double * (*PFun)(const double *, int); //PFun now a type name
		PFun P1 = Fun1;	//P1 points to the Fun1() function
*/
//--------------------------------------------------//
/*
10.���һ����Ϊcalculate()�ĺ���,����������doubleֵ��һ��ָ������ָ��,����ָ��ĺ�����������double����,������һ��doublkeֵ��calculate()����������Ҳ��doublc,�����ر�ָ��ĺ���ʹ��calculate()������double��������õ���ֵ������,����add()�����Ķ�������: 
		double add(double x,double y)
		{
			return x + y; 
		}
	�����������еĺ������ý�����calculate()��25��104���ݸ�add()����,������add()�ķ���ֵ(12.9): 
		double q = calculate(2.5, 10.4, add); 
	���дһ������,��������������������������һ����add()���Ƶĺ������ó���ʹ��ѭ�������û��ɶԵ��������֡�����ÿ������,����ʹ��calculaie()������add()������һ�������ĺ�����������߰�����,���Գ��Դ���һ��ָ������,���е�ָ��ָ��add()��ʽ�ĺ���,����дһ��ѭ��,ʹ����Щָ��������calculate()������Щ��������ʾ:��������������ָ������ķ�ʽ,���а�������ָ��: 
		double (tpf[3])(double, double); 
	���Բ��������ʼ���﷨,������������Ϊ��ַ����ʼ�����������顣

*/
#include <iostream>
#include "chapter07.h"
//���´�������ʧ�ܣ����Ǵ������ֻ�Ǵ��ݺ�����ָ���޷�������ʹ�ã�����˵�Ҳ��ᣬ��main()��������������
double Chapter07::Add(double x, double y)
{
	return x + y;
}
double Chapter07::Calculate(double x, double y, double (*PFun)(double, double))
{
	std::cout << (*PFun)(x, y);
	return (*PFun)(x, y);
}
double Chapter07::Mycalculate(double x, double y)
{
	//double (*PFun)(double, double);
	//PFun = Add;		//error!  ������ָ��ָ�����Ա���������У���main()�����в���û������
	//return Calculate(x, y, PFun);
	return 1.0;	//�������뷵��һ��ֵ
}