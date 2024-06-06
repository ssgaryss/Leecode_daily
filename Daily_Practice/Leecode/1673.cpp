#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
using namespace std;

//vector<int> mostCompetitive(vector<int>& nums, int k) {
//	//只需要遍历最小元素（并保证其后面有足够元素）
//	//若存在多个同样小的元素，取前面那个元素，因为后面开始的子序列，前面的一定也可以
//	vector<int> res{};
//	pair<int, int> minCurrent{ make_pair(INT_MAX, -1) };
//	for (int j = 0; j < k; ++j) {
//		for (int i = minCurrent.second + 1; i < nums.size() - k + j + 1; ++i) {
//			if (res.size() != 0 && nums[nums.size() - k + j] < res[j - 1]) {
//				minCurrent.first = nums[nums.size() - k + j];
//				minCurrent.second = nums.size() - k + j;
//				break;
//			}
//			else {
//				if (res.size() != 0 && nums[i] == res[j - 1]) {
//					minCurrent.first = nums[i];
//					minCurrent.second = i;
//					break;
//				}
//			}
//			if (minCurrent.first > nums[i]) {
//				minCurrent.first = nums[i];
//				minCurrent.second = i;
//			}
//		}
//		res.emplace_back(minCurrent.first);
//		minCurrent.first = INT_MAX;
//	}
//	return res;
//}

vector<int> mostCompetitive(vector<int>& nums, int k) {
	vector<int> res{};
	int n = nums.size();
	for (int i = 0; i < n; ++i) {
		while (!res.empty() && i - res.size() + k < n && res.back() > nums[i])
		{
			res.pop_back();
		}
		res.emplace_back(nums[i]);
	}
	res.resize(k);
	return res;
}

int main() {
	vector<int> nums{ 1,1,1,1,1,1,1,1,0,0 };
	int k = 5;
	vector<int> res{ mostCompetitive(nums, k) };
}