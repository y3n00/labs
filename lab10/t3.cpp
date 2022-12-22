#include <iostream>
#include <string>

size_t askForAst() {
    int n;
    std::cout << "Enter amount of *: ";
    std::cin >> n;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cin >> n;
    }
    return (n > 0 ? n : -n);
}

void printAsterisks(size_t num) {
    // std::cout << std::string(num, '*') << '\n';
    for (size_t i = 0; i < num; i++)
        std::cout << '*';
    std::cout << '\n';
}

int main() {
    printAsterisks(askForAst());
}