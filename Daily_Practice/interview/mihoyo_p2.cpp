// 第二题是，现在一个字符串由L、R、LL、RR组成，现在给定一个由L和R组成的字符串，判断有几种组合方式
// eg.RRR = 3, RRRR = 5, LRLR = 1，LLRL = 2

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countWays(const string& s) {
	int n = static_cast<int>(s.size());
	vector<int> dp(n + 1, 0);
	dp[0] = 1;

	vector<string> dict = { "L", "R", "LL", "RR" };

	for (int i = 1; i <= n; i++) {
		for (auto& w : dict) {
			int len = static_cast<int>(w.size());
			if (i >= len && s.substr(i - len, len) == w) {
				dp[i] += dp[i - len];
			}
		}
	}

	return dp[n];
}

int main() {
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		cout << countWays(s) << endl; // 输出 3
	}
	return 0;
}

