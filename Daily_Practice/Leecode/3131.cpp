#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int addedInteger(vector<int>& nums1, vector<int>& nums2) {
	return *min_element(nums2.begin(), nums2.end()) - *min_element(nums1.begin(), nums1.end());
}

int main() {
	vector nums1{ 2,6,4 };
	vector nums2{ 9,7,5 };
	int res = addedInteger(nums1, nums2);
	cout << res << "\n";
}