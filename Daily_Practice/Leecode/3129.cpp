#include <iostream>
#include <vector>
using namespace std;

int numberOfStableArrays(int zero, int one, int limit) {
	// dp1[i][j]表示填入i个0和j个1且最后填入为1的可行总方案数
	// dp0[i][j]表示填入i个0和j个1且最后填入为0的可行总方案数
	// 而可行的方案可等价为所有长为limit + 1的子数组同时有0或1的情况
	vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0));
	vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0));
	constexpr long long mod = 1e9 + 7;
	for (int i = 0; i <= std::min(zero, limit); ++i)
		dp0[i][0] = 1; // 只有一种可行方案
	for (int i = 0; i <= std::min(one, limit); ++i)
		dp1[0][i] = 1; // 只有一种可行方案
	for (int i = 1; i <= zero; ++i) {
		for (int j = 1; j <= one; ++j) {
			if (i <= limit)  // 此时总方案数就是可行的方案数
				dp0[i][j] = (dp0[i - 1][j] + dp1[i - 1][j]) % mod;
			if (j <= limit)  // 此时总方案数就是可行的方案数
				dp1[i][j] = (dp0[i][j - 1] + dp1[i][j - 1]) % mod;
			// i > limit时,对于dp[i-1][j]再加入一个0,只有当末尾有连续i-1个0时会存在不可行方案,即不可行方案为dp1[i-1-limit][j]
			if (i > limit)  // 此时总方案数减去不可行方案数
				dp0[i][j] = (dp0[i - 1][j] + dp1[i - 1][j] - dp1[i - 1 -limit][j]) % mod;
			// j > limit时,对于dp[i][j-1]再加入一个1,只有当末尾有连续j-1个1时会存在不可行方案,即不可行方案为dp0[i][j-1-limit]
			if (j > limit)  // 此时总方案数减去不可行方案数
				dp1[i][j] = (dp0[i][j - 1] + dp1[i][j - 1] - dp0[i][j - 1 - limit]) % mod;
			// 由于之前取模运算导致可能出现负数
			dp0[i][j] = (dp0[i][j] % mod + mod) % mod;
			dp1[i][j] = (dp1[i][j] % mod + mod) % mod;
		}
	}

	return (dp0[zero][one] + dp1[zero][one]) % mod;
}

int main() {
	int zero = 3, one = 3, limit = 2;
	int res = numberOfStableArrays(zero, one, limit);
	cout << res << "\n";
}