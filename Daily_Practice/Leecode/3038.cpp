#include <iostream>
#include <vector>
using namespace std;

int maxOperations(vector<int>& nums) {
	int score = nums[0] + nums[1];
	int temp = 0;
	int maxNum = 0;
	for (int i = 0; i < std::ssize(nums); ++i) {
		temp += nums[i];
		if (i % 2 == 1) {
			if (temp == score)
				maxNum++;
			else
				return maxNum;
			temp = 0;
		}
	}
	return maxNum;
}

int main() {
	vector<int> nums{ 2,2,3,2,4,2,3,3,1,3 };
	int maxNum = maxOperations(nums);
	cout << maxNum << "\n";
}