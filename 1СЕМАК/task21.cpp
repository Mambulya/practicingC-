#include <iostream>
using namespace std;

double find_min(double y[30]) {
	double MIN = 1000000000000000000; 
	for (int i = 0; i < 30; i++) {
		if (y[i] < MIN)
			MIN = y[i];
	}
	return MIN;
}

double scolar_product(double x[30], double y[30]) {
	double r = 0;
	for (int i = 0; i < 30; i++) {
		r = r + (x[i] * y[i]);
	}
	return r;
}

int main() 
{
	double a[30], b[30], c[30];
	double x;

	// заполняем вектора
	for (int j = 0; j < 30; j++) {
		cin >> x;
		a[j] = x;
	}

	for (int j = 0; j < 30; j++) {
		cin >> x;
		b[j] = x;
	}

	for (int j = 0; j < 30; j++) {
		cin >> x;
		c[j] = x;
	}


	// определяем а
	if (find_min(a) < find_min(b)) 
	{
		if (find_min(a) < find_min(c))
			cout <<  scolar_product(a, a) - scolar_product(b, c);
		else
			cout << scolar_product(c, c) - scolar_product(b, a);
	}
	else 
	{
		if (find_min(b) < find_min(c))
			cout << scolar_product(b, b) - scolar_product(a, c);
		else
			cout << scolar_product(c, c) - scolar_product(a, c);
	}


	return 0;
