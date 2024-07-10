#include <iostream>
#include <vector>
using namespace std;

int incremovableSubarrayCount(vector<int>& nums) {
	int n = nums.size();
	int i = 0, j = n - 1;
	while (i < n - 1) {
		if (nums[i] < nums[i + 1])
			++i;
		else
			break;
	}
	int res = 0;
	if (i == n - 1)
		return (n * (n + 1)) / 2;

	res += i + 2; // ÓÒ°ë²¿·ÖÎª¿Õ
	while (j > 0) {
		if (i < 0 || nums[j] > nums[i])
			res += i + 2;
		else {
			while (i >= 0 && nums[j] <= nums[i])
				--i;
			res += i + 2;
		}

		if (nums[j] > nums[j - 1])
			--j;
		else
			break;
	}
	return res;
}

int main() {
	vector nums{ 9,2,5 };
	int res = incremovableSubarrayCount(nums);
	cout << res << "\n";
}