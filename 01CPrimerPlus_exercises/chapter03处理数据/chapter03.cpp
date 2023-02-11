/*
3.1 �򵥱���
	1.��������
		����������ĸСд��������д���շ巨����ȫ�ֱ����ɼ�ǰ׺gl_
		������ȫ��ĸ��д���»��߷ָ����ʣ�MAX_SIZE
		����������ĸȫ��д����˹����������
		�ࣺ
			����������ĸȫ��д����˹����������
			������������ǰ׺m_ ���������ݳ�Ա�뺯������ͬ��
	2.���Σ�short, int, long, long long, ���޷������Σ�unsigned = unsigned int, unsigned char, unsigned short, unsigned long, unsigned long long,
		�������sizeof
		ͷ�ļ���<climits>
			int value = 1;	//C initialization
			int value(1);	//alternative C++ syntax
			more:
				int value = {1};
				int value{1};
				int value{};	//set value to 0
			�Ƽ���������ʱ��ʼ���������Ժ����Ǹ�ֵ
		int�Ǽ�������Ȼ���ĳ��ȣ�ͨ�������Ͷ���Ϊint�����ǵ�������ȡֵ��Χ������ֲ�ԣ���ѡ���������͡�
		C++֧��10���ƣ�8���ƣ�16���� ����ֵ
			int value = 10;
			int value = 012;
			int value = 0xA;
	3.����ת�壺�ڿ���ʹ������ת�����л����ת�����У���\0x8��\b��ʱ��ʹ�÷������С��������ض����뷽ʽ����ASCII�룩��أ������������κα��뷽ʽ���ɶ��Ը�ǿ��
	4.wchar_t, chat16_t, chat32_t;��Unicode,ISO10646		//�Ժ���˵
3.2 const�޶���
	1.const���#define���ŵ�
		��ָ������
		��ͨ������������޶�������
		��Ӧ���ڸ����ӵ�����
3.3 ������
	1.��������float, double, long double
		ͷ�ļ���<cfloat>
3.4 �������㼰�����е������Զ�ת��

*/
#include <climits>	//���η�Χͷ
#include <cfloat>	//��������Χ
//---------------------------------------------------//
#include "chapter03.h"
#include <iostream>
/*
7.��дһ������,Ҫ���û���ŷ�޷�����������ĺ�����(ÿ100�������ĵ�������(��)),Ȼ����ת��Ϊ�������ĺ���������ÿ���ض���Ӣ�
	ע��,����ʹ�ò�ͬ�ĵ�λ������,��������(����/ ȼ��)��ŷ�޷���(ȼ��/����)�෴��
	100�������62.14Ӣ��,1���ص���3.875�������,19mpg��Լ��12.41/100km,127mpg��Լ��8.71/100km��
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

