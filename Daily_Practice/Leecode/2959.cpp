#include <iostream>
#include <vector>
using namespace std;

int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
	int res = 0;
	vector<int> opened(n, 0);
	vector<vector<int>> d(n, vector<int>(n, 1000000));
	for (int mask = 0; mask < (1 << n); ++mask) {
		// 枚举所有情况，即把mask转换为二进制数存储到opened
		for (int i = 0; i < n; ++i) {
			opened[i] = mask & (1 << i);
		}
		fill(d.begin(), d.end(), vector<int>(n, 1000000));
		for (const auto& road : roads) {
			int i = road[0], j = road[1], r = road[2];
			if (opened[i] && opened[j]) {
				d[i][j] = d[j][i] = min(d[i][j], r); //初始化直接相连的点
			}
		}
		for (int k = 0; k < n; ++k) {
			if (opened[k]) {
				for (int i = 0; i < n; ++i) {
					if (opened[i]) {
						for (int j = i + 1; j < n; ++j) {
							if (opened[j]) {
								d[i][j] = d[j][i] = min(d[i][j], d[i][k] + d[k][j]);
							}
						}
					}
				}
			}
		}

		// 比较maxDistance
		bool isValid = true;
		for (int i = 0; i < n; ++i) {
			if (opened[i]) {
				for (int j = i + 1; j < n; ++j) {
					if (opened[j] && d[i][j] > maxDistance) {
						isValid = false;
						break;
					}
				}
				if (!isValid)
					break;
			}
		}
		if (isValid)
			res++;
	}
	return res;
}

int main() {
	vector<vector<int>> roads{
		{0,1,2},
		{1,2,10},
		{0,2,10}
	};
	int n = 3, maxDistance = 5;
	int res = numberOfSets(n, maxDistance, roads);
	cout << res << "\n";
}