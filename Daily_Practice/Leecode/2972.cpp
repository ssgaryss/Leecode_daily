#include <iostream>
#include <vector>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	return 0;
}() };

long long incremovableSubarrayCount(vector<int>& nums) {
	int n = nums.size();
	int i = 0, j = n - 1;
	while (i < n - 1) {
		if (nums[i] < nums[i + 1])
			i++;
		else
			break;
	}
	if (i == n - 1)
		return (n * (1 + n)) / 2;
	long long res = 0LL;
	res += (long long)i + 2;
	while (j > 0) {
		while (i >= 0) {
			if (nums[i] >= nums[j])
				--i;
			else
				break;
		}
		res += (long long)i + 2;
		if (j - 1 >= 0 && nums[j] > nums[j - 1])
			--j;
		else
			break;
	}
	return res;
}

int main() {
	vector nums{ 9,9 };
	auto res = incremovableSubarrayCount(nums);
	cout << res << "\n";
}