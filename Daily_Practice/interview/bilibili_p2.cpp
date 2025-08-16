#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

constexpr int MOD = static_cast<int>(1e9 + 7);

bool IsOdd(int n) {
	return static_cast<bool>(n % 2);
}

int main() {
	int n;
	cin >> n;
	vector<int> dp(1, 1);
	dp.emplace_back(0);
	if (n == 1) {
		cout << dp[1];
		return 0;
	}
	for (int i = 2; i <= n; ++i) {
		int temp = (dp[i - 1] + static_cast<int>(pow(26, i-1) * 25)) % MOD;
		dp.emplace_back(temp);
	}
	cout << dp[n];
}