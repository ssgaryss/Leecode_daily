#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	return 0;
}() };

int countWays(vector<int>& nums) {
	int n = (int)nums.size();
	sort(nums.begin(), nums.end());
	int res = 0;
	if (nums[0] > 0) res++;
	if (nums[n - 1] < n) res++;
	for (int i = 0; i < n - 1; ++i) {
		if (nums[i] < i + 1 && nums[i + 1] > i + 1)
			res++;
	}
	return res;
}

int main() {
	vector nums{ 6,0,3,3,6,7,2,7 };
	cout << countWays(nums) << "\n";
}