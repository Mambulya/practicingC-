
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для вычисления квадрата расстояния между двумя векторами
int sum_squares(vector<int> x, vector<int> y)
{
    int sum = 0;
    for (int i = 0; i < x.size(); i++) {
        int diff = x[i] - y[i];
        sum += diff * diff;
    }
    return sum;
}

// Функция для вычисления максимального отклонения между двумя векторами
int max_deviation(vector<int> x, vector<int> y)
{
    int max_diff = 0;
    for (int i = 0; i < x.size(); i++) {
        int diff = abs(x[i] - y[i]);
        if (diff > max_diff) {
            max_diff = diff;
        }
    }
    return max_diff;
}

// Функция для вычисления скалярного произведения двух векторов
int scalar_product(vector<int> x, vector<int> y)
{
    int sum = 0;
    for (int i = 0; i < x.size(); i++) {
        sum += x[i] * y[i];
    }
    return sum;
}

int main()
{
    // Объявляем и инициализируем переменные
    vector<int> C2 = { 1020, -108, -79 };
    vector<int> X8 = { -35001, 102, -3041 };
    int AB, BA, XY;

    // Выполняем операции
    AB = scalar_product(C2, X8);
    BA = max_deviation(X8, C2);
    XY = sum_squares(X8, C2);

    // Выводим результаты
    cout << "AB = " << AB << endl;
    cout << "BA = " << BA << endl;
    cout << "XY = " << XY << endl;

    return 0;
}
