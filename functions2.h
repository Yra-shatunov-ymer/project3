#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <cctype>

using namespace std;


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

bool isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isOperand(char c) {
  return (isdigit(c) || c == '.');
}  

int getPrecedence(char op) {
  if (op == '^') {
  return 3;
  } else if (op == '*' || op == '/') {
  return 2;
 } else if (op == '+' || op == '-') {
return 1;
} else {
return 0;
  }
}




double evaluate(double a, double b, char op) {
switch (op) {
   case '+': return a + b;
  case '-': return a - b;
  case '*': return a * b;
  case '/': 
          if (b == 0) {
              throw runtime_error("Деление на ноль!"); 
          }
return a / b;
  case '^': return pow(a, b);
      default: throw runtime_error("Неизвестная операция!");
  }
}


double calculate(string expression) {
  stack<double> operandStack;
  stack<char> operatorStack;

  for (int i = 0; i < expression.length(); i++) {
      char c = expression[i];

      if (isspace(c)) {
          continue; 
      }

      if (isOperand(c)) {

string number;
while (i < expression.length() && (isOperand(expression[i]) || expression[i] == '.')) {
  number += expression[i];
      i++;
}
  operandStack.push(stod(number));
  i--; 
      } else if (c == '(') {
          operatorStack.push(c);
      } else if (c == ')') {

          while (!operatorStack.empty() && operatorStack.top() != '(') {
              double b = operandStack.top();
              operandStack.pop();
              double a = operandStack.top();
              operandStack.pop();
              char op = operatorStack.top();
              operatorStack.pop();
              operandStack.push(evaluate(a, b, op));
          }
          if (!operatorStack.empty() && operatorStack.top() == '(') {
              operatorStack.pop(); 
          } else {
              throw runtime_error("Ошибка: несоответствие скобок!");
          }
      } else if (isOperator(c)) {
          while (!operatorStack.empty() && getPrecedence(c) <= getPrecedence(operatorStack.top())) {
              double b = operandStack.top();
              operandStack.pop();
              double a = operandStack.top();
              operandStack.pop();
              char op = operatorStack.top();
              operatorStack.pop();
              operandStack.push(evaluate(a, b, op));
          }
          operatorStack.push(c);
      } else {
          throw runtime_error("Недопустимый символ: " + string(1, c));
      }
  }

  while (!operatorStack.empty()) {
      double b = operandStack.top();
      operandStack.pop();
      double a = operandStack.top();
      operandStack.pop();
      char op = operatorStack.top();
      operatorStack.pop();
      operandStack.push(evaluate(a, b, op));
  }

  if (operandStack.empty()) {
      throw runtime_error("Ошибка: пустой стек операндов!");
  }
  return operandStack.top();
}


#endif