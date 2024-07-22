#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <bitset>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int maximumDetonation(vector<vector<int>>& bombs) {
	int res = 0;
	int n = bombs.size();
	bool (*calculate)(vector<int>, vector<int>) = [](vector<int> a, vector<int> b) {
		return pow((a[0] - b[0]), 2) + pow((a[1] - b[1]), 2) <= pow(a[2], 2);
		};
	vector<bitset<100>> detonate(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (calculate(bombs[i], bombs[j]))
				detonate[i].set(j);
		}
	}
	for (int i = 0; i < n; ++i) {
		int temp = 1;
		vector<int> exploded(n);
		queue<int> q;
		q.push(i);
		exploded[i] = 1;
		while (!q.empty())
		{
			int k = q.front();
			q.pop();
			for (int j = 0; j < n; ++j) {
				if (detonate[k].test(j)) {
					if (exploded[j] == 1)
						continue;
					temp++;
					q.push(j);
					exploded[j] = 1;
				}
			}
		}
		res = max(res, temp);
	}
	return res;
}

int main() {
	vector<vector<int>> bombs{
		{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}
	};
	int res = maximumDetonation(bombs);
	cout << res << "\n";
}