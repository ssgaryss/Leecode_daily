#include <iostream>
#include <vector>
using namespace std;

long long sumDigitDifferences(vector<int>& nums) {
    long long res = 0;
    int n = nums.size();
    while (nums[0] > 0) {
        vector<int> cnt(10);
        for (int i = 0; i < n; i++) {
            cnt[nums[i] % 10]++;
            nums[i] /= 10;
        }
        for (int i = 0; i < 10; i++) {
            res += (long long)(n - cnt[i]) * cnt[i];
        }
    }
    return res / 2;
}

int main() {
	vector nums{ 13,23,12 };
	cout << sumDigitDifferences(nums) << "\n";
}