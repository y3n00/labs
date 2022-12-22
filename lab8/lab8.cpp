#include <iostream>

#include "Random.hpp"
static size_t lab = 1;

#define nextTask() std::cout << "\nTask " << lab++ << '\n';

void task1() {
    nextTask();
    int a;
    std::cout << "Введите переменную а: ";
    std::cin >> a;

    int* aPtr = &a;
    *aPtr += 100;
    std::cout << "Value:" << '\t' << "Adress:\n";
    std::cout << a << '\t' << &a << '\n';
}

void task2() {
    nextTask();
    size_t N, placeOfOne, attempts = 0;
    std::cout << "Введите размер массива: ";
    std::cin >> N;

    int* arr = new int[N]{0};
    placeOfOne = Random::getRand(N);
    arr[placeOfOne] = 1;

    int input = -1;
    std::cout << "Введите предпологаемое место единицы в массиве\n";
    do {
        std::cin >> input;
        if (input > placeOfOne)
            std::cout << "Единица левее\n";
        else if (input < placeOfOne)
            std::cout << "Единица правее\n";
        attempts++;
    } while (input != placeOfOne);
    std::cout << "Количество попыток: " << attempts << '\n';
    delete[] arr;
}

void task3() {
    nextTask();
    size_t n, sumOfPositive = 0;

    std::cout << "Введите размерность матрицы: ";
    std::cin >> n;
    int** matrix = new int*[n];
    for (size_t i = 0; i < n; i++) {
        matrix[i] = new int[n]{0};
        for (size_t j = 0; j < n; j++) {
            int& elem = matrix[i][j];
            elem = Random::getRand(-50, 50);
            std::cout << elem << '\t';
        }
        std::cout << '\n';
    }
    std::cout << "\nПобочная диагональ\n";
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n - i; j++) {
            int& elem = matrix[i][j];
            std::cout << elem << '\t';
            if (elem > 0)
                sumOfPositive += elem;
        }
        std::cout << '\n';
    }
    std::cout << "Сумма положительных элементов над побочной диагональю " << sumOfPositive << '\n';

    for (size_t i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}

int main() {
    task1();
    task2();
    task3();
}
