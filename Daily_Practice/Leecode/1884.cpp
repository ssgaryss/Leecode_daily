#include <iostream>
#include <vector>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int twoEggDrop(int n) {
	//dp
	vector<int> dp((size_t)n + 1, INT_MAX / 2);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= i; ++k) {
			dp[i] = min(dp[i], max(k - 1, dp[(size_t)i - k]) + 1);
		}
	}
	return dp[n];
}

int main() {
	int n = 2;
	cout << twoEggDrop(n) << "\n";
}