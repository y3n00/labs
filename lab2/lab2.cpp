#include <cmath>
#include <iostream>

void task1() {
    float a, b;
    std::cout << "Введите 2 числа: ";
    std::cin >> a >> b;

    float sub = a - b;
    float div = a / b;

    std::cout << "a-b = " << sub << '\n'
              << "a/b = " << div << std::endl;
}

void task2() {
    double x = 1.71, y = 0.765, z = 3.14;
    double exp1 = (exp(fabs(x - y)) * pow(fabs(x - y), x + y)) / (atan(x) + atan(z));
    double exp2 = cbrt(pow(x, 6) + pow(log(y), 2));
    double s = exp1 + exp2;
    std::cout << s << '\n';
}

int main() {
    task1();
    task2();
}