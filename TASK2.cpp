#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;


double F(double x, int i) 
{	
	//описывает закон, по которому вычисляется Xi

	double first = ((pow((-1), i)) * x) / (1 + x + x * x);
	double second = sinh(x - 1);
	return first * second;
}


void TASK2(double x, int n) {

	//Итерирование последовательности
	//Семестр 2
	//Задание 1.3  I д)		II a)	 III a)		IV д)
	

	// Создаем последовательность x0, x1, x2, ...
	double* xs = new double[n];
	xs[0] = x;
	double r = 0;

	for (int i = 1; i < n; i++)
		xs[i] = F(xs[i - 1], i + 1);
		
	
	cout << "X collection:\n";
	for (int i = 0; i < n; i++)
		cout << xs[i] << "   ";

	// Преобразовывем коллекцию Х в коллекцию Y по правилу П
	sort(xs, xs + n);

	cout << "\n\nY collection:\n";

	for (int i = 0; i < n; i++) {
		cout << xs[i] << "   ";

		if (xs[i] > 0 && r == 0)
			r = xs[i];
	}
		
	if (r == 0)
		cout << "\no such numbers\n";
	else
		cout << "\n\nR = " << r;
}


int main() 
{   

	TASK2(4.2, 14);

	return 0;
}
