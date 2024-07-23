#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int sumOfPowers(vector<int>& nums, int k) {
	// dp[i][p][v] ��i��β�ж��ٸ�����Ϊv�ҳ���Ϊp
	long long res = 0;
	int n = (int)nums.size();
	int MOD = 1e9 + 7;
	int inf = 0x3f3f3f3f; //�ܴ��һ������Ĭ�ϲ������������������
	vector<vector<unordered_map<int, int>>> dp(n, vector<unordered_map<int, int>>(k + 1));
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n; ++i) {
		dp[i][1][inf] = 1;
		for (int j = 0; j < i; ++j) {
			int diff = nums[i] - nums[j];
			for (int p = 2; p <= k; ++p) {
				for (auto& [v, count] : dp[j][p - 1]) {
					dp[i][p][min(diff, v)] = (dp[i][p][min(diff, v)] + count) % MOD;
				}
			}
		}
		for (auto& [v, count] : dp[i][k]) {
			res = (res + 1LL * v * count % MOD) % MOD;
		}
	}
	return static_cast<int>(res % MOD);
}

int main() {
	vector nums{ 1,2,3,4 };
	int k = 3;
	int res = sumOfPowers(nums, k);
	cout << res << "\n";
}