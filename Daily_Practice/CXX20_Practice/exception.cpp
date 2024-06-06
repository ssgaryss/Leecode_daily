#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

[[nodiscard("nodiscard_findIndices")]] int func() { return 1; }

int main() {
	func();
}