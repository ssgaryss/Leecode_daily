#include <iostream>
#include <bit>
using namespace std;

char kthCharacter(int k) {
	return 'a' + popcount((uint32_t)k - 1);
}

int main(int argc, char** argv) {
	int k = 5;
	auto res = kthCharacter(k);
	cout << res << "\n";
}