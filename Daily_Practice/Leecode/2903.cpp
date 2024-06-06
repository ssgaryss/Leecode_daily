#include <iostream>
#include <vector>
using namespace std;

[[nodiscard("nodiscard_findIndices")]] vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
    vector<int> ans(2, -1);
    int n = nums.size();
    for (int i = 0; i < n - indexDifference; ++i) {
        for (int j = i + indexDifference; j < n; ++j) {
            if (abs(nums[i] - nums[j]) >= valueDifference) {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums{ 0 };
    vector<int> ans{ findIndices(nums,100,50) };
    cout << ans[0] << " " << ans[1] << "\n";
    cout << SIZE_MAX << "\n";
    size_t n = -1; // == SIZE_MAX
    cout << n;
}

//一定注意size（）返回的时无符号整数size_t所以没有负数