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

double f(int j)
{
	return (j + cos(j * j - 0.8));
}

double g(int i)
{
	return (3.7 - log(1 + i * i));
}

double H(double a, double b, double c)
{
	return 2 * a - b - c;
}


void TASK1(int m, int n)
{
	//Вычисление строки таблицы
	//Семестр 1
	//Задание 1.12  I б) г)		II a)	 III a)	


	// f(x) = x + cos(x^2 - 0,8)
	// g(x) = 3,7 - In(1 + x^2)

	double** table = new double* [m];

	// Создаем таблицу
	for (int i = 0; i < m; i++)
		table[i] = new double[n];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			if (i == 0)
				table[i][j] = f(j);
			else if ((j == 0) && (i != 0))
				table[i][j] = g(i);
			else
				table[i][j] = H(table[i - 1][j], table[i - 1][j - 1], table[i][j - 1]);
		}
	}

	cout << "\nthe whole table:\n";

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << table[i][j] << "     ";
		}cout << endl;
	}


	cout << "\nm-line:\n";
	for (int i = 0; i < n; i++)
	{
		cout << table[m - 1][i] << "   ";
	}

}

int main() 
{

	TASK1(10, 5);
	//TASK2(4.2, 14);

	return 0;
}
