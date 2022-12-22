#include <ctime>
#include <iostream>

using namespace std;
void task1() {
    srand(time(NULL));
    int guess;
    int randNum = (rand() % 20) + 1;
    size_t attempts = 1;

    cout << "Введите число:\n";
    while (guess != randNum) {
        cin >> guess;

        if (guess == randNum)
            break;
        else if (guess > randNum)
            cout << "Мое число меньше\n";
        else
            cout << "Мое число больше\n";

        ++attempts;
    }
    cout << "Было загадано число: " << randNum << '\n';
    cout << "Количество попыток: " << attempts << '\n';
}

void task2() {
    const int currYear = 2022;
    int year, month, day;
    int maxDays = 31;

    do {
        cout << "Введите год вашего рождения\n";
        cin >> year;
    } while (year < currYear - 100 || year > currYear);

    bool isLeapYear = year % 400 == 0 && year % 4 == 0;

    do {
        cout << "Введите месяц вашего рождения\n";
        cin >> month;
    } while (month < 1 || month > 12);

    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            maxDays = 30;
            break;
        case 2:
            maxDays = isLeapYear ? 29 : 28;
            break;
    }

    do {
        cout << "Введите день вашего рождения\n";
        cin >> day;
    } while (day < 1 || day > maxDays);

    cout << "Ваша дата рождения: " << day << '.' << month << '.' << year << '\n';
}

int main() {
    setlocale(LC_ALL, "");
    task1();
    task2();
}
