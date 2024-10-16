#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

double minimumAverage(vector<int>& nums) {
	int n = (int)nums.size();
	sort(nums.begin(), nums.end());
	double res = std::numeric_limits<double>::max();
	for (int i = 0; i < n / 2; ++i)
		res = min(res, nums[i] * 0.5 + nums[n - 1 - i] * 0.5);
	return res;
}

int main() {
	vector nums{ 7,8,3,4,15,13,4,1 };
	cout << minimumAverage(nums) << "\n";
}