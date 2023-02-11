/*
5.1 for循环
	1.通常，cout在显示bool值之前将它们转换为int，但cout.setf(ios::boolalpha)函数调用设置了一个标记，该标记命令cout显示true or false，而不是1 or 0。
	2.通常，定义一个const值来表示数组中元素的个数是个好办法。
	3.副作用和顺序点
		副作用：计算表达式时对某些东西进行了修改。
		顺序点：程序执行过程中的一个点，在这个点之前，所有副作用都已经评估。
			任何完整的表达式末尾都是一个顺序点。
		在C++11文档中，不再使用顺序点，因为这个概念难以讨论多线程执行。取而代之，使用术语“顺序”。
5.2 while循环
	1.与时间控制相关函数
		须包含头文件<ctime>，其中定义了符号常量CLOCKS_PER_SEC，即每秒钟包含的系统时间单位数。
		编写延迟：
			clock_t delay = second * CLOCKS_PER_SEC;
			clock_t start = clock();
			while (clock() - start < delay);
	2.创建别名
		#define CHAR char  //方式一，不推荐
		typedef char CHAR;	//方式二，推荐。
			通用格式：typedef typeName aliasName;	//即先声明aliasName为typeName类型，然后在前面加上typedef
			如：typedef char * chPointer;	//chPointer为char*类型别名
5.3 do while循环
5.4 基于范围的for循环（C++11）
	1.这种循环一般不这样使用，主要用于模板容器类。
		double prices[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
		for (double x : prices)	//遍历数组元素，不改变数组值
			cout << x << endl;
		for (double &x : prices)	//引用类型，改变数组值
			x *= 0.8;
		还可结合初始化列表使用
		for (int x : { 3, 5, 2, 7, 6 })
			cout << x << " ";
5.5 循环和文本输入
	1.cin在读取基本类型时，将忽略空格和换行符。
	2.若要读取空格，制表或换行，可使用cin.get(ch)		//cin.getline(str).get()，  getline()读取一行，第二个get()读取换行符
	3.文件尾检测
		检测到文件尾后，cin将两位（eofbit 和failbit）都设置为1.
		可以通过成员函数eof()查看eofbit是否被设置，是则返回true，否则返回false。	//cin.eof()
		如果eofbit or failbit被设置为1，则fail()返回true。
		while (cin.fail() == false) {...};
		while (!cin.fail()) {...};
		while (cin) {...};	//这比上面两种方式更通用，因为它可以检测到其他失败原因，如磁盘故障。
		while ((ch = cin.get()) != EOF) {...};
		cin.clear()，重置输入流
	4.


*/