#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
    long long res = 0;
    int n = static_cast<int>(nums.size());
    int Max = *std::max_element(nums.begin(), nums.end());
    int count = 0;
    queue<int> idxQueue;
    int lastPos = 0;

    for (int i = 0; i < n; ++i) {
        if (nums[i] == Max) {
            count++;
            idxQueue.emplace(i);
        }
        if (count >= k) {
            int firstIdx = idxQueue.front(); // 取队头索引
            idxQueue.pop();                  // 出队
            res += static_cast<long long>(n - i) * (firstIdx + 1 - lastPos);
            lastPos = firstIdx + 1;
            count--;
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
	std::vector<int> nums{ 1,3,2,3,3 };
	int k = 2;
	auto res = countSubarrays(nums, k);
	std::cout << res << "\n";
}