#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int numberOfPoints(vector<vector<int>>& nums) {
	int n = (int)nums.size();
	sort(nums.begin(), nums.end());
	int res = nums[0][1] - nums[0][0] + 1;
	int flag = nums[0][1];  // 当前最大的节点
	for (int i = 1; i < n; ++i) {
		if (nums[i][0] <= flag && nums[i][1] > flag)
			res += nums[i][1] - flag;
		else if (nums[i][0] > flag)
			res += nums[i][1] - nums[i][0] + 1;
		flag = max(flag, nums[i][1]);
	}
	return res;
}

int main() {
	vector<vector<int>> nums{ {2,3},{1,7},{1,8},{7,9},{1,5} };
	cout << numberOfPoints(nums) << "\n";
}
