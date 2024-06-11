#include <iostream> 
#include <string>
#include <stack>
#include <cmath>
#include <cctype>
#include "functions2.h"
using namespace std;

int main() {
    try {
        string expression;
        cout << "Введите арифметическое выражение: ";
        getline(cin, expression); 
        double result = calculate(expression);
        cout << "Результат: " << result << endl;
    } catch (const runtime_error& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    return 0;
}