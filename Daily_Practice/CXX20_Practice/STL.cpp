#include <stdio.h>   //在全局命名空间 
#include <cstdio>    //在命名空间std
#include <bit>
#include <iostream>
#include <iomanip>
#include <utility>

int main() {
	std::printf("hello world!\n");
	uint8_t a = 0b10001000, b = 0b01000000;
	std::cout << std::boolalpha;
	std::cout << std::has_single_bit(a) << "\n";
	std::cout << std::has_single_bit(b) << "\n";

	std::cout << static_cast<unsigned int>(-5) << "\n";  
	std::cout << (-5 > 5u) << "\n";                      //不安全
	std::cout << std::cmp_greater(-5, 5u) << "\n";       //即使无符号数和有符号数比较也安全

}