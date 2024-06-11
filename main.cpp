#include <iostream>
#include "functions.h"
using namespace std;

int main() {
    int a, b;
    cout << "Введите ширину квадрата: ";
    cin >> a;
    cout << "Введите высоту квадрата: ";
    cin >> b;

    int area = calculate_area(a, b);
    if (area < 0) {
        cout << "Ошибка: неверные данные" << endl;
    }
    else {
        cout << "Площадь квадрата: " << area << endl;
    }
}