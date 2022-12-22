#include <iostream>

void task1() {
    const int myNum = 3;
    for (size_t num = 1; num <= 10; ++num)
        std::cout << num << 'x' << myNum << " = " << num * myNum << '\n';
}

void task2() {
    int32_t a, b;
    std::cout << "Введите два разных числа\n";
    std::cin >> a >> b;

    if (a > b) {
        auto tempVal = b;
        b = a;
        a = tempVal;
    }

    for (; a <= b; a += 2)
        std::cout << a << '\n';
}

int main() {
    task1();
    task2();
}
