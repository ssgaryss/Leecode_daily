#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;

bool canPartitionKSubsets(vector<int>& nums, int k) {
	int sum = reduce(nums.begin(), nums.end());
	if (sum % k > 0)
		return false;
	int average = sum / k;
	sort(nums.begin(), nums.end());
	if (nums.back() > average)
		return false;
    int n = nums.size();
    vector<bool> dp(1 << n, true);
    function<bool(int, int)> dfs = [&](int s, int p)->bool {
        if (s == 0) {
            return true;
        }
        if (!dp[s]) {
            return dp[s];
        }
        dp[s] = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] + p > average) {
                break;
            }
            if ((s >> i) & 1) {
                if (dfs(s ^ (1 << i), (p + nums[i]) % average)) {
                    return true;
                }
            }
        }
        return false;
        };
    return dfs((1 << n) - 1, 0);
}

int main() {
	vector nums{ 4, 3, 2, 3, 5, 2, 1 };
	int k = 4;
	auto res = canPartitionKSubsets(nums, k);
	cout << boolalpha << res << "\n";
}