#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> group(n, vector<int>(m, -1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int value;
			cin >> value;
			group[i][j] = value;
		}
		sort(group[i].begin(), group[i].end());
	}
	sort(group.begin(), group.end(), [](const auto& a, const auto& b) {
		return a[0] < b[0];
		});

	function<int()> process = [&]() -> int {
		// [i, j]范围内的最小极差
		vector<vector<int, int>> dp;
		int Mininimum = group[0][0];
		int Maximum = group[n-1][m-1];
		dp[0][0] = group[n - 1][m - 1] - group[0][0];
		int res = Maximum - Mininimum;
		for (int i = 0; i < m; ++i) {

		}
		return res;
		};
	auto res = process();
	cout << res;
}