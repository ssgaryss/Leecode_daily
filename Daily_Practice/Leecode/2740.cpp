#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int findValueOfPartition(vector<int>& nums) {
	int n = (int)nums.size();
	sort(nums.begin(), nums.end(), greater<>());
	int res = INT_MAX;
	for (int i = 0; i < n - 1; ++i) {
		res = min(res, nums[i] - nums[i + 1]);
	}
	return res;
}

int main() {
	vector nums{ 100,1,10 };
	int res = findValueOfPartition(nums);
	cout << res << "\n";
}