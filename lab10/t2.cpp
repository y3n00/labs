#include <iomanip>
#include <iostream>

#include "Random.hpp"

size_t counter(int value, int arr[5][5]) {
    size_t counter = 0;
    for (size_t i = 0; i < 5; i++)
        for (size_t j = 0; j < 5; j++)
            if (arr[i][j] == value)
                counter++;
    return counter;
}

int main() {
    int arr[5][5];
    for (auto& row : arr) {
        for (auto& elem : row)
            std::cout << std::setw(5) << (elem = Random::getRand(-5, 5));
        std::cout << std::endl;
    }
    int value;
    std::cin >> value;
    std::cout << "amount of " << value << ": " << counter(value, arr) << '\n';
}