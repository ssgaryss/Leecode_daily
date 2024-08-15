#include <iostream>
#include <vector>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int maxScore(vector<vector<int>>& grid) {
	int m = (int)grid.size();
	int n = (int)grid[0].size();
	// 得分只和起点和终点有关
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, -100000)); // 区域外的正方形矩阵最小值
	for (int i = m - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			dp[i][j] = max({ dp[i][j + 1], dp[i + 1][j], grid[i][j] });
		}
	}
	int res = INT_MIN;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			res = max({ res, dp[i + 1][j] - grid[i][j], dp[i][j + 1] - grid[i][j] });
		}
	}
	return res;
}

int main() {
	vector<vector<int>> grid{
		{9, 5, 7, 3},
		{8, 9, 6, 1},
		{6, 7,14, 3},
		{2, 5, 3, 1}
	};
	auto res = maxScore(grid);
	cout << res << "\n";
}