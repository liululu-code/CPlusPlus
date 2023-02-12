#ifndef CHAPTER06_H_
#define CHAPTER06_H_
#include <string>

const int STR_SIZE = 50;

struct Bop {
	char fullname[STR_SIZE];		// real name 
	char title[STR_SIZE];			// job title 
	std::string bopname;		// secret BOP name 
	int preference;				//0 - fullname, 1 - title, 2 - bopname 
};

class Chapter06
{
private:
	void BOPMenu();
	void ShowContent(const char choice, const int nums);
public:
	;
	void FileTest();
	void ShowBOP();
};




#endif