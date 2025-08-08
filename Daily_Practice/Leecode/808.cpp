#include <iostream>
#include <vector>
using namespace std;

double soupServings(int n) {
	double res = 0.0;
	int all = static_cast<int>(std::ceil(static_cast<double>(n) / 25.0));
	if (all >= 179)
		return 1.0; // 此时概率已经无限接近1.0，且误差小于10^-5
    vector<vector<double>> dp(all + 1, vector<double>(all + 1));
    dp[0][0] = 0.5;
    for (int i = 1; i <= all; i++) {
        dp[0][i] = 1.0;
    }
    for (int i = 1; i <= all; i++) {
        for (int j = 1; j <= all; j++) {
            dp[i][j] = (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][max(0, j - 1)] +
                dp[max(0, i - 2)][max(0, j - 2)] + dp[max(0, i - 1)][max(0, j - 3)]) / 4.0;
        }
    }
    return dp[all][all];
}

int main() {
	int n = 0;
	cin >> n;
	auto res = soupServings(n);
	cout << res << "\n";
}