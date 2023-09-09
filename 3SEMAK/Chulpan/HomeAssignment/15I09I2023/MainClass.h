// Заголовочный файл
#pragma once
#include <iostream>

class RationalFraction {
private:
	int a, b;

public:
	RationalFraction();
	RationalFraction(int, int);
	void reduce();
	RationalFraction add(RationalFraction);
	void add2(RationalFraction);
	RationalFraction sub(RationalFraction);
	void sub2(RationalFraction);
	RationalFraction mult(RationalFraction);
	void mult2(RationalFraction);
	RationalFraction div(RationalFraction);
	void div2(RationalFraction);
	double value();
	bool equals(RationalFraction);
	int nuumberPart();
	int getDenominator();
	int getNominator();
};

class ComplexNumber {
private:
	double a, b;
public:
	ComplexNumber();
	ComplexNumber(double, double);
	ComplexNumber add(ComplexNumber);
	void add2(ComplexNumber);
	ComplexNumber sub(ComplexNumber);
	void sub2(ComplexNumber);
	ComplexNumber multNumber(double);
	void multNumber2(double);
	ComplexNumber mult(ComplexNumber);
	void mult2(ComplexNumber);
	ComplexNumber div(ComplexNumber);
	void div2(ComplexNumber);
	double length();
	double arg();
	ComplexNumber pow(double);
	bool equals(ComplexNumber);


};
