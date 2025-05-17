#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>

using namespace std;

void sortColors(vector<int>& nums) {
	//std::sort(nums.begin(), nums.end());
	int n = static_cast<int>(nums.size());
	unordered_map<int, int> count;
	for (int i = 0; i < n; ++i) {
		count[nums[i]]++;
	}
	nums.clear();
	nums.insert(nums.end(), count[0], 0);
	nums.insert(nums.end(), count[1], 1);
	nums.insert(nums.end(), count[2], 2);
}

int main(int argc, char** argv) {
	vector<int> nums{ 2,0,2,1,1,0 };
	std::cout << "Input: ";
	std::copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
	std::cout << "\n";
	sortColors(nums);
	std::cout << "Output: ";
	std::copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
	std::cout << "\n";
	return 0;
}