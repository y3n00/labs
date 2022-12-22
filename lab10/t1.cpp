#include <iostream>

float getMax(float v1, float v2, float v3);

int main() {
    float a, b, c;
    std::cin >> a >> b >> c;
    std::cout << getMax(a, b, c) << '\n';
}

float getMax(float v1, float v2, float v3) {
    return (v1 > v2 ? (v1 > v3 ? v1 : v3) : (v2 > v3 ? v2 : v3));
}
