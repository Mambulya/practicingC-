#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
* 
* 
      РЕАЛИЗВЦИЯ АЛГОРИТМА ГРЭХЕМА

На плоскости задано точек, составляющее множество. 
Построить выпуклую оболочку этих точек по алгоритму Грэхема.


*/

struct Point {
    int x, y;
};

int rotate(Point A, Point B, Point C) {
    /*
    определяет по какую сторону от AB находится точка C 
    ! положительное возвращаемое значение соответствует левой стороне, отрицательное — правой
    z=axby-aybx. Если z>0, то искомый поворот левый, если z<0 — то правый
    */
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x); 
    // векторное произведение AB и BC
    // = ABx * BCy - ABy * BCx
}

vector<int> grahamscan(vector<Point> & A) {
    int n = A.size(); // число точек
    vector<int> P(n); // список индексов точек
    for (int i = 0; i < n; ++i)
        P[i] = i;

    // ищем самую левую точку для старта оболочки
    for (int i = 1; i < n; ++i) {
        if (A[P[i]].x < A[P[0]].x) 
            swap(P[i], P[0]); 
    }

    // сортируем оставшиеся точки по их левизне отностительно первой точки
    sort(P.begin() + 1, P.end(), [&](int a, int b) {
        return rotate(A[P[0]], A[a], A[b]) > 0; }); // быстрая сортировка


    // создаем стек для точек ВЫПУКЛОЙ оболочки (первые 2 точки гарантированы)
    vector<int> S;
    S.push_back(P[0]);
    S.push_back(P[1]);

    for (int i = 2; i < n; ++i) {
        while (rotate(A[S[S.size() - 2]], A[S[S.size() - 1]], A[P[i]]) < 0) // встретили правую точку
        {
            S.pop_back(); // удаляем все левые точки до неё
        }
        S.push_back(P[i]); // тобавляем вершину
    }

    return S;
}

void test(vector<Point> &p) {
    vector<int> convexHull = grahamscan(p);
    cout << "\nMBO Points:\n";
    for (int i = 0; i < convexHull.size(); ++i) {
        cout << p[convexHull[i]].x << " " << p[convexHull[i]].y << endl;
    }
}

int main() {
    vector<Point> points0 = { {0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3} };
    vector<Point> points1 = { {-1, 3}, {-3, 1}, {-1, -1}, {-2, -3}, {1, -4}, {3, -2}, {1, 1}, {3, 3}, {4, 4} };
    vector<Point> points2 = { {1, 5}, {1, 9}, {1, 2}, {2, 2}, {3, 5}, {3, 6}, {5, 5}, {5, 7}, {3, 7}, {5, 9} };

    test(points0);
    test(points1);
    test(points2);

    return 0;
}
