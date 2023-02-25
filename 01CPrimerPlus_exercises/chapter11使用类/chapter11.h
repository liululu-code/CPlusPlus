#ifndef CHAPTER_H_
#define CHAPTER_H_

#include <iostream>

class Chapter11
{
private:
	double m_real;
	double m_imaginary;
public:
	Chapter11();
	Chapter11(double real, double imaginary);
	void Run();
	//operator overloading
	Chapter11 operator+(const Chapter11& complexValue) const;
	Chapter11 operator-(const Chapter11& complexValue) const;
	Chapter11 operator*(const Chapter11& complexValue) const;
	Chapter11 operator*(double x) const;

	//friends
	friend Chapter11 operator*(double x, const Chapter11& complexValue);
	friend Chapter11 operator~(const Chapter11& complexValue);
	friend std::istream& operator>>(std::istream& is, Chapter11& complexValue);
	friend std::ostream& operator<<(std::ostream& os, const Chapter11& complexValue);

};

#endif
