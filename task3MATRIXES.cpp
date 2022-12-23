#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;


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

	int** A = new int* [m];
	int** B = new int* [m];
	int** C = new int* [n];


	// create matrix A, B
	for (int i = 0; i < m; i++)
	{
		A[i] = new int[n];
		B[i] = new int[n];
	}

	// create matrix C
	for (int i = 0; i < n; i++)
		C[i] = new int[m];


	for (int i = 0; i < m * 2 + N + 1; i++) // проходимся по всем строкам файла
	{
		if (i >= 2 * m) // теперь очередь матрицы С
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


	// output the matrixes
	cout << "--------------\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}

	cout << "--------------\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << B[i][j] << "  ";
		}cout << endl;
	}

	cout << "--------------\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << C[i][j] << "  ";
		}cout << endl;
	}



	return 0;
}
