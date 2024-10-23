#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int smallestRangeI(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());
	return nums.front() + 2 * k >= nums.back() ? 0 : (nums.back() - nums.front() - 2 * k);
}

int main(int argc, char** argv) {
	vector nums{ 1,3,6 };
	int k = 3;
	cout << smallestRangeI(nums, k) << "\n";
}