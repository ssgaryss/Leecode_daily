#include <iostream>

void foo() {
    std::cout << __FUNCSIG__ << std::endl;
}

int main() {
    foo();
    return 0;
}