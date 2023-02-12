#ifndef CHAPTER07_H_
#define CHAPTER07_H_

class Chapter07
{
private:
	
public:
	double Add(double x, double y);
	double Calculate(double x, double y, double (*PFun)(double, double));
	double Mycalculate(double x, double y);
};

#endif