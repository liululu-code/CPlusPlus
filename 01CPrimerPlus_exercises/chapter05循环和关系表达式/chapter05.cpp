/*
5.1 forѭ��
	1.ͨ����cout����ʾboolֵ֮ǰ������ת��Ϊint����cout.setf(ios::boolalpha)��������������һ����ǣ��ñ������cout��ʾtrue or false��������1 or 0��
	2.ͨ��������һ��constֵ����ʾ������Ԫ�صĸ����Ǹ��ð취��
	3.�����ú�˳���
		�����ã�������ʽʱ��ĳЩ�����������޸ġ�
		˳��㣺����ִ�й����е�һ���㣬�������֮ǰ�����и����ö��Ѿ�������
			�κ������ı��ʽĩβ����һ��˳��㡣
		��C++11�ĵ��У�����ʹ��˳��㣬��Ϊ��������������۶��߳�ִ�С�ȡ����֮��ʹ�����˳�򡱡�
5.2 whileѭ��
	1.��ʱ�������غ���
		�����ͷ�ļ�<ctime>�����ж����˷��ų���CLOCKS_PER_SEC����ÿ���Ӱ�����ϵͳʱ�䵥λ����
		��д�ӳ٣�
			clock_t delay = second * CLOCKS_PER_SEC;
			clock_t start = clock();
			while (clock() - start < delay);
	2.��������
		#define CHAR char  //��ʽһ�����Ƽ�
		typedef char CHAR;	//��ʽ�����Ƽ���
			ͨ�ø�ʽ��typedef typeName aliasName;	//��������aliasNameΪtypeName���ͣ�Ȼ����ǰ�����typedef
			�磺typedef char * chPointer;	//chPointerΪchar*���ͱ���
5.3 do whileѭ��
5.4 ���ڷ�Χ��forѭ����C++11��
	1.����ѭ��һ�㲻����ʹ�ã���Ҫ����ģ�������ࡣ
		double prices[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
		for (double x : prices)	//��������Ԫ�أ����ı�����ֵ
			cout << x << endl;
		for (double &x : prices)	//�������ͣ��ı�����ֵ
			x *= 0.8;
		���ɽ�ϳ�ʼ���б�ʹ��
		for (int x : { 3, 5, 2, 7, 6 })
			cout << x << " ";
5.5 ѭ�����ı�����
	1.cin�ڶ�ȡ��������ʱ�������Կո�ͻ��з���
	2.��Ҫ��ȡ�ո��Ʊ���У���ʹ��cin.get(ch)		//cin.getline(str).get()��  getline()��ȡһ�У��ڶ���get()��ȡ���з�
	3.�ļ�β���
		��⵽�ļ�β��cin����λ��eofbit ��failbit��������Ϊ1.
		����ͨ����Ա����eof()�鿴eofbit�Ƿ����ã����򷵻�true�����򷵻�false��	//cin.eof()
		���eofbit or failbit������Ϊ1����fail()����true��
		while (cin.fail() == false) {...};
		while (!cin.fail()) {...};
		while (cin) {...};	//����������ַ�ʽ��ͨ�ã���Ϊ�����Լ�⵽����ʧ��ԭ������̹��ϡ�
		while ((ch = cin.get()) != EOF) {...};	//cin.get()ͨ������EOFָ�������ļ�β,cin.get(ch)ͨ������falseָ�������ļ�β
		cin.clear()������������
5.6 ѭ��Ƕ�׺Ͷ�ά����
*/
/*
7.���һ����Ϊcar�Ľṹ,�����洢�����й���������Ϣ:������(�洢���ַ������sring�����е��ַ���)���������(����)����дһ������,���û�ѯ���ж��������������,����ʹ��new������һ������Ӧ������car�ṹ��ɵĶ�̬���顣������,������ʾ�û�����ÿ������������(�����ɶ���������)�������Ϣ����ע��,����Ҫ�ر�С��,��Ϊ���������ȡ��ֵ���ַ���(�μ���4��)�����, ������ʾÿ���ṹ�����ݡ��ó���������������:																//ShowCar()
		How many cars do you wish to catalog? 2 
		Car #1: Please enter the make: Hudson Hornet 
		Please enter the year made: 1952 
		Car #2: Please enter the make: Kaiser 
		Please enter the year made: 1951 
		Here is your collection: 
		1952 Hudson Hornet 
		1951 Kaiser 
8.��дһ������,��ʹ��һ��char�����ѭ����ÿ�ζ�ȡһ������,ֱ���û�����doneΪֹ�����, �ó���ָ���û������˶��ٸ�����(������done����)�������Ǹó�����������: 
		Enter words (to stop, type the word done) : anteater birthday category dumpster envy finagle geometry done for sure 
		You entered a total of 7 words.
	��Ӧ�ڳ����а���ͷ�ļ�cstring��ʹ�ú���strcmp()�����бȽϲ��ԡ�				//ShowTotalNum()
*/
#include <iostream>
#include <cstring>
#include "chapter05.h"

void Chapter05::ShowCar()
{
	int num;
	const int CAR_NAME_SIZE = 30;
	std::cout << "How many cars do you wish to catalog? ";
	(std::cin >> num).get();
	Car* pArr = new Car[num];
	for (int i = 1; i <= num; i++)
	{
		std::cout << "Car #" << i << ": Please enter the make: ";
		std::getline(std::cin, pArr[i - 1].manufacturer);
		std::cout << "Please enter the year made: ";
		(std::cin >> pArr[i - 1].productionYear).get();
	}
	std::cout << "Here is your collection :" << std::endl;
	for (int i = 1; i <= num; i++)
	{
		std::cout << pArr[i - 1].productionYear << " " << pArr->manufacturer << std::endl;
	}
}
void Chapter05::ShowTotalNum()
{
	const int WORD_NUM = 20;
	const int ALPHA_NUM = 20;
	char arr[WORD_NUM][ALPHA_NUM];
	int totalNum = 0;
	std::cout << "Enter words (to stop, type the word done): ";
	for (int i = 0; i < WORD_NUM; i++)
	{
		std::cin >> arr[i];
		if (!strcmp(arr[i], "done"))
		{
			break;
		}
		totalNum++;
	}
	std::cout << "You entered a total of " << totalNum << " words.";
}
