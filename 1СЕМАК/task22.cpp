#include <iostream>
using namespace std;

bool get_diagonal(double**a, double**b) {
	double sum1 = 0; // для а
	double sum2 = 0; // для b

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				sum1 = sum1 + a[i][j];
				sum2 = sum2 + b[i][j];
				break;
			}
		}
	}
	// is it a?
	if (sum1 < sum2)
		return true;
	else 
		return false;
	
}

double** get_square(double** a) {

	// a * a

	// создаем вспомогательную матрицу
	double** c = new double* [3];
	for (int i = 0; i < 3; i++)
		c[i] = new double[3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c[i][j] = 0;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				c[i][j] += a[i][k] * a[k][j];
			}
		}
	}
	return c;
}

void print_matrix(double** s) {
	cout << "\n--------------\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n--------------\n";
}

int main() 
{	
	// инициализация матриц
	double** A = new double* [3];
	double** B = new double* [3];
	double x;


	for (int i = 0; i < 3; i++) {
		A[i] = new double[3];
		B[i] = new double[3];
	}

	// заполняем матрицы значениями
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> x;
			A[i][j] = x;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> x;
			B[i][j] = x;
		}
	}


	if (get_diagonal(A, B) == true) // нужно посчитать квадрат а, а не b
		print_matrix(get_square(A));
		
	else
		print_matrix(get_square(B));


	return 0;
}
