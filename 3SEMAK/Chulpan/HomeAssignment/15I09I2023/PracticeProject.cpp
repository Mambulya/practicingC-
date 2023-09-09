// файл выполнения
#include "MainClass.h"
#include <iostream>

int main()
{	
	RationalFraction f1(8,4);
	f1.reduce();

	RationalFraction f2(6,3);
	RationalFraction f3 = f1.div(f2);
	std::cout << f3.getNominator() << "/" << f3.getDenominator() << std::endl;
	std::cout << f2.value() << std::endl;
	std::cout << std::boolalpha << f1.equals(f2) << std::endl;



	ComplexNumber z1;
	ComplexNumber z2(2, 5);
	z1.add2(z2);
	ComplexNumber z3 = z2.sub(z2);
	std::cout << "length z2 = " << z2.length() << std::endl;
	ComplexNumber z4 = z1.pow(3);
	std::cout << z4.equals(z3);

	return 0;
}
