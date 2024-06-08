#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int maxOperations(vector<int>& nums) {  //动态规划+递归
    int n = nums.size();
    vector<vector<int>> memo(n, vector<int>(n));
    auto helper = [&](int i, int j, int target) -> int {
        for (auto& row : memo) {
            ranges::fill(row, -1); // -1 表示没有计算过
        }
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i >= j) return 0;
            int& res = memo[i][j]; // 注意这里是引用
            if (res != -1) return 0; // 之前计算过
            res = 0;
            if (nums[i] + nums[i + 1] == target) res = max(res, dfs(i + 2, j) + 1);
            if (nums[j - 1] + nums[j] == target) res = max(res, dfs(i, j - 2) + 1);
            if (nums[i] + nums[j] == target) res = max(res, dfs(i + 1, j - 1) + 1);
            return res;
            };
        return dfs(i, j);
        };
    int res1 = helper(2, n - 1, nums[0] + nums[1]); // 删除前两个数
    int res2 = helper(0, n - 3, nums[n - 2] + nums[n - 1]); // 删除后两个数
    int res3 = helper(1, n - 2, nums[0] + nums[n - 1]); // 删除第一个和最后一个数
    return max({ res1, res2, res3 }) + 1; // 加上第一次操作
}

int main() {
	vector<int> nums{ 3,2,1,2,3,4 };
	int maxNum = maxOperations(nums);
	cout << maxNum << "\n";
}