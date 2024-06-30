#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

//// 超出时间限制O(2^n)
//int findTargetSumWays(vector<int>& nums, int target) {
//	int n = nums.size();
//	int res = 0;
//	//using recursive = void (*)(int, int);
//	function<void(int, int)> recurFunc = [&](int index, int value) {
//		if (index < n) {
//			recurFunc(index + 1, value + nums[index]);
//			recurFunc(index + 1, value - nums[index]);
//		}
//		else {
//			if (value == target)
//				res++;
//		}
//		};
//	recurFunc(0, 0);
//	return res;
//}

// dp
int findTargetSumWays(vector<int>& nums, int target) {
    std::unordered_map<int, int> dp; // dp[value] 表示能够得到该 value 的方法数
    dp[0] = 1;

    for (int num : nums) {
        std::unordered_map<int, int> next_dp;
        for (const auto& [value, count] : dp) {
            next_dp[value + num] += count;
            next_dp[value - num] += count;
        }
        dp = std::move(next_dp);
    }

    return dp[target];
}

int main() {
	vector<int> nums{ 0,17,5,0,0,18,18,28,36,29,42,4,32,2,5,31,24,30,8,6 };
	int target = 27;
	auto res = findTargetSumWays(nums, target);
	cout << res << "\n";
}