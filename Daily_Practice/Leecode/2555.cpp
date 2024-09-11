#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int maximizeWin(vector<int>& prizePositions, int k) {
	int n = (int)prizePositions.size();
	vector<int> dp(n + 1);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int x = (int)(lower_bound(prizePositions.begin(), prizePositions.end(), prizePositions[i] - k) - prizePositions.begin());
		res = max(res, dp[x] + i - x + 1);
		dp[i + 1] = max(dp[i], i - x + 1);
	}
	return res;
}

int main() {
	vector prizePositions{ 1,1,2,2,3,3,5 };
	int k = 2;
	cout << maximizeWin(prizePositions, k) << "\n";
}