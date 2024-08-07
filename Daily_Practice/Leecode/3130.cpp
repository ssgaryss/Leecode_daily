#include <iostream>
#include <vector>
using namespace std;

int numberOfStableArrays(int zero, int one, int limit) {
	// dp
	int res = 0;
	int mod = 1e9 + 7;
	vector<vector<int>> dp0(zero + 1, vector<int>(one + 1));
	vector<vector<int>> dp1(zero + 1, vector<int>(one + 1));
	for (int i = 0; i <= min(zero, limit); ++i)
		dp0[i][0] = 1;
	for (int i = 0; i <= min(one, limit); ++i)
		dp1[0][i] = 1;
	for (int i = 1; i <= zero; ++i) {
		for (int j = 1; j <= one; ++j) {
			if (i <= limit)
				dp0[i][j] = (dp0[i - 1][j] + dp1[i - 1][j]) % mod;
			else
				dp0[i][j] = (dp0[i - 1][j] + dp1[i - 1][j] - dp1[i - 1 - limit][j]) % mod; // dp1[i - 1 - limit][j]表示以1结尾再连续添加limit + 1个0的非法方案数

			if (j <= limit)
				dp1[i][j] = (dp0[i][j - 1] + dp1[i][j - 1]) % mod;
			else
				dp1[i][j] = (dp0[i][j - 1] + dp1[i][j - 1] - dp0[i][j - 1 - limit]) % mod;
			dp0[i][j] = (dp0[i][j] + mod) % mod;
			dp1[i][j] = (dp1[i][j] + mod) % mod;
		}
	}
	return (dp0[zero][one] + dp1[zero][one]) % mod;
}

int main() {
	int zero = 1, one = 2, limit = 2;
	auto res = numberOfStableArrays(zero, one, limit);
	cout << res << "\n";
}