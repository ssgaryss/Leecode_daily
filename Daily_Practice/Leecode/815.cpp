#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
	if (source == target)
		return 0;

	int n = (int)routes.size();
	vector<vector<bool>> edge(n, vector<bool>(n)); // ��ͬ������·֮�����ͨ���
	unordered_map<int, vector<int>> rec;           // rec��ÿ������վ��Ӧ��Щ������·�ɵ���
	for (int i = 0; i < n; ++i) {
		for (int site : routes[i]) {
			for (int j : rec[site]) {
				edge[i][j] = edge[j][i] = true;
			}
			rec[site].emplace_back(i);
		}
	}

	// BFS
	vector<int> dis(n, -1);
	queue<int> q;
	for (int site : rec[source]) {              // ��ʼ��BFS���ڵ�
		dis[site] = 1;
		q.push(site);
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y = 0; y < n; ++y) {
			if (edge[x][y] && dis[y] == -1) {
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
	}

	// �ҵ���Сdis
	int res = INT_MAX;
	for (int route : rec[target]) {
		if (dis[route] != -1)
			res = min(res, dis[route]);
	}
	return res == INT_MAX ? -1 : res;
}

int main() {
	vector<vector<int>> routes{
		{1,2,7},
		{3,6,7}
	};
	int source = 1, target = 6;
	cout << numBusesToDestination(routes, source, target) << "\n";
}