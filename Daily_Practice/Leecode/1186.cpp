#include <iostream>
#include <vector>
using namespace std;

auto _{ []()noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int maximumSum(vector<int>& arr) {
	// dp[i][k] 以arr[i]结尾(删除前)且删除k个元素的最大非空子数组之和
	// 优化为dp0 dp1记录上一次的结果，不需要记录所有dp
	int n = arr.size();
	int dp0 = arr[0], dp1 = -1000000;
	int res = max(dp0, dp1);
	for (int i = 1; i < n; ++i) {
		dp1 = max(dp0, dp1 + arr[i]);
		dp0 = max(dp0, 0) + arr[i];
		res = max({ dp0, dp1, res });
	}
	return res;
}

int main() {
	vector arr{ 1,-2,-2,3 };
	int res = maximumSum(arr);
	cout << res << "\n";
}