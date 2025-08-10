#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	// -1 : 障碍物
	vector<vector<int>> RouteMap(n, vector<int>(m, -1));
	unordered_map<int, int> GoldValue(k);
	pair<int, int> StartPoint;
	for (int i = 0; i < n; ++i) {
		string Value;
		cin >> Value;
		for (int j = 0; j < static_cast<int>(Value.size()); ++j) {
			if (Value[j] == 'S') {
				StartPoint = { i, j };
			}
			else if (Value[j] == '#') {
				RouteMap[i][j] = -1;
			}
			else if (Value[j] == '.') {
				RouteMap[i][j] = 0;
			}
			else {
				RouteMap[i][j] = Value[j] - '0';
			}
		}
	}
	vector<pair<int, int>> GoldNumber2Value;
	for (int i = 0; i < k; ++i) {
		int Value = 0;
		cin >> Value;
		GoldValue[i + 1] = Value;
		GoldNumber2Value.emplace_back(i, Value);
	}
	sort(GoldNumber2Value.begin(), GoldNumber2Value.end(), [](const auto& a, const auto& b) {
		return a.second < b.second;
		});

	// 先采集a-1个值最大的金矿
	// 再保证之后的路径规划最短路径获得最大收益
	int res = 0;



}