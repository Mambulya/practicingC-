#include <iostream>
using namespace std;

double** get_matrix() {
	double r;
	double** A = new double* [3]; // double* [6]
	for (int i = 0; i < 3; i++) { // 6
		A[i] = new double[3];  // 6
	}
	for (int i = 0; i < 3; i++) { // 6
		for (int j = 0; j < 3; j++) { // 6
			cin >> r;
			A[i][j] = r;
		}
	}
	return A;
}


double* mult_vector_matrix(double v[3], double** M) {
	double r[3]; // 6
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			r[i] = r[i] + M[i][j] * v[j];
		}
	}
	return r;
}


double scolar_product(double* A, double* B) {
	double r = 0;
	for (int i = 0; i < 3; i++) {
		r = r + A[i] * B[i];
	}
	return r;
}

int main() 
{	
	double x[3]; // x[3]
	double y[3]; // y[3]
	double r;

	// заполнение векторов
	for (int i = 0; i < 6; i++) { // i < 12
		cin >> r; 
		if (i < 3) // i < 6
			x[i] = r;
		else
			y[i % 3] = r; // i % 6
	}

	double** A = get_matrix();
	double** B = get_matrix();
	double** C = get_matrix();

	double* Ax = mult_vector_matrix(x, A);
	double* Cx = mult_vector_matrix(x, C);
	double* By = mult_vector_matrix(y, B);


	cout << (scolar_product(Ax, By)) + (scolar_product(Cx, y) / scolar_product(x, By));

	return 0;
