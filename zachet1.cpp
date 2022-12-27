#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

int** create_matrix(int m, int n)
{
	int** a = new int* [m];
	for (int i = 0; i < m; i++)
		a[i] = new int[n];
	return a;
}

void print_matrix(int** a, int m, int n, ofstream& out)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			out << a[i][j] << " ";
		out << endl;
	}
}

void print(int* a, int n)
{	// prints 1-dimensional array into concol
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
}

int** sum_matrix(int** a, int** b, int m, int n)
{
	int** D = create_matrix(m, n);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			D[i][j] = a[i][j] + b[i][j];
		}
	}
	return D;
}

int** transposed(int** d, int m, int n)
{
	int** H = create_matrix(n, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			H[i][j] = d[j][i];
		}
	}

	return H;
}

int** mult_matrix(int** a, int** b, int n)
{	// умножение работает только на квадратные матрицы

	int** c = create_matrix(n, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
	return c;
}

bool is_equal(int* a, int* b, int n)
{
	// a == b ?
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

//int** get_columns(int** a, int n)
//	// works only for square matrixes
//{
//	int** columns = create_matrix(n, n);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			columns[i][j] = a[j][i];
//		}
//	}
//	return columns;
//}

int main() 
{
	ifstream in("C:/Users/yashn/OneDrive/Documents/in1.txt", ios:: app);
	ofstream out("C:/Users/yashn/OneDrive/Documents/out.txt");

	if (!in.is_open())
	{
		cout << "can't open the file";
		exit(1);
	}

	int m, n, x;
	int i = 0;

	in >> m;
	in >> n;

	int N = n;

	// create matrixes
	int** A = create_matrix(m, n);
	int** B = create_matrix(m, n);
	int** C= create_matrix(n, m);

	// read the matrixes from files
	for (int i = 0; i < m * 2 + N + 1; i++) // go through all lines
	{
		if (i >= 2 * m) // now matrix C is read
			N = m;
			

		for (int j = 0; j < N; j++)
		{	
			if (in.eof())
				break;

			in >> x;

			if (i < m) // matrix A
				A[i][j] = x;

			else if ((i >= m) && (i < 2 * m)) // matrix B
				B[i%m][j] = x;
			
			else
				C[i % (2 * m)][j] = x;
		}
	}

	int** D = sum_matrix(A, B, m, n);
	int** D1 = transposed(D, m, n);
	
	out << "matrix D:\n";
	print_matrix(D, m, n, out);
	out << "\nMatrix D' : \n";

	print_matrix(D1, n, m, out);


	out << "\nD' * C:\n";


	if (n != m)
	{
		out << "Multiplication is maintained only for square matrixes, according to the task\n";
		return 0;
	}

	int** E = mult_matrix(D1, C, n);
	print_matrix(E, n, n, out);
	

	int** columns = transposed(E, n, n);

	// check if there is any line looking like a coumn

	for (int i = 0; i < n; i++)
	{	// line i
		// compare with columns
		// find E[i] in columns

		cout << "line:\n";
		print(E[i], n);
		cout << "\n---" << endl;

		for (int k = 0; k < n; k++)
		{	
			// columns[k] - a column
			// columns[k] == E[i] ?
			
			print(columns[k], n);
			cout << endl;

			if (is_equal(E[i], columns[k], n)) // if a line == a column
			{
				out << "\nThere are the same line and column\nline:  " << i << "\na column:  " << k;
				return 0;
			}
				


			//int t = 0;
			//for (int j = 0; j < n; i++)
			//{
			//	cout << "compare:  " << columns[k][j] << " and " << E[i][j] << endl;
			//	if (columns[k][j] != E[i][j])
			//		break; // look another column
			//	else
			//		t++; // if t = n then E[i] = columns[i]
			//}cout << " ------- " << endl;

			//if (t == n)
			//{
			//	out << "There are same line and column\nline - " << i << "\ncolumn - " << k;
			//	return 0;
			//}

		}
			
	}out << "\nNo the same line and column";

	return 0;
}
