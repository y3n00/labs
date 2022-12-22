#include <ctime>
#include <iostream>

void task1() {
    const int members = 3;
    const int judges = 4;

    float avg[members]{};
    for (int m = 0; m < members; m++) {
        std::cout << m + 1 << "-й участник\n";
        for (int j = 0; j < judges; j++) {
            int score = rand() % 101;
            std::cout << "\t Балл " << j + 1 << "-ого судьи: " << score << std::endl;
            avg[m] += score;
        }
        avg[m] /= judges;
        std::cout << "\tСредний балл: " << avg[m] << std::endl;
    }

    int maxScore = 0;
    for (int m = 0; m < members; m++) {
        if (avg[m] > avg[maxScore])
            maxScore = m;
    }

    std::cout << "Победил " << maxScore + 1 << "-й участник со средним счетом " << avg[maxScore] << std::endl;
}

void task2() {
    const int rows = 5, cols = 6;
    int arr[rows][cols];
    for (size_t k = 0; k < rows; ++k) {
        for (size_t i = 0; i < cols; ++i) {
            arr[k][i] = rand() % 100;
            std::cout << arr[k][i] << ' ';
        }
        std::cout << '\n';
    }

    for (size_t k = 0; k < rows; ++k) {
        int firstElem = arr[k][0];
        arr[k][0] = arr[k][cols - 1];
        arr[k][cols - 1] = firstElem;
    }
    std::cout << "Измененный:\n";
    for (size_t k = 0; k < rows; ++k) {
        for (size_t i = 0; i < cols; ++i)
            std::cout << arr[k][i] << ' ';

        std::cout << '\n';
    }
}

int main() {
    task1();
    task2();
}