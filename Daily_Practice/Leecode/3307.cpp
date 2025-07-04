#include <iostream>
#include <bit>
#include <vector>
#include <iomanip>
#include <bitset>
using namespace std;

char kthCharacter(long long k, vector<int>& operations) {
    long long n = 1;
    int i = 0;
    while (n < k) {
        n *= 2;
        ++i;
    }
    int d = 0;
    while (n > 1) {
        if (k > n / 2) {
            k -= n / 2;
            d += operations[i - 1];
        }
        n /= 2;
        --i;
    }
    return 'a' + (d % 26);
}

int main(int argc, char** argv) {
	int k = 12145134613;
	std::vector<int> operations{ 0,0,0,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,0,0,1,1,1,1,1 };
	auto res = kthCharacter(k, operations);
	cout << res << "\n";
}