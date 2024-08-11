#include <iostream>
#include <vector>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}()}
;
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
	// 其实就是寻找最长公共子序列
	int m = (int)nums1.size();
	int n = (int)nums2.size();
	vector<vector<int>> dp(m, vector<int>(n));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (nums1[i] == nums2[j])
				dp[i][j] = ((i && j) ? dp[i - 1][j - 1] : 0) + 1;
			else
				dp[i][j] = max(i ? dp[i - 1][j] : 0, j ? dp[i][j - 1] : 0);
		}
	}
	return dp.back().back();
}

int main() {
	vector nums1{ 1,4,2 };
	vector nums2{ 1,2,4 };
	auto res = maxUncrossedLines(nums1, nums2);
	cout << res << "\n";
}