#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int minimumSubstringsInPartition(string s) {
	int n = (int)s.length();
	vector<int> dp(n + 1, 100000);
	dp[0] = 0;
	unordered_map<char, int> count;
	for (int i = 1; i <= n; ++i) {
		int max_count = 0;
		count.clear();
		for (int j = i; j >= 1; --j) {
			count[s[j - 1]]++;
			max_count = max(max_count, count[s[j - 1]]);
			if (max_count * (int)count.size() == i - j + 1 && dp[j - 1] != 100000) {
				dp[i] = min(dp[i], dp[j - 1] + 1);
			}
		}
	}
	return dp[n];
}

int main() {
	string s = "fabccddg";
	int res = minimumSubstringsInPartition(s);
	cout << res << "\n";
}