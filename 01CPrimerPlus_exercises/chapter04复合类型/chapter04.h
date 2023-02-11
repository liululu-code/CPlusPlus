#ifndef CHAPTER04_H_
#define CHAPTER04_H_
#include <string>
#include <iostream>
#include <array>

struct CandyBar
{
	std::string brand;
	double weight;
	int calorie;
};
struct Pizza
{
	std::string brand;
	double diameter;
	double weight;
};
class Chapter04
{
private:
	void ShowPizza(Pizza& pz);
public:
	void ShowSnack();
	void ShowSnack(CandyBar &s);
	void ShowArr();
	void PizzaIO();
	void PizzaIOUseNew();
	void ShowArrUseNew();
	void ShowGrade();
};

#endif