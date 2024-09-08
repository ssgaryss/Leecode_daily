#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
	transform(nums.begin(), nums.end(), nums.begin(), [](int x) {
		return x * x;
		});
	sort(nums.begin(), nums.end());
	return nums;
}

int main() {
	vector nums{ -4,-1,0,3,10 };
	auto res = sortedSquares(nums);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
}