#include <iostream>
#include <vector>
using namespace std;

int maxAdjacentDistance(vector<int>& nums) {
	int res = std::abs(nums.front() - nums.back());
	int n = static_cast<int>(nums.size());
	for (int i = 0; i < n - 1; ++i) {
		res = max(res, std::abs(nums[i] - nums[i + 1]));
	}
	return res;
}

int main(int argc, char** argv) {
	vector<int> nums{ 1,2,4 };
	auto res = maxAdjacentDistance(nums);
	cout << res << "\n";
}