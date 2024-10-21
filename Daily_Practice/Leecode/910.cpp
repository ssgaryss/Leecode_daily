#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int smallestRangeII(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int mi = nums[0], ma = nums.back();
    int res = ma - mi;
    for (int i = 0; i < nums.size() - 1; i++) {
        int a = nums[i], b = nums[i + 1];
        res = min(res, max(ma - k, a + k) - min(mi + k, b - k));
    }
    return res;
}

int main() {
	vector nums{ 1,3,6 };
	int k = 3;
	cout << smallestRangeII(nums, k) << "\n";
}