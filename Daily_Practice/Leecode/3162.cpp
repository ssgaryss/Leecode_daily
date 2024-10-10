#include <iostream>
#include <vector>
using namespace std;

int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	int res = 0;
	for (int i = 0; i < (int)nums1.size(); ++i) {
		for (int j = 0; j < (int)nums2.size(); ++j) {
			if (nums1[i] % (nums2[j] * k) == 0) {
				res++;
			}
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