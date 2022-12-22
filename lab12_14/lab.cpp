#include <algorithm>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

#include "Random.hpp"
using namespace nlohmann;

constexpr auto filename = "students.json";
constexpr auto line = "-------------------------------------------\n";

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
        std::cout << "Оценки:\t";
        for (const auto& m : marks)
            std::cout << m << ' ';
        std::cout << "(средний балл " << getGrade() << ")\n";
        std::cout << "Сезон:\t" << seasonToStr(favSeason) << '\n';
        std::cout << "МобТел:\t" << phoneNumber << '\n';
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
    while (sstr >> mark)
        s.marks.emplace_back(mark);

    int SeasonInput;
    std::cout << "Выберите любимую пору года:\n";
    std::cout << "1) Зима\n";
    std::cout << "2) Весна\n";
    std::cout << "3) Лето\n";
    std::cout << "4) Осень\n";
    std::cin >> SeasonInput;
    s.favSeason = static_cast<Season>(SeasonInput);
    return s;
}

void findByPhoneNumber(const std::vector<Student>& students, const std::string& phoneNumberPart) {
    std::cout << "Студенты с " << phoneNumberPart << " в номере\n";
    for (auto& s : students)
        if (s.hasNumberPart(phoneNumberPart))
            s.getInfo();
}

void findWithGrade(const std::vector<Student>& students, float grade = 7.0f) {
    std::cout << "Студенты с баллом равным или выше " << grade << '\n';
    for (auto& s : students)
        if (s.getGrade() >= grade)
            s.getInfo();
}

void findBySeason(const std::vector<Student>& students, Season season) {
    std::cout << "Студенты которые предпочитают " << seasonToStr(season) << '\n';
    for (auto& s : students)
        if (s.favSeason == season)
            s.getInfo();
}

auto generateMarks() {
    const uint8_t marksN = Random<uint8_t>::getRand(5, 15);
    std::vector<int> vec;
    vec.reserve(marksN);
    for (uint8_t k = 0; k < marksN; k++)
        vec.emplace_back(Random<int>::getRand(0, 10));
    return vec;
}

void saveToFile(const std::vector<Student>& students, std::string filename) {
    json mainJs;
    for (auto& s : students) {
        json j;
        j["Name"] = s.fullName;
        j["Group"] = s.group;
        j["Number"] = s.phoneNumber;
        j["Marks"] = s.marks;
        j["Season"] = s.favSeason;
        mainJs += j;
    }
    std::ofstream(filename, std::ios::out) << mainJs;
}

void loadFromFile(std::vector<Student>& loadTo, std::string filename) {
    json mainJs;
    std::ifstream(filename, std::ios::in) >> mainJs;
    loadTo.clear();
    loadTo.reserve(mainJs.size());

    for (const auto& j : mainJs) {
        Student s;
        j.at("Name").get_to(s.fullName);
        j.at("Group").get_to(s.group);
        j.at("Number").get_to(s.phoneNumber);
        j.at("Marks").get_to(s.marks);
        j.at("Season").get_to(s.favSeason);
        loadTo.emplace_back(std::move(s));
    }
}

void printStudents(const std::vector<Student>& students) {
    for (size_t idx = 1; auto& s : students) {
        std::cout << idx++ << ") ";
        s.getInfo();
        std::cout << '\n';
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
            std::sort(students.begin(), students.end(),
                      [](const Student& s1, const Student& s2) -> bool {
                          auto sur1 = s1.fullName.substr(0, s1.fullName.find(' '));
                          auto sur2 = s2.fullName.substr(0, s2.fullName.find(' '));
                          return sur1 < sur2;
                      });
            break;
        case 2:
            std::sort(students.begin(), students.end(),
                      [](const Student& s1, const Student& s2) -> bool {
                          auto sur1 = s1.fullName.substr(0, s1.fullName.find(' '));
                          auto sur2 = s2.fullName.substr(0, s2.fullName.find(' '));
                          return sur1 > sur2;
                      });
            break;
        case 3:
            std::sort(students.begin(), students.end(),
                      [](const Student& s1, const Student& s2) -> bool {
                          return s1.group < s2.group;
                      });
            break;
        case 4:
            std::sort(students.begin(), students.end(),
                      [](const Student& s1, const Student& s2) -> bool {
                          return s1.phoneNumber < s2.phoneNumber;
                      });
            break;
        case 5:
            std::sort(students.begin(), students.end(),
                      [](const Student& s1, const Student& s2) -> bool {
                          return s1.getGrade() < s2.getGrade();
                      });
            break;
        case 6:
            std::sort(students.begin(), students.end(),
                      [](const Student& s1, const Student& s2) -> bool {
                          return s1.getGrade() > s2.getGrade();
                      });
            break;
    }
}

template <typename Func>
void doAtIndex(std::vector<Student>& students, Func&& func) {
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
    int errCode = system("clear");
    std::vector<Student> students{
        Student{"Тихонов Артём Артёмович", "ГР-345", "375 29 303-51-26", {3, 4, 5, 0, 2}, Season::Summer},
        Student{"Игнатов Даниил Иванович", "ГР-345", "375 29 061-44-75", generateMarks(), Season::Autumn},
        Student{"Миронова Мария Григорьевна", "ГР-345", "375 29 532-25-01", {9, 10, 8, 9, 7}, Season::Winter},
        Student{"Поликарпова Варвара Артемьевна", "ГР-345", "375 29 849-65-66", generateMarks(), Season::Spring}};

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
                findBySeason(students, static_cast<Season>(s));
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
                          [](auto& range, int k) -> void {
                              range.erase(range.begin() + k);
                          });
                break;
            case 10:
                std::cout << "Смена имени студента\n";
                doAtIndex(students,
                          [](auto& range, int k) -> void {
                              std::cout << "Введите новое имя студента: ";
                              std::cin.ignore();
                              std::getline(std::cin, range[k].fullName);
                          });
                break;
            case 99:
                if (system("clear") != 0)
                    return 0;
                break;

            default:
                return 0;
        }
    }
}