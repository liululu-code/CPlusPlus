/*
11.1 ���������
	1.Ҫ�������������Ҫʹ�ñ���Ϊ��������������⺯����ʽ
		operator op(argument-list)		//op must be valid C++ operator
11.2 ���������ʾ��
	1.ʹ����������غ���ʱ��Ӧ���ض��󡣶�����������Ҳ��һ�����������ÿ��ܵ��º�������ʱ���ö���ɾ�������ý�ָ��һ�������ڵĶ���
	2.������������صķ�ʽ�����֣�
		total = coding.operator+(fixing);		//total,coding and fixing are object
		total = coding + fixing;
		��������Ķ����ǵ��ö���������Ҳ�Ķ�������Ϊ���������ݵĶ���
		t4 = t3 + t2 + t1;		//t4 = t3.operator+(t2.operator+(t1));		//���ض��󣬿�����ô����

	3.��������
		���غ�������������һ�����������û���������ͣ���ֹ�û�Ϊ��׼�����������������֤���򲻳���
		ʹ�������ʱ������Υ��ԭ�еľ䷨�������粻�ܽ����������������������Ϊһ�����������������ͬ���������޸�����������ȼ���
		���ܴ����µ��������
		��������������������
			sizeof
			.			//��Ա�����
			.*			//��Աָ�������
			::			//��������������
			?:			//���������
			typeid		//һ��RTTI�����
			const_cast			//ǿ������ת�������
			dynamic_cast		//ǿ������ת�������
			reinterpret_cast	//ǿ������ת�������
			static_cast			//ǿ������ת�������
		����������ֻ��ͨ����Ա������������			//����ͨ����Ԫ������������������
			=
			()
			[]
			->
11.3 ��Ԫ			//��Ԫ��3�֣���Ԫ��������Ԫ�ࡢ��Ԫ��Ա����������ֻ������Ԫ����			
	1.��Ԫ��������ԭ��
		�������ض�Ԫ�����ʱ�������������������������������ͬһ����ʱ��ͨ����Ҫ��Ԫ������
			A = B * 3.2;	// A = B.operator*(3.2);
			A = 3.2 * B;	// error
		���������
			ʹ�÷ǳ�Ա������ת���� 
				A = operator*(3.2, B);
			����ԭ��
				Time operator*(double, const Time &);	//Time is a class
			���Ƿǳ�Ա�����޷��������˽�����ݣ�ֻ��ͨ������һ������ĺ���-��Ԫ�������ﵽĿ�ġ�
	2.������Ԫ����
		��ʽ��
			friend Time operator*(double m, const Time & t);		//declaration, must be included in class declaration
			Time operator*(double m, const Time & t) {...};		//definition
				//{ return t * m; }�� ��������ʱ�����Բ�����������Ϊ��Ԫ������������Ϊ��Ԫ�����ĺô��ǣ�������ʽ��Ϊ��ӿڵ���ɲ��֣�����Ժ���Ҫ����ֱ�ӷ���˽�����ݣ�ֱ���޸���Ԫ�������弴�ɣ��������޸�ԭ�͡�
		˵����
			������ԭ�ͷ����������У�����ԭ������ǰ���Ϲؼ���friend
			�������岻Ҫʹ�����޶�������Ϊ�����ǳ�Ա��������Ҫ�ڶ�����ʹ�ùؼ���friend
			�����Ԫ�����Ƿǳ�Ա����������ͨ����Ա����� . �����á�������Ȩ�޺ͳ�Ա������ͬ��
	3.����<<�����ʾ��
		1.cout ֮�����ܹ��Զ�ʶ����ֻ������ͣ�ԭ�������ostream�ࣨcout ��ostream���һ�����������а����˸��ֻ������͵�����operator<<()���塣Ҫʹcout �ܹ�ʶ��������ͣ��޸�ostream�ļ���һ�������������������ڱ�׼�ӿ����˷�ʱ�䣬���Ƽ���һ��ʹ����Ԫ�������Զ�������������������Ҳֻ��ʹ����Ԫ��������
		2. << ������
			���룺
				ostream & operator<<(ostream & os, const Time & t)
				{
					os << t.hours << " hours, " << t.minutes << " minutes";
					return os;
				}
			˵����
				����ʹ�������������˱�����Ӧ�������������Ԫ�����������ں���ֻ�ǽ�os���󵱳�һ�����壬��û��ֱ�ӷ���˽�����ݳ�Ա�����ֻ��Ҫ��Time�����Ԫ�Ϳ����ˡ�
11.4 �������������Ϊ��Ա�������Ƿǳ�Ա����
11.5 ��̸���أ�һ��ʸ����
11.6 ����Զ�ת����ǿ������ת��
	1.ֻ����һ�������Ĺ��캯�������˴Ӳ������͵������͵�ת�������ʹ�ùؼ���explicit�޶������ֹ��캯��������ֻ��������ʾת�������������������ģ������һ�������ṩĬ��ֵ��Ҳ�����Զ�ת����
		StoneWt myCat;
		myCat = 19.6;		//use StoneWt(double) to convert 19.6 to StoneWt
		explicit StoneWt(double n);		//�����Զ�ת��
	2.��������ʱ���ù��캯�������Զ�ת��
		������캯��������ʹ��explicit����ֻ��������ʽǿ������ת�������������һ����ʽת����
			��StoneWt�����ʼ��Ϊdoubleֵʱ��
			��double����StoneWt����ʱ��
			��doubleֵ���ݸ�����StoneWt��������ĺ���ʱ��
			����ֵ��StoneWt����ĺ�����ͼ����doubleֵʱ��
			��������£������������Ϳ���ת��Ϊdouble��ʱ��
		ת��ʱӦ��������ԣ�����int�ͼ���ת��Ϊdouble�ͣ�Ҳ��ת��Ϊlong�ͣ�������캯��ͬʱ����������ת���������
	3.ת������
		ֻ��ʹ��ת��������StoneWt����ת��Ϊdoubleֵ��ת���������û������ǿ������ת�������û�ж�����Ӧ��ת�������ͽ���ת���������������ɴ�����Ϣ��
		����ת��������
			operator typeName();		//typeName��Ҫת��������
			˵����
				ת�������������෽����
				ת����������ָ���������͡�
				ת�����������в�����
			ʾ����
				StoneWt::operator double() const
				{
					return pounds;				//pounds����˽�г�Ա��
				}
		���ඨ�������ֻ����ת������ʱ�����ܵ��¶����ԣ����³������Կ���ʹ����ʾǿ������ת����ָ��Ҫʹ���ĸ�ת��������
		�ṩ�Զ��ģ���ʽ��ת�����������ڵ������ǣ����û���ϣ������ת��ʱ��ת������Ҳ���ܽ���ת����
			�����������ת�����������Ϊ��ʾ�ģ�ʹ��explicit
				explicit operator double() const;		//reclaration
			���棺Ӧ����ʹ����ʽת��������ͨ�������ѡ����ڱ���ʾ�ص���ʱ�Ż�ִ�еĺ�����
		С���Զ�ת����������Ԫ���������������ͻ��
		��double����StoneWt����ӣ������ַ�ʽ
			һ���Զ�����ת��
				operator+(const StoneWt &, const StoneWt &);	//double convert to StoneWt
			�������ؼӷ������
				StoneWt operator+(double x);
				friend StoneWt operator+(double x, StoneWt & s);
			��һ�ַ���������̣�����Ա����С������Ļ���ҲС����ÿ��ת����Ҫ���ù��캯��������ʱ����ڴ濪����
			�ڶ��ַ������෴������Ա������һ�㣬�������ٶȸ��졣
			Ӧ���ʵ����Ҫѡ��ʹ�����ַ�ʽ��
*/
/*
7.����������������ɣ�ʵ�����ֺ��������֣�������һ����д��ʽ�ǣ���3.0��4.0�������У�3.0��ʵ�����֣�4.0���������֡�����a = (A, Bi), c = (C, Di)����������һЩ�������㡣
	�ӷ���a + c = (A + C, (B + D)i).
	������a - c = (A - C, (B - D)i).
	�˷���a * c = (A * C - B * D, (A * D + B * C)i).
	�˷���x * c = (x * C, x * Di).
	���~a = (A, -Bi).
	�붨��һ�������࣬�Ա�����ĳ����ܹ�ʹ�����������ȷ�Ľ����
		#include <iostream>
		using namespace std;
		#include "complex0.h"
		int main()
		{
			complex a(3.0, 4.0);
			complex c;
			cout << "Enter a complex number (q to quit): \n";
			while (cin >> c)
			{
				cout << "c is " << c << endl;
				cout << "complex conjugate is " << ~c << endl;
				cout << "a is " << a << endl;
				cout << "a + c is " << a + c << endl;
				cout << "a - c is " << a - c << endl;
				cout << "a * c is " << a * c << endl;
				cout << "2 * c is " << 2 * c << endl;
				cout << "Enter a complex number (q to quit): \n";

			}
			cout << "Done!\n";
			return 0;
		}
	ע�⣬�������������<< and >> ����׼C++ʹ��ͷ�ļ�complex�ṩ�˱����ʾ�����㷺�ĸ���֧�֣����Ӧ���Զ����ͷ�ļ�����Ϊcomplex0.h�����ⷢ����ͻ��Ӧ������ʹ��const��
	�����Ǹó�������������
		Enter a complex number (q to quit):
		real: 10
		imaginary: 12
		c is (10, 12i);
		complex conjugate is (10, -12i)
		a is (3, 4i)
		a + c is (13, 16i)
		a - c is (-7, -8i)
		a * c is (-18, 76i)
		2 * c is (20, 24i)
		Enter a complex number (q to quit):
		real: q
		Done!
	��ע�⣬�������غ�cin >> c ����ʾ�û�����ʵ�����������֡�

*/

#include <iostream>
#include "chapter11.h"

void Chapter11::Run()
{
	using std::cout;
	using std::cin;
	using std::endl;
	Chapter11 a(3.0, 4.0);
	Chapter11 c;
	cout << "Enter a complex number (q to quit): \n";
	while (cin >> c)
	{
		cout << "c is " << c << endl;
		cout << "complex conjugate is " << ~c << endl;
		cout << "a is " << a << endl;
		cout << "a + c is " << a + c << endl;
		cout << "a - c is " << a - c << endl;
		cout << "a * c is " << a * c << endl;
		cout << "2 * c is " << 2 * c << endl;
		cout << "Enter a complex number (q to quit): \n";

	}
	cout << "Done!\n";
}

Chapter11::Chapter11()
{
	
}
Chapter11::Chapter11(double real, double imaginary)
{
	m_real = real;
	m_imaginary = imaginary;
}
//operator overloading
Chapter11 Chapter11::operator+(const Chapter11& complexValue) const
{
	return Chapter11(this->m_real + complexValue.m_real, this->m_imaginary + complexValue.m_imaginary);
}
Chapter11 Chapter11::operator-(const Chapter11& complexValue) const
{
	return Chapter11(this->m_real - complexValue.m_real, this->m_imaginary - complexValue.m_imaginary);

}
Chapter11 Chapter11::operator*(const Chapter11& complexValue) const
{
	return Chapter11(this->m_real * complexValue.m_real - this->m_imaginary * complexValue.m_imaginary, this->m_real * complexValue.m_imaginary + this->m_imaginary * complexValue.m_real);
}
Chapter11 Chapter11::operator*(double x) const
{
	return Chapter11(this->m_real * x, this->m_imaginary * x);
}

//friends
Chapter11 operator*(double x, const Chapter11& complexValue)
{
	return Chapter11(x * complexValue.m_real, x * complexValue.m_imaginary);
}
Chapter11 operator~(const Chapter11& complexValue)
{
	Chapter11 temp(complexValue.m_real, -complexValue.m_imaginary);
	return temp;
}
std::istream& operator>>(std::istream& is, Chapter11& complexValue)
{
	std::cout << "real: ";
	std::cin >> complexValue.m_real;
	if (!std::cin.good())				//�����벻Ϊ����ʱ��std::cin.good����false�������������
	{
		return is;
	}
	std::cout << "imaginary: ";
	std::cin >> complexValue.m_imaginary;
	return is;
}
std::ostream& operator<<(std::ostream& os, const Chapter11& complexValue)
{
	std::cout << "(" << complexValue.m_real << ", " << complexValue.m_imaginary << "i)";
	return os;
}