#include <iostream>

const size_t sum(int n);

int main() {
    int n;
    std::cout << "Enter n for sum: ";
    std::cin >> n;
    std::cout << sum(n) << '\n';
}

const size_t sum(int n) {
    return n == 0
               ? 0
               : n + sum(n - 1);
}