// файл реализации
#include "MainClass.h"
#include <cmath>

RationalFraction::RationalFraction()
{
	a = 0;
	b = 1;
}

RationalFraction::RationalFraction(int arg1, int arg2)
{
	a = arg1;
	b = arg2;
}

void RationalFraction::reduce()
{
	if (a == b) {
		a = 1;
		b = 1;
		exit;
	}

	int MIN = (a > b) ? a : b;	// наименьшее из чисел
	bool MINisA = (MIN == a) ? true : false;	// числитель меньше знаминателя?
	int MAX = a + b - MIN;	// наибольшее из чисел

	for (int i = 2; i <= MIN; i++)
	{
		if ((MIN % i == 0) && (MAX % i == 0))	// есть общий делитель
		{
			MIN /= i;
			MAX /= i;
		}
	}
	if (MINisA)
	{
		a = MIN;
		b = MAX;
	}
	else
	{
		b = MIN;
		a = MAX;
	}

}

RationalFraction RationalFraction::add(RationalFraction f)
{
	RationalFraction res;
	
	if (b == f.b)
	{// у дробей одинаковый знаменатель
		res.b = b;
		res.a = a + f.a;
	}
	else 
	{// у дробей разный знаменатель
		res.a = a * f.b + f.a * b;
		res.b = b * f.b;
	}

	res.reduce();
	return res;
}

void RationalFraction::add2(RationalFraction f)
{
	if (b == f.b)
	{// у дробей одинаковый знаменатель
		a = a + f.a;
	}
	else
	{// у дробей разный знаменатель
		a = a * f.b + f.a * b;
		b = b * f.b;
	}
	this->reduce();
}

RationalFraction RationalFraction::sub(RationalFraction f)
{
	RationalFraction res;

	if (b == f.b)
	{// у дробей одинаковый знаменатель
		res.b = b;
		res.a = a - f.a;
	}
	else
	{// у дробей разный знаменатель
		res.a = a * f.b - f.a * b;
		res.b = b * f.b;
	}

	res.reduce();
	return res;
}

void RationalFraction::sub2(RationalFraction f)
{
	if (b == f.b)
	{// у дробей одинаковый знаменатель
		a = a - f.a;
	}
	else
	{// у дробей разный знаменатель
		a = a * f.b - f.a * b;
		b = b * f.b;
	}
	this->reduce();
}

RationalFraction RationalFraction::mult(RationalFraction f)
{
	RationalFraction res;
	res.a = a * f.a;
	res.b = b * f.b;
	res.reduce();
	return res;

}

void RationalFraction::mult2(RationalFraction f)
{
	a *= f.a;
	b *= f.b;
	this->reduce();
}

RationalFraction RationalFraction::div(RationalFraction f)
{
	RationalFraction res;
	res.a = a * f.b;
	res.b = b * f.a;

	res.reduce();
	return res;
}

void RationalFraction::div2(RationalFraction f)
{
	a *= f.b;
	b *= f.a;

	this->reduce();
}

double RationalFraction::value()
{
	return 1.0 * a / b;
}	

bool RationalFraction::equals(RationalFraction f)
{
	this->reduce();
	f.reduce();
	return ((a == f.a) && (b == f.b));
}

int RationalFraction::getDenominator()
{
	return b;
}

int RationalFraction::getNominator()
{
	return a;
}



ComplexNumber::ComplexNumber()
{
	a = 0;
	b = 0;
}

ComplexNumber::ComplexNumber(double arg1, double arg2)
{
	a = arg1;
	b = arg2;
}

ComplexNumber ComplexNumber::add(ComplexNumber c)
{
	ComplexNumber res;
	res.a = a + c.a;
	res.b = b + c.b;
	return res;
}

void ComplexNumber::add2(ComplexNumber c)
{
	a += c.a;
	b += c.b;
}

ComplexNumber ComplexNumber::sub(ComplexNumber c)
{
	ComplexNumber res;
	res.a = a - c.a;
	res.b = b - c.b;
	return res;
}

void ComplexNumber::sub2(ComplexNumber c)
{
	a -= c.a;
	b -= c.b;
}

ComplexNumber ComplexNumber::multNumber(double t)
{
	ComplexNumber res;
	res.a = a * t;
	res.b = b * t;
	return res;
}

void ComplexNumber::multNumber2(double t)
{
	a *= t;
	b *= t;
}

ComplexNumber ComplexNumber::mult(ComplexNumber z)
{
	ComplexNumber res;
	res.a = a * z.a - b * z.b;
	res.b = a * z.b + z.a * b;
	return res;
}

void ComplexNumber::mult2(ComplexNumber z)
{
	a = a * z.a - b * z.b;
	b = a * z.b + z.a * b;
}

ComplexNumber ComplexNumber::div(ComplexNumber z)
{
	ComplexNumber res;
	double c = z.a;
	double d = z.b;
	res.a = (a * c + b*d) / (c*c + d*d);
	res.b = (b*c - a*d) / (c*c + d*d);
	return res;
}

void ComplexNumber::div2(ComplexNumber z)
{
	double c = z.a;
	double d = z.b;
	a = (a * c + b * d) / (c * c + d * d);
	b = (b * c - a * d) / (c * c + d * d);
}

double ComplexNumber::length() 
{
	return sqrt(a * a + b * b);
}

double ComplexNumber::arg()
{
	return atan(b / a);
}

ComplexNumber ComplexNumber::pow(double t)
{
	ComplexNumber res;
	double r = this->length();
	double p = this->arg();
	res.a = std::pow(r, t) * std::cos(t * p);
	res.b = std::pow(r, t) * std::sin(t * p);
}

bool ComplexNumber::equals(ComplexNumber z)
{
	return ((a == z.a) && (b == z.b));
}
