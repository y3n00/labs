#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
    // /*
    int randNum = (rand() % 20) + 1;
    int atmpts = 1;

    int guess;
    cout << "Введите число:" << endl;
    while (guess != randNum) {
        if (guess > randNum)
            cout << "Число меньше" << endl;
        else
            cout << "Число больше" << endl;
        cin >> guess;
        attempts++;
    }
    cout << "Было загадано число " << randNum << endl;
    cout << "Количество попыток: " << attempts << endl;
    // */
    
    /*
    const int currYear = 2022;
    int maxDays = 31;
    int year, month, day;

    do {
        cout << "Введите год вашего рождения" << endl;
        cin >> year;
    } while (year < currYear - 100 || year > currYear);

    do {
        cout << "Введите месяц вашего рождения" << endl;
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
            if(year%4 == 0)
                maxDays = 29;
            else 
                maxDays = 28);
            break;
    }

    do {
        cout << "Введите день вашего рождения" << endl;
        cin >> day;
    } while (day < 1 || day > maxDays);

    cout << "Ваша дата рождения: " << day << '.' << month << '.' << year << endl;
    */
}
