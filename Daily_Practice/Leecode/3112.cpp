#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
	vector<vector<pair<int, int>>> d(n);
	for (const auto& edge : edges) {
		int u = edge[0], v = edge[1], length = edge[2];
		d[u].emplace_back(v, length);
		d[v].emplace_back(u, length);
	}
	// 最小堆,源节点到该节点的最短距离
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, 0);
	vector<int> res(n, -1);
	res[0] = 0;
	// dijkstra 但需要判断
	while (!pq.empty())
	{
		auto [u, v] = pq.top(); // u为长度，v为节点，到v的最小距离为u
		pq.pop();
		if (u != res[v]) // 避免计算重复节点
			continue;
		for (auto& [v, length] : d[v]) {
			if (length + u < disappear[v] && (res[v] == -1 || length + u < res[v])) {
				res[v] = length + u;
				pq.emplace(res[v], v);
			}
		}
	}

	return res;
}

int main() {
	int n = 3;
	vector<vector<int>> edges{
		{0,1,2},
		{1,2,1},
		{0,2,4}
	};
	vector<int> disappear{ 1,1,5 };
	auto res = minimumTime(n, edges, disappear);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
}