#include <iostream>
#include <chrono>

// ����������������
constexpr int operator"" _square(unsigned long long n) {
    return n * n;
}

int main() {
    // ʹ���Զ���������
    constexpr int area = 5_square;
    std::cout << "Area: " << area << std::endl;

    using namespace std::literals;
    auto myString{ "Hello"sv };
    std::cout << "myString: " << myString << std::endl;
    using namespace chrono_literals;
    auto Minutes{ 42min };
    std::cout << "Minutes: " << Minutes << std::endl;
    auto Year{ 2020y };
    std::cout << "Year: " << Year << std::endl;
    //auto myString{ "Hello"sv };
    //std::cout << "myString: " << myString << std::endl;

    return 0;
}