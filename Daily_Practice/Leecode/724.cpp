#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int pivotIndex(vector<int>& nums) {
	int n = nums.size();
	int left = 0;
	int right = reduce(nums.begin(), nums.end()) - nums[0];
	for (int i = 0; i < n - 1; ++i) {
		if (left == right)
			return i;
		left += nums[i];
		right -= nums[i + 1];
	}
	if (left == right)
		return n - 1;
	return -1;
}

int main() {
	vector<int> nums{ -1,-1,0,1,1,0 };
	int res = pivotIndex(nums);
	cout << res << "\n";
}