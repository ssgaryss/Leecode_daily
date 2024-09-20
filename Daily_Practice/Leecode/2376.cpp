#include <iostream>
#include <string>
#include <unordered_map>
#include <bit>
using namespace std;

unordered_map<int, int> memo;

int dp(int mask, bool prefixSmaller, const string& nStr) {
    if (popcount((unsigned int)mask) == nStr.size()) {
        return 1;
    }
    int key = mask * 2 + (prefixSmaller ? 1 : 0);
    if (!memo.count(key)) {
        int res = 0;
        int lowerBound = mask == 0 ? 1 : 0;
        int upperBound = prefixSmaller ? 9 : nStr[popcount((unsigned int)mask)] - '0';
        for (int i = lowerBound; i <= upperBound; i++) {
            if (((mask >> i) & 1) == 0) {
                res += dp(mask | (1 << i), prefixSmaller || i < upperBound, nStr);
            }
        }
        memo[key] = res;
    }
    return memo[key];
}

int countSpecialNumbers(int n) {
	string num = to_string(n);
	int res = 0;
	int prod = 9;
	for (int i = 0; i < (int)num.length() - 1; ++i) {
		res += prod;
		prod *= 9 - i;
	}
    res += dp(0, false, num);
	return res;
}

int main() {
	int n = 20;
	cout << countSpecialNumbers(n) << "\n";
}