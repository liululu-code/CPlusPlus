/*
6.1 if���
	1.�������
		if (3 == value)	//����д��������д=,���Լ�����
6.2 �߼����ʽ
6.3 �ַ�������cctype�������ͷ�ļ�<cctype>
6.4 ?: �����
6.5 switch���
6.6 break �� continue ���
6.7 ��ȡ����ѭ��
	1.���������EOF��������cin����false���������������ǹر����롣ʹ��cin.clear()�����������롣
	2.��������Ӵ�������ʾ����
		while (!cin >> nums[i])
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Enter a number: ";
		}
6.8 ���ļ�����/���
	1.������ļ�
		����ͷ�ļ�<fstream>
		����һ��ofstream����
		����ofstream����ͬһ���ļ���������
		����ʹ��cout����ʹ�ô�����ofstream����
			ofstream fout;
			fout.open("test.txt");	//���ڸ��ļ�����ļ���������ԭʼ���ݡ������ڱ��½��ļ���
			fout << "Hello world!";
			fout.close()��	//ʹ�����ļ�Ӧʹ��close()����ر�
	2.���ļ�����
		����ͷ�ļ�<fstream>
		����һ��ifstream����
		����ifstream����ͬһ���ļ���������
		����ʹ��cin����ʹ�ô�����ifstream����
			ifstream fin;
			fin.open("test.txt");
			if (!fin.is_open())				//�ļ�δ�ɹ���
			{
				exit(EXIT_FAILURE);			//exit()ԭ����ͷ�ļ�<cstdlib>�ж��壬EXIT_FAILUREҲ��
			}
			string str;					//char arr[100]
			getline(fin, str);			//fin.getline(arr, 100);
			while (fin.good())				//good()�������ڼ�����һ�������Ƿ�ɹ��������Ӧ����Ӧ�����ֲ���
				���ʽgetline(fin, str)�Ľ��Ϊfin.������Ҫboolֵʱ��fin�Ľ��Ϊfin.good()���ʿɾ���Ϊ
					while (getline(fin, str)) {...}

		
*/
#include <cctype>

//----------------------------------------------------------------//
/*
����Benevolent Order of Programme��,��BOP����ϡ����Ǳ����ͨ�������ߵ���ʵ������ʧ�λ�����BOP�������˽���(��)�����дһ������,����ʹ����ʵ������ͷ�Ρ������������Աƫ�����г���Ա����д�ó���ʱ,��ʹ������Ľṹ:								//ShowBOP()
	***ʹ��newΪ�ṹ�����ڴ�
		//Benevolent Order of Programmers name structure 
		struct Bop { 
		char fullname[strsize];		// real name 
		char title[strsize];			// job title 
		char bopname[strsize];		// secret BOP name 
		int preference;				//0 - fullname, 1 - title, 2 - bopname 
		};
	***���ļ�"BOP.txt"�ж�ȡ��������
	�ó��򴴽�һ���������ṹ��ɵ�С������,�������ʼ��Ϊ�ʵ���ֵ������,�ó���ʹ��һ��ѭ��, ���û��������ѡ���н���ѡ��: 
		a. display by name			b. display by title 
		c. display by bopname		d. display by preference 
		q. quit 
	ע�⡣��display by preference��������ζ����ʾ��Ա��ƫ�á�������ζ�Ÿ��ݳ�Ա��ƫ��������Ա��
	����,���ƫ�ú�Ϊ1,��ѡ��d����ʾ����Ա��ͷ�Ρ��ó���������������: 
		Benevolent Order of Programmers Report 
		a. display by name			b. display by title 
		c. display by bopname		d. display by preference 
		g. guit 
		Enter your choice: a 
		Wimp Macho 
		Raki Rhodes 
		Celia Laiter 
		Hoppy Hipman 
		Pat Hand 
		Next choice: d 
		Wimp Macho
		title Raki Rhodes
		bopname Celia Laiter
		Hoppy Hipman
		title Pat Hand
		Next choice: q
		Bye !

*/
#include "chapter06.h"
#include <fstream>
#include <string>
#include <iostream>


void Chapter06::FileTest()
{
	//write file 
	std::ofstream fout;
	std::ifstream fin;
	fout.open("test.txt");
	fout << "Hello world!";
	fout.close();
	//read file
	fin.open("test.txt");
	std::string str;
	if (!fin.is_open())
	{
		exit(EXIT_FAILURE);
	}
	while (std::getline(fin, str));
	std::cout << str;
	fin.close();
}
void Chapter06::BOPMenu()
{
	std::cout << "a.display by name" << "\t\t" << "b.display by title" << std::endl;
	std::cout << "c.display by bopname" << "\t\t" << "d.display by preference" << std::endl;
	std::cout << "q.quit" << std::endl;
}
void Chapter06::ShowContent(char choice, const int nums)
{
	Bop* pBOP = new Bop[nums];
	std::fstream fin;
	fin.open(".\\01CPrimerPlus_exercises\\chapter06��֧�����߼�����\\BOP.txt");
	if (!fin.is_open())
	{
		//std::cout << "failed open.";
		exit(EXIT_FAILURE);
	}
	//else
	//{
	//	std::cout << "open!!!";
	//}
	for (int i = 0; i < nums; i++)
	{
		fin.getline(pBOP[i].fullname, STR_SIZE).getline(pBOP[i].title, STR_SIZE);	//����������ϳ�һ��
		//fin.getline(pBOP[i].fullname, STR_SIZE);
		//fin.getline(pBOP[i].title, STR_SIZE);
		std::getline(fin, pBOP[i].bopname);
		(fin >> pBOP[i].preference).get();		//ʹ��get()��ȡ���ֺ�Ļ��з�����ֹ��ȡ���йر�������
	}

	switch (choice)
	{
	case 'a':
		for (int i = 0; i < nums; i++)
		{
			std::cout << pBOP[i].fullname << std::endl;
		}
		break;
	case 'b':
		for (int i = 0; i < nums; i++)
		{
			std::cout << pBOP[i].title << std::endl;
		}
		break;
	case 'c':
		for (int i = 0; i < nums; i++)
		{
			std::cout << pBOP[i].bopname << std::endl;
		}
		break;
	case 'd':
		for (int i = 0; i < nums; i++)
		{
			switch (pBOP[i].preference)
			{
			case 0:
				std::cout << pBOP[i].fullname << std::endl;
				break;
			case 1:
				std::cout << pBOP[i].title << std::endl;
				break;
			case 2:
				std::cout << pBOP[i].bopname << std::endl;
				break;
			default:
				break;
			}
		}
		break;
	default:
		break;
	}
	fin.close();
	delete [] pBOP;
}
void Chapter06::ShowBOP()
{
	const int BOP_NUMS = 5;
	BOPMenu();
	std::cout << "Enter your choice: ";
	char choice;
	(std::cin >> choice).get();
	ShowContent(choice, BOP_NUMS);

}


