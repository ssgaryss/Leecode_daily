#include <iostream>
#include <algorithm>

void process(int& a) {
	std::cout << "Lvalue" << "\n";
}

void process(int&& a) {
	std::cout << "Rvalue" << "\n";
}


int main(int argc, char** argv) {
	int c = 10;
	int& a = c;
	int&& b = 20;
	process(a);
	process(b);
	process(std::forward<int>(b));
	process(std::forward<int&>(b));
	process(std::move(a));
	process(std::move(b));
}