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
		while ((ch = cin.get()) != EOF) {...};
		cin.clear()������������
	4.


*/