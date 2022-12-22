#include <iostream>

void task1() {
    const size_t SIZE = 5;
    int arr1[SIZE] = {1, 2, 3, 4, 5}, arr2[SIZE], arr3[SIZE], arr4[SIZE];

    for (size_t k = 0; k < SIZE; ++k) {
        std::cout << "Enter " << k + 1 << " element of array: ";
        std::cin >> arr2[k];
        arr3[k] = rand() % 1000;
        arr4[k] = arr1[k] * arr2[k] * arr3[k];
    }
    std::cout << "\narr1\tarr2\tarr3\tarr4\n";
    for (size_t k = 0; k < SIZE; ++k)
        std::cout << arr1[k] << '\t' << arr2[k] << '\t' << arr3[k] << '\t' << arr4[k] << '\n';
}

void task2() {
    const size_t SIZE = 20;
    int arr[SIZE];
    for (size_t k = 0; k < SIZE; ++k) {
        arr[k] = rand() % 1000;
        std::cout << arr[k] << ' ';
    }

    size_t counter = 0;
    for (size_t k = 1; k < SIZE - 1; ++k)
        if (arr[k] > arr[k - 1] && arr[k] > arr[k + 1]) {
            std::cout << k << ' ';
            ++counter;
        }
    std::cout << "\nAmount of elements that are greater than their neighbors: " << counter << '\n';
}

void task3() {
    const char surname[] = {"KLESHCHINSKY"};
    const size_t size = sizeof(surname) / sizeof(surname[0]);
    std::cout << "Original: " << surname << '\n';

    char code[size], decode[size];
    std::cout << "Encoded: ";
    for (size_t k = 0; k < size; ++k) {
        char encoded = surname[k] + 4;
        code[k] = (encoded > 'Z' ? encoded - 26 : encoded);
        std::cout << code[k];
    }
    std::cout << std::endl;

    std::cout << "Decoded: ";
    for (size_t k = 0; k < size; ++k) {
        char decoded = code[k] - 4;
        decode[k] = (decoded < 'A' ? decoded + 26 : decoded);
        std::cout << decode[k];
    }
    std::cout << std::endl;
}

int main() {
    system("clear");
    int input;
    while (true) {
        std::cout << "Choose a task:\n1)Arrays\n2)Neighbors\n3)Caesar code\n0)Exit\n\n";
        std::cin >> input;
        switch (input) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            default:
                return 0;
        }
    }
}