#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());
    auto check = [&](int mx) -> bool {
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] - nums[i] <= mx) {
                cnt++;
                i++;
            }
        }
        return cnt >= p;
        };
    int left = 0, right = nums.back() - nums[0];
    while (left < right) {
        int mid = (left + right) >> 1;
        if (check(mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int main(int argc, char** argv) {
	vector nums{ 0,5,3,4 };
	int p = 0;
	auto res = minimizeMax(nums, p);
	cout << res << "\n";
}