/*
4.1 ����
4.2 �ַ���
	1.ȷ���洢�ַ������������ʱ�������˽���β���ַ��������ڡ�
	2.�ַ�������
		cin: cinʹ�ÿհף��ո��Ʊ�������з���ȷ���ַ�������λ�ã�����ζ��cin������ʱֻ�ܶ�ȡһ�����ʡ�
		�����е�����
			cin.getline(name, ARRAYSIZE);	//��ౣ��ARRAYSIZE - 1���ַ�����ȡָ����Ŀ�ַ����������з�ֹͣ��ȡ
			cin.get(name, ARRAYSIZE);	////��ౣ��ARRAYSIZE - 1���ַ�
			����getline()�������з���get()�����з����������������У�Ҫ��ȡ�����з���������ʹ�ã�cin.get(name, ATTAYSIZE).get();
				get()�����getline()����ϸ����ͨ����һ���ַ��ǲ��ǻ��з��ж��Ƿ�ɹ���ȡ�����С���getline()ʹ�ø���һЩ��
		���к���������
			����ȡ����ʱ,get()������getline()����ȡ���к󣬻�����ʧЧλ�����رպ�������룬��������cin.clear()�ָ���
			�������ַ�������ʱ��get()��getline()������µ��ַ�������������У�getline()��������ʧЧλ���رպ������롣
		��������ַ��������֣����������ֺ���������л����»��з��������������
			cin >> num;	//input num
			cin.get();	//or cin.get(ch);
			//or
			(cin >> num).get();
4.3 String����
	1.Ҫʹ��String�࣬�������ͷ�ļ�<string>��ͬʱstring��λ�����ƿռ�std�У�����ʹ��using����ָ���std::string����������
	2.str3 = str1 + str2;	//valid������������󣬿����ز�������������˵һ�㶼��������ʹ�á�
	3.�����ַ�������
		int len1 = str1.size(); //obtain length of str1
		int len2 = strlen(charr1); //botain length of charr1
	4.��һ�������ȡ��������
		cin.getline(charr, 20);	//valid
		getline(cin, str);	//valid
	5.������ʽ���ַ�������ֵ
		����wchar_t, char16_t, char32_t, C++�ֱ�ʹ��ǰ׺L,u,U��ʾ���磺
			wchar_t title[] = L"Happy New Year!";
			char16_t name[] = u"Happy New Year!";
			char32_t cat[] = U"Happy New Year!";
		��һ��������ԭʼ�ַ���
			cout << R"(Jim "King" Tutt uses "\n" instead of endl.)" << '\n';	//display Jim "King" Tutt uses "\n" instead of endl.
			cout << R"+*("(Who wouldn't?)", she whispered.)+*" << endl;		//display "(Who wouldn't?)", she whispered.     �Զ����ʽ"+*( �� )*+" �м�ɻ���������
4.4 �ṹ
	1.C++�����ڶ���ṹ����ʱʡ�Թؼ���struct
		struct Student stu1;	//C-style
		Student stu2;		//valid in C++
	2.�ṹ�е�λ�ֶ�
		struct Register
		{
			unsigned int SN : 4;	//4 bits for SN value
			undigned int : 4;		//4 bits unused,ʹ��û�����Ƶ��ֶ��ṩ���
			bool goodIn : 1;
			bool goodTorgle : 1;
		}
		λ����һ�����ڵͼ�����У�һ����˵�������ð�λ������������ַ�ʽ��
4.5 ������
	1.������һ��������ʡ�ڴ棬������Ƕ��ʽ�����ϵͳ�����С�
4.6 ö��
4.7 ָ������ɴ洢�ռ�
	1.ʹ��new�������ڴ�
		typeName * pointerName = new typeName;
		new�ӱ���Ϊ�ѣ�heap�������ɴ洢����free store�����ڴ��з����ڴ档
	2.ʹ��delete�ͷ��ڴ�
		int * ps = new int;
		delete ps;	//�ͷ�psָ����ڴ棬psָ����Ȼ����ָ���µ��ڴ�
		�ɶ�ʹ��new �� delete����Ҫ�ͷ�ͬһ���ڴ�����Ρ�
	3.ʹ��new������̬����
		typeName * pointerName = new typeName [num_elements];
		delete pointerName [];
4.8 ָ�룬�����ָ������
	1.ʹ��new������̬�ṹ
4.9 ���顢�ṹ��ָ����϶���
4.10 ��������Ʒ
	1.ģ����vector
		Ҫʹ��vector���󣬱������ͷ�ļ�<vector>
		vectorλ�����ƿռ�std�У��������ʹ��using����ָ�using��������std::vector
		ģ��ʹ�ò�ͬ���﷨��ָ�����洢�����ͣ�ʹ�ò�ͬ���﷨��ָ��Ԫ����Ŀ
		vector<typeName> vt(n_elem);	//����һ����Ϊvt��vector����������n_elem������ΪtypeName��Ԫ��
	2.ģ����array��C++11��
		��vector���ƣ������ͷ�ļ�<array>��λ�����ƿռ�std��
		array���󳤶ȹ̶�����̬�ڴ���䣬Ч����������ͬ����vector�ߡ�
		array<typeName, n_elem> arr;	//systax, n_elem�����Ǳ���
	3.����
		vector��̬�����ڴ棬array��̬�����ڴ棬��������飬�����Ƕ��󣬾��ж���Ӧ�е����ԡ�
	


*/
#include <string>	//make string class available
#include <cstring>	//C-style string library
#include <vector>
#include <array>
//-----------------------------------------------------//
#include <iostream>
#include "chapter04.h"

/*
5.�ṹCandvBar����3����Ա����һ����Ա�洢���ǿ��Ʒ��:�ڶ�����Ա�洢�ǿ������(������С��);��������Ա�洢���ǿ�Ŀ�·�ﺬ��(����)�����дһ������,��������ṹ,����һ����Ϊsnack �� CandyBar����,�������Ա�ֱ��ʼ��Ϊ��Mocha Munch����23��350����ʼ��Ӧ������snack ʱ���С����,������ʾsnack���������ݡ�//ShowSnack()
6.�ṹ CandyBar����3����Ա,������ϰ5��ʾ�����дһ������,����һ������3��Ԫ�ص�CandyBar����,�������ǳ�ʼ��Ϊ��ѡ���ֵ,Ȼ����ʾÿ���ṹ�����ݡ�	//ShowArr()
7.William Wingate���±������������񡣶���ÿ��������,������Ҫ��¼������Ϣ: 
	��������˾������,�����ж��������ɡ�
	��������ֱ���� 
	��������������
  �����һ���ܹ��洢��Щ��Ϣ�Ľṹ,����дһ��ʹ�����ֽṹ�����ĳ���,���������û�����������Ϣ,Ȼ����ʾ��Щ��Ϣ����ʹ��cin(�����ķ���)��cout��	//PizzaIO()
8.��ɱ����ϰ7,��ʹ��new��Ϊ�ṹ�����ڴ�,����������һ���ṹ����������,�ó��������������������˾����֮ǰ�����������ֱ����	//PizzaIOUseNew()
9.��ɱ����ϰ6,��ʹ��new����̬��������,����������һ������3��Ԫ�ص�CandyBar���顣	//ShowArrUseNew()
10.��дһ������,���û���������40���ܵĳɼ�(�����Ը��,Ҳ�����û�����40���ܵĳɼ�), ����ʾ������ƽ���ɼ�����ʹ��һ��array�������洢����(�����������֧��array��,��ʹ������)��	//ShowGrade()

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
