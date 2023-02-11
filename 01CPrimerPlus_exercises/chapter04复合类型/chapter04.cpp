/*
4.1 数组
4.2 字符串
	1.确定存储字符所需最短数组时，别忘了将结尾空字符计算在内。
	2.字符串输入
		cin: cin使用空白（空格，制表符，换行符）确定字符串结束位置，这意味着cin在输入时只能读取一个单词。
		面向行的输入
			cin.getline(name, ARRAYSIZE);	//最多保存ARRAYSIZE - 1个字符，读取指定数目字符或遇到换行符停止读取
			cin.get(name, ARRAYSIZE);	////最多保存ARRAYSIZE - 1个字符
			区别：getline()丢弃换行符。get()将换行符保留在输入序列中，要读取掉换行符可以这样使用：cin.get(name, ATTAYSIZE).get();
				get()相对于getline()更仔细，可通过下一个字符是不是换行符判断是否成功读取了整行。但getline()使用更简单一些。
		空行和其他问题
			当读取空行时,get()（不是getline()）读取空行后，会设置失效位，并关闭后面的输入，但可以用cin.clear()恢复。
			当输入字符数过多时，get()和getline()会把余下的字符留在输入队列中，getline()还会设置失效位，关闭后面输入。
		混合输入字符串和数字：先输入数字后，输入队列中会留下换行符，解决方法如下
			cin >> num;	//input num
			cin.get();	//or cin.get(ch);
			//or
			(cin >> num).get();
4.3 String类简介
	1.

*/