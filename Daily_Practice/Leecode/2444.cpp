#include <iostream>
#include <vector>

using namespace std;

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
	long long Num = 0;
	int Left = -1, Right = -1; 
	int border = -1;
	for (int i = 0; i < (int)nums.size(); ++i) {
		if (nums[i] > maxK || nums[i] < minK) {
			border = i;
			Left = -1, Right = -1;
			continue;
		}
		else {
			if (nums[i] == minK)
				Left = i;
			if (nums[i] == maxK)
				Right = i;
			if (Left != -1 && Right != -1) {
				Num += min(Left, Right) - border;
			}
		}
	}
	return Num;
}


int main(int argc, char* argv[]) {
	vector<int> nums{ 1,3,5,2,7,5 };
	constexpr int minK = 1, maxK = 5;
	auto res = countSubarrays(nums, minK, maxK);
	cout << res << "\n";
}