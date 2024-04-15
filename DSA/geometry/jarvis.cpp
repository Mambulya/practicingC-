
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* Нахожление минимальной выпуклой оболочкой
*   АЛГОРИТМ ДЖАРВИСА
* 
* 
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

// вывести вектор Р
void printV(const vector<int>& p) {
    cout << "\n-------------------" << endl;;
    for (int el : p) {
        cout << el << " ";
    }
    cout << "\n-------------------" << endl;;
}


vector<Point> jarvisMarch(vector<Point> points) {
    int n = points.size();
    vector<int> P(n);
    for (int i = 0; i < n; i++)
        P[i] = i;

    // найдем самую левую точку
    sort(P.begin(), P.end(), [&](int a, int b) {
        return points[a].x < points[b].x;
        });
    //printV(P);

    vector<int> hull; // вектор оболочки
    int p = 0;          // индекс нынешней точки

    hull.push_back(P[0]);
    P.push_back(P[0]);
    P.erase(P.begin());


    while (true) {
        int right = 0;
        for (int i = 1; i < P.size(); i++) {
            if (rotate(points[hull.back()], points[P[right]], points[P[i]]) < 0) {
                right = i;
            }
        }
        if (P[right] == hull[0]) break; // оболочка замкнулась
        else {
            hull.push_back(P[right]);
            P.erase(P.begin() + right);
            }
        }

    vector<Point> res;
    for (int index : hull) {
        res.push_back(points[index]);
    }
    return res;
}

void test(vector<Point>& p) {
    vector<Point> hull = jarvisMarch(p);

    cout << "Convex Hull points are:\n";
    for (auto el : hull)
        cout << "(" << el.x << ", " << el.y << ")\n";
}

int main() {
    vector<Point> points1 = { {0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3} };
    vector<Point> points2 = { {1, 4}, {-3, 2}, {-1, 2}, {-2, -1}, {2, -3}, {2, -1}, {4, 1}, {3, 2}, {3, 4}, {2, 3} };
    vector<Point> points3 = { {-2, 6},  {-3, 4}, {-2, 3}, {-3, 1}, {-3, -2}, {-1, -1}, {1, -1}, {3, -2}, {2, 1}, {1, 2}, {4, 4}, {3, 4} };

    cout << "1 test:" << endl;
    test(points1);
    cout << endl;

    cout << "2 test:" << endl;
    test(points2);
    cout << endl;

    cout << "3 test:" << endl;
    test(points3);
    cout << endl;


    return 0;
}
