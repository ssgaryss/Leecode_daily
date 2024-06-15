#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumBeauty(vector<int>& nums, int k) {
	int n = nums.size();
	sort(begin(nums), end(nums));
	int maxBeauty = 0;
	int i = 0, j = 0;
	while (i < n) {
		while (j < n && nums[j] - 2 * k <= nums[i]) {
			j++;
		}
		maxBeauty = max(maxBeauty, j - i);
		i++;
	}
	return maxBeauty;
}

int main() {
	vector<int> nums{ 4,6,1,2 };
	int  k = 2;
	int res = maximumBeauty(nums, k);
	cout << res << "\n";
}