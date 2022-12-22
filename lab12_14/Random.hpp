#pragma once
#include <random>

template <typename T>
class Random {
   private:
    static std::mt19937 gen;

   public:
    Random() = default;
    Random(Random&&) = delete;
    Random(const Random&) = delete;
    Random& operator=(const Random&) = delete;

    static T getRand() {
        return std::uniform_int_distribution()(gen);
    }

    static T getRand(T maxN) {
        return std::uniform_int_distribution(T(0), maxN)(gen);
    }

    static T getRand(T minN, T maxN) {
        return std::uniform_int_distribution(minN, maxN)(gen);
    }
};

template <typename T>
std::mt19937 Random<T>::gen{std::random_device{}()};