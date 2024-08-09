#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int addedInteger(vector<int>& nums1, vector<int>& nums2) {
    int m = (int)nums1.size(), n = (int)nums2.size();
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    // 由于n = m - 2, 所以第一个数一定是nums1[0/1/2]
    for (int i : {2, 1, 0}) {
        int left = i + 1, right = 1;
        while (left < m && right < n) {
            if (nums1[left] - nums2[right] == nums1[i] - nums2[0]) {
                ++right;
            }
            ++left;
        }
        if (right == n) {
            return nums2[0] - nums1[i];
        }
    }
    return 0;
}

int main() {
	vector nums1{ 4,20,16,12,8 };
	vector nums2{ 14,18,10 };
	int res = addedInteger(nums1, nums2);
	cout << res << "\n";
}