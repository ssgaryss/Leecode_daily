#include <iostream>
#include <vector>
using namespace std;

int maxCoins(vector<int>& nums) { // 动态规划
	int n = nums.size();
	vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0)); // dp[i][j] 代表从[i, j]中插入气球产生的最大值
	vector<int> numsForDP;
	numsForDP.reserve(n + 2);
	numsForDP.emplace_back(1);
	std::copy(nums.begin(), nums.end(), std::back_inserter(numsForDP));
	numsForDP.emplace_back(1);
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 2; j < n + 2; ++j) {
			for (int k = i + 1; k < j; ++k) {
				int sum = numsForDP[i] * numsForDP[k] * numsForDP[j];
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + sum);
			}
		}
	}

	return dp[0][n + 1];
}

int main() {
	vector<int> nums{ 3,1,5,8 };
	int maxNums = maxCoins(nums);
	cout << maxNums << "\n";
}