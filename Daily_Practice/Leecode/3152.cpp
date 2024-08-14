#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	return 0;
}() };

vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
	int n = (int)nums.size();
	// dp[j] : 以index j结尾的最长特殊数组
	vector<int> dp(n, 1);
	for (int i = 1; i < n; ++i) {
		if (!((nums[i] + nums[i - 1]) % 2))
			dp[i] = 1;
		else
			dp[i] = dp[i - 1] + 1;
	}
	vector<bool> res(queries.size(), true);
	for (int i = 0; i < (int)res.size(); ++i) {
		if (dp[queries[i][1]] < queries[i][1] - queries[i][0] + 1)
			res[i] = false;
	}
	return res;
}

int main() {
	vector nums{ 3,4,1,2,6 };
	vector<vector<int>> queries{
		{ 0,4 }
	};
	auto res = isArraySpecial(nums, queries);
	cout << boolalpha;
	copy(res.begin(), res.end(), ostream_iterator<bool>(cout, " "));
	cout << noboolalpha;
}
