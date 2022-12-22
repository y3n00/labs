#include <iostream>

const size_t factorial(int n);

int main() {
    int j;
    std::cout << "Enter j for factorial: ";
    std::cin >> j;
    std::cout << factorial(j) << '\n';
}

const size_t factorial(int n) {
    if (n == 1) {
        std::cout << 1 << " = ";
        return 1;
    } else {
        std::cout << n << '*';
        return n * factorial(n - 1);
    }
}