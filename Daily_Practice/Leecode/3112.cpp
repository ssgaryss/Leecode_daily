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
	// ��С��,Դ�ڵ㵽�ýڵ����̾���
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, 0);
	vector<int> res(n, -1);
	res[0] = 0;
	// dijkstra ����Ҫ�ж�
	while (!pq.empty())
	{
		auto [u, v] = pq.top(); // uΪ���ȣ�vΪ�ڵ㣬��v����С����Ϊu
		pq.pop();
		if (u != res[v]) // ��������ظ��ڵ�
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