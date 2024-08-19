#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int checkRecord(int n) {
    int Mod = (int)(1e9 + 7);
    // dp[i][j][k] : 长(n), A数目(0和1), 连续L数目(0和1和2)
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[i][j][0] += dp[i - 1][j][k];     // 第i天为P
                dp[i][j][0] %= Mod;
            }
        }
        for (int k = 0; k < 3; ++k) {
            dp[i][1][0] += dp[i - 1][0][k];         // 第i天为A
            dp[i][1][0] %= Mod;
        }
        for (int j = 0; j < 2; ++j) {
            for (int k = 1; k < 3; ++k) {
                dp[i][j][k] += dp[i - 1][j][k - 1]; //第i天为L
                dp[i][j][k] %= Mod;
            }
        }
    }
    int res = 0;
    for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 3; ++k) {
            res = (res + dp[n][j][k]) % Mod;
        }
    }
    return res;
}

int main() {
	int n = 10101;
	auto res = checkRecord(n);
	cout << res << "\n";
}