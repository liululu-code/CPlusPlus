#ifndef CHAPTER13_H_
#define CHAPTER13_H_


#include <iostream>

class Port
{
private:
	enum {STYLE_SIZE = 20};
	char* m_brand;
	char m_style[STYLE_SIZE];
	int m_bottles;
public:
	Port(const char* brand = "none", const char* style = "none", int bottles = 0);
	Port(const Port& p);
	virtual ~Port();
	Port& operator=(const Port& p);
	Port& operator+=(int bottles);
	Port& operator-=(int bottles);
	int BottleCount() const { return m_bottles; }
	virtual void Show() const;
	friend std::ostream& operator<<(std::ostream& os, const Port& p);
};

class VintagePort : public Port
{
private:
	char* m_nickname;
	int m_year;
public:
	VintagePort();
	VintagePort(const char* brand, int bottles, const char* nickname, int year);
	virtual ~VintagePort();
	VintagePort& operator=(const VintagePort& vp);
	virtual void Show() const;
	friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
};


class Chapter13
{
private:
	;
public:
	void Run();
};



#endif