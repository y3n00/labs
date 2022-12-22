#include <cmath>
#include <iostream>

void task1() {
    double x, y, result;
    std::cin >> x >> y;

    if (x > fabs(y))
        result = 2 * pow(x, 3) + 3 * pow(y, 3);
    else if (x > 3 && x < fabs(y))
        result = fabs(x - y);
    else
        result = cbrt(fabs(x - y));

    std::cout << result << std::endl;
}

void task2() {
    int k, day;
    std::cout << "Введите номер дня: ";
    std::cin >> k;

    if (k < 1 || k > 365) {
        std::cout << "invalid value\n";
        return;
    }

    day = k % 7;
    switch (day) {
        case 1:
            std::cout << "понедельник\n";
            break;
        case 2:
            std::cout << "вторник\n";
            break;
        case 3:
            std::cout << "среда\n";
            break;
        case 4:
            std::cout << "четверг\n";
            break;
        case 5:
            std::cout << "пятница\n";
            break;
        case 6:
            std::cout << "суббота\n";
            break;
        case 0:
            std::cout << "воскресенье\n";
            break;
    }
}

int main() {
    // task1();
    task2();
}