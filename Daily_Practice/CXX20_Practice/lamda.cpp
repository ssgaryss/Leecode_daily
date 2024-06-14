#include <iostream>
using namespace std;

int main() {
	int y = 10;
	auto chageY = [y]() mutable {
		y = 20;
		cout << y << "\n";
		return y;
		};
}