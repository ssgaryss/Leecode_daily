#include <iostream>
#include <vector>
#include <bit>
using namespace std;

long long minEnd(int n, int x) {
	long long res = x;
	long long m = n - 1, j = 0;
	int bitCount = bit_width((unsigned int)n) + bit_width((unsigned int)x);
	for (int i = 0; i < bitCount; ++i) {
		if (((res >> i) & 1) == 0) {
			if ((m >> j) & 1) {
				res |= (1LL << i);
			}
			j++;
		}
	}
	return res;
}

int main() {
	int n = 3, x = 4;
	auto res = minEnd(n, x);
	cout << res << "\n";
}