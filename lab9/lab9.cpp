#include <iostream>
#include <string>

void task1() {
    std::cin.ignore();
    std::string str;
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);
    for (size_t k = 0; k < str.length(); k++)
        if (!std::isdigit(str[k])) {
            str.erase(k, 1);
            k--;
        }
    std::cout << "Строка без символов: " << str << '\n';
}

void task2() {
    std::cin.ignore();
    std::string str;
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);
    std::string substr = str.substr(0, 3);
    if (substr == "Hel")
        str += " :)";
    else if (substr == "Bye")
        str += " :(";
    else {
        std::cout << "Некорректный ввод\n";
        return;
    }
    std::cout << str << '\n';
}

void task3() {
    std::cin.ignore();
    std::string str, surname = "Клещинский";
    std::cout << "Введите имя и фамилию: ";
    std::getline(std::cin, str);
    size_t surnameLen = str.find(' ');
    str.replace(0, surnameLen, surname);
    std::cout << str << '\n';
}

void task4() {
    std::cin.ignore();
    std::string longWord;
    std::getline(std::cin, longWord);
    if (longWord.empty()) {
        std::cout << "Введена пустая строка\n";
        return;
    }

    for (size_t i = 1;; i++) {
        std::string str;
        std::cin >> str;
        if (longWord.find(str) == std::string::npos) {
            size_t winner = (i % 2 == 0 ? 1 : 2);
            std::cout << "Выиграл игрок " << winner << "-й игрок\n";
            return;
        }
    }
}

int main() {
    int input;
    while (true) {
        std::cout << "Выберите задание:\n";
        std::cout << "1) Задание 1\n";
        std::cout << "2) Задание 2\n";
        std::cout << "3) Задание 3\n";
        std::cout << "4) Задание 4\n";
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
            case 4:
                task4();
                break;
            default:
                return 0;
        }
    }
}