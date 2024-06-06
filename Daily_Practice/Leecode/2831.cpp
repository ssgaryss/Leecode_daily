#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestEqualSubarray(vector<int>& nums, int k) {
	int res = 0;
	unordered_map<int, vector<size_t>> pos; //记录不同元素所有出现下标
	for (size_t i = 0; i < nums.size(); ++i) {
		pos[nums[i]].emplace_back(i);
	}
	//找出每个元素最长等值子数组
	for (auto& [_, vec] : pos) {
		for (size_t i = 0, j = 0; i < vec.size(); ++i) {
			//i为最右侧的index，j为左侧，如果k不够了才移动左边(滑动窗口)
			while (vec[i] - vec[j] - (i - j) > k) {
				j++;
			}
			res = max(res, static_cast<int>(i - j + 1));
		}
	}
	return res;
}

int main() {
	vector<int> nums{ 1,3,2,3,1,3 };
	int k = 3;
	int res = longestEqualSubarray(nums, k);
	cout << res;
}