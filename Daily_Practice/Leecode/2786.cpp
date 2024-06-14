#include <iostream>
#include <vector>
using namespace std;

long long maxScore(vector<int>& nums, int x) {
	long long res = nums[0];
	vector<long long> dp(2, INT_MIN);
	dp[nums[0] % 2] = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
		int parity = nums[i] % 2;
		long long cur = max(dp[parity] + nums[i], dp[1 - parity] + nums[i] - x);
		res = max(res, cur);
		dp[parity] = max(dp[parity], cur);
	}
	return res;
}

int main() {
	vector<int> nums{ 2,3,6,1,9,2 };
	int x = 5;
	long long score = maxScore(nums, x);
	cout << score << '\n';
}