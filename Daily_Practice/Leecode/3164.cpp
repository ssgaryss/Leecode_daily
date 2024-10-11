#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	long long res = 0;
	unordered_map<int, int> count1, count2;
	int maxNum1 = 0;
	for (auto it : nums1) {
		maxNum1 = max(maxNum1, it);
		count1[it]++;
	}
	for (auto it : nums2)
		count2[it]++;
	for (const auto& it : count2) {
		for (int i = 1; i * it.first * k <= maxNum1; ++i) {
			if (count1.count(it.first * k * i))
				res += 1LL * count1[it.first * k * i] * it.second; 
		}
	}

	return res;
}

int main() {
	vector nums1{ 1,3,4 };
	vector nums2{ 1,3,4 };
	int k = 1;
	cout << numberOfPairs(nums1, nums2, k) << "\n";
}