#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numberGame(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i += 2) {
		swap(nums[i], nums[i + 1]);
	}
	return nums;
}

int main() {
	vector<int> nums{ 5,4,2,3 };
	vector<int> res = numberGame(nums);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
}