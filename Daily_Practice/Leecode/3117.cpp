#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

static const int INF = (1 << 20) - 1; // 保证全1
vector<unordered_map<int, int>> memo; // 记忆化搜索

int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
	int m = (int)nums.size(), n = (int)andValues.size();
	memo.resize(n * m); // k = i * n + j 记录到andValues[j]，nums[i]已有的最小值
	function<int(int, int, int, vector<int>, vector<int>)> dfs = [&dfs](int i, int j, int cur, const vector<int>& nums, const vector<int>& andValues) {
		int m = (int)nums.size(), n = (int)andValues.size(), k = i * n + j;
		if (i == m && j == n)
			return 0;
		if (i == m || j == n)
			return INF;
		if (memo[k].count(cur))
			return memo[k][cur];
		cur &= nums[i];
		if (cur < andValues[j])
			return INF;
		int res = dfs(i + 1, j, cur, nums, andValues);
		if (cur == andValues[j])
			res = min(res, dfs(i + 1, j + 1, INF, nums, andValues) + nums[i]);
		memo[k][cur] = res;
		return res;
		};
	int res = dfs(0, 0, INF, nums, andValues);
	return res < INF ? res : -1;
}

int main() {
	vector nums{ 1,3,10 };
	vector andValues{ 0 };
	auto res = minimumValueSum(nums, andValues);
	cout << res << "\n";
}