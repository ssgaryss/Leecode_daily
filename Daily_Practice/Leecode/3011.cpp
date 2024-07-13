#include <iostream>
#include <vector>
#include <iomanip>
#include <bit>
using namespace std;

bool canSortArray(vector<int>& nums) {
	int n = nums.size();
    int lastCnt = 0;
    int lastGroupMax = 0;
    int curGroupMax = 0;

    for (int i = 0; i < n; i++) {
        int num = nums[i];
        int curCnt = popcount((uint32_t)num);
        if (curCnt == lastCnt) {
            curGroupMax = fmax(curGroupMax, num);
        }
        else {
            lastCnt = curCnt;
            lastGroupMax = curGroupMax;
            curGroupMax = num;
        }
        if (num < lastGroupMax) {
            return false;
        }
    }
    return true;
}

int main() {
	vector nums{ 1, 4, 3, 2 };
	auto res = canSortArray(nums);
	cout << boolalpha << res << "\n";
}