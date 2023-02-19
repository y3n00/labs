#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>

#include "Random.hpp"

constexpr static auto filename = "students.txt";
constexpr static auto line = "-------------------------------------------\n";

int clearScreen() {
    return system("clear");
}

enum class Season : uint8_t {
    Winter = 1,
    Spring,
    Summer,
    Autumn
};

std::string seasonToStr(Season s) {
    std::string str;
    switch (s) {
        case Season::Winter:
            str = "Зима";
            break;
        case Season::Spring:
            str = "Весна";
            break;
        case Season::Summer:
            str = "Лето";
            break;
        case Season::Autumn:
            str = "Осень";
            break;
    }
    return str;
}

Season seasonFromInt(int value) {
    value %= 4;
    switch (value) {
        case 0:
            return Season::Autumn;
        case 1:
            return Season::Winter;
        case 2:
            return Season::Spring;
        case 3:
            return Season::Summer;
    }
}

struct Student {
    std::string fullName;
    std::string group;
    std::string phoneNumber;
    std::vector<int> marks;
    Season favSeason;

    float getGrade() const {
        return std::accumulate(marks.begin(), marks.end(), 0) / static_cast<float>(marks.size());
    }

    bool hasNumberPart(const std::string& str) const {
        return phoneNumber.find(str) != std::string::npos;
    }

    void getInfo() const {
        std::cout << "ФИО:\t" << fullName << '\n';
        std::cout << "Группа:\t" << group << '\n';
        std::cout << "МобТел:\t" << phoneNumber << '\n';
        std::cout << "Оценки:\t";
        for (auto& mark : marks)
            std::cout << mark << ' ';
        std::cout << "(средний балл " << getGrade() << ")\n";
        std::cout << "Сезон:\t" << seasonToStr(favSeason) << '\n';
        std::cout << line;
    }
};

Student createStudent() {
    Student s;
    std::cout << "Введите ФИО учащегося: ";
    std::cin.ignore();
    std::getline(std::cin, s.fullName);

    std::cout << "Введите группу: ";
    std::getline(std::cin, s.group);

    std::cout << "Введите номер телефона: ";
    std::getline(std::cin, s.phoneNumber);

    int mark;
    std::string str;
    std::cout << "Введите оценки:\n";
    std::getline(std::cin, str);
    std::stringstream sstr;
    sstr << str;
    while (sstr >> mark) {
        if (mark > 10)
            mark = 10;
        else if (mark < 0)
            mark = 0;

        s.marks.emplace_back(mark);
    }

    int SeasonInput;
    std::cout << "Выберите любимую пору года:\n";
    std::cout << "1) Зима\n";
    std::cout << "2) Весна\n";
    std::cout << "3) Лето\n";
    std::cout << "4) Осень\n";
    std::cin >> SeasonInput;
    s.favSeason = seasonFromInt(SeasonInput);
    return s;
}

void findByPhoneNumber(const std::vector<Student>& students, const std::string& phoneNumberPart) {
    std::cout << "Студенты с " << phoneNumberPart << " в номере\n";
    for (auto& s : students) {
        if (s.hasNumberPart(phoneNumberPart))
            s.getInfo();
    }
}

void findWithGrade(const std::vector<Student>& students, float grade = 7.0f) {
    std::cout << "Студенты с баллом равным или выше " << grade << '\n';
    for (auto& s : students) {
        if (s.getGrade() >= grade)
            s.getInfo();
    }
}

void findBySeason(const std::vector<Student>& students, Season season) {
    std::cout << "Студенты которые предпочитают " << seasonToStr(season) << '\n';
    for (auto& s : students) {
        if (s.favSeason == season)
            s.getInfo();
    }
}

std::vector<int> generateMarks() {
    const uint8_t marksN = Random<uint8_t>::get(5, 15);
    std::vector<int> marks(marksN);
    for (auto& mark : marks)
        mark = Random<int>::get(0, 10);
    return marks;
}

void printStudents(const std::vector<Student>& students) {
    for (size_t idx = 1; auto& s : students) {
        std::cout << idx++ << ") ";
        s.getInfo();
        std::cout << '\n';
    }
}

void saveToFile(const std::vector<Student>& students, std::string filename) {
    std::ofstream ofstr(filename);
    for (auto& s : students) {
        ofstr << s.fullName << '\n';
        ofstr << s.group << '\n';
        ofstr << s.phoneNumber << '\n';
        for (const auto& mark : s.marks)
            ofstr << mark << ' ';
        ofstr << '\n';
        ofstr << static_cast<int>(s.favSeason) << '\n';
    }
}

void loadFromFile(std::vector<Student>& students, std::string filename) {
    if (!std::filesystem::exists(filename)) {
        std::cout << "Файла не существует\n";
        return;
    }
    int mark, season;
    std::string buffer;
    std::stringstream sstr;

    std::ifstream ifstr(filename);
    students.clear();
    while (ifstr.good()) {
        std::getline(ifstr, buffer);
        if (buffer.empty())
            break;

        Student s;
        s.fullName = buffer;
        std::getline(ifstr, s.group);
        std::getline(ifstr, s.phoneNumber);
        std::getline(ifstr, buffer);

        sstr << buffer;
        while (sstr >> mark) {
            if (mark > 10)
                mark = 10;
            else if (mark < 0)
                mark = 0;

            s.marks.emplace_back(mark);
        }
        sstr.clear();

        std::getline(ifstr, buffer);
        sstr << buffer;
        sstr >> season;
        s.favSeason = static_cast<Season>(season);

        students.emplace_back(std::move(s));
        sstr.clear();
    }
}

void sortStudents(std::vector<Student>& students) {
    int in;
    std::cout << "1) Фамилии А-Я\n";
    std::cout << "2) Фамилии Я-А\n";
    std::cout << "3) Номеру группы\n";
    std::cout << "4) Номеру телефона\n";
    std::cout << "5) Среднему баллу 1-10\n";
    std::cout << "6) Среднему баллу 10-1\n";

    std::cin.ignore();
    std::cin >> in;
    switch (in) {
        case 1:
            std::ranges::sort(students,
                              [](const auto& s1, const auto& s2) {
                                  auto stud1Surname = s1.fullName.substr(0, s1.fullName.find(' '));
                                  auto stud2Surname = s2.fullName.substr(0, s2.fullName.find(' '));
                                  return stud1Surname < stud2Surname;
                              });
            break;
        case 2:
            std::ranges::sort(students,
                              [](const auto& s1, const auto& s2) {
                                  auto stud1Surname = s1.fullName.substr(0, s1.fullName.find(' '));
                                  auto stud2Surname = s2.fullName.substr(0, s2.fullName.find(' '));
                                  return stud1Surname > stud2Surname;
                              });
            break;
        case 3:
            std::ranges::sort(students,
                              [](const auto& s1, const auto& s2) {
                                  return s1.group < s2.group;
                              });
            break;
        case 4:
            std::ranges::sort(students,
                              [](const auto& s1, const auto& s2) {
                                  return s1.phoneNumber < s2.phoneNumber;
                              });
            break;
        case 5:
            std::ranges::sort(students,
                              [](const auto& s1, const auto& s2) {
                                  return s1.getGrade() < s2.getGrade();
                              });
            break;
        case 6:
            std::ranges::sort(students,
                              [](const auto& s1, const auto& s2) {
                                  return s1.getGrade() > s2.getGrade();
                              });
            break;
    }
}

void doAtIndex(std::vector<Student>& students, auto func) {
    printStudents(students);

    int in;
    std::cout << "Выберите студента\n";
    std::cin >> in;
    in -= 1;
    if (in >= 0 && in < students.size())
        func(students, in);
    else
        std::cout << "Неверный ввод\n";
}

int main() {
    clearScreen();
    std::vector<Student> students{
        Student{"Тихонов Артём Артёмович", "ГР-345", "+375293035126", {3, 4, 5, 0, 2}, Season::Summer},
        Student{"Игнатов Даниил Иванович", "ГР-345", "+375290614475", generateMarks(), Season::Autumn},
        Student{"Миронова Мария Григорьевна", "ГР-345", "+375295322501", {9, 10, 8, 9, 7}, Season::Winter},
        Student{"Поликарпова Варвара Артемьевна", "ГР-345", "+375298496566", generateMarks(), Season::Spring}};

    int in;
    while (true) {
        std::cout << "1) Найти студента по номеру телефона\n";
        std::cout << "2) Найти студента по любимой поре года\n";
        std::cout << "3) Вывести студентов со средним баллом > 7\n";
        std::cout << "4) Добавить студента\n";
        std::cout << "5) Сохранить список студентов\n";
        std::cout << "6) Загрузить список\n";
        std::cout << "7) Вывести список студентов\n";
        std::cout << "8) Сортировать студентов\n";
        std::cout << "9) Удалить студента по номеру\n";
        std::cout << "10) Смена имени студенту\n";
        std::cout << "99) Очистить экран\n";
        std::cout << "0) Выход\n";

        std::cin >> in;
        switch (in) {
            case 1: {
                std::cout << "Введите часть номера телефона для поиска: ";
                std::cin.ignore();

                std::string str;
                std::getline(std::cin, str);
                findByPhoneNumber(students, str);
                break;
            }
            case 2: {
                std::cout << "Выберите пору года:\n";
                std::cout << "1) Зима\n";
                std::cout << "2) Весна\n";
                std::cout << "3) Лето\n";
                std::cout << "4) Осень\n";

                int s;
                std::cin >> s;
                findBySeason(students, seasonFromInt(std::abs(s)));
                break;
            }
            case 3:
                findWithGrade(students);
                break;
            case 4:
                std::cout << "\nДобавление нового студента\n";
                students.emplace_back(createStudent());
                break;
            case 5:
                std::cout << "\nСохранение в файл\n";
                saveToFile(students, filename);
                break;
            case 6:
                std::cout << "\nЗагрузка из файла\n";
                loadFromFile(students, filename);
                break;
            case 7:
                std::cout << "\nПолный список учащихся\n";
                printStudents(students);
                break;
            case 8:
                sortStudents(students);
                break;
            case 9:
                std::cout << "Удаление студента\nВыберите студента для удаления\n";
                doAtIndex(students,
                          [](auto& range, int k) {
                              range.erase(range.begin() + k);
                          });
                break;
            case 10:
                std::cout << "Смена имени студента\n";
                doAtIndex(students,
                          [](auto& range, int k) {
                              std::cout << "Введите новое имя студента: ";
                              std::cin.ignore();
                              std::getline(std::cin, range[k].fullName);
                          });
                break;
            case 99:
                clearScreen();
                break;
            case 0:
                return 0;
        }
    }
}