#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
using namespace std;

vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
		int n = edges.size() + 1;
		vector<int> result(n);
		vector<vector<pair<int, int>>> pathData(n); //index i为i节点的pair<相邻节点, 权值>
		for (auto& it : edges) {
			pathData[it[0]].emplace_back(make_pair(it[1], it[2]));
			pathData[it[1]].emplace_back(make_pair(it[0], it[2]));
		}
		std::function<int(int, int, int)> dfs = [&](int root, int next, int weightSum) { //深度优先找出一个子树中符合要求的节点
			int res = 0;
			if (weightSum % signalSpeed == 0) {
				res++;
			}
			for (auto& [v, w] : pathData[next]) {
				if (v != root) {
					res += dfs(next, v, weightSum + w);
				}
			}
			return res;
			};

		for (int i = 0; i < n; ++i) {
			int temp = 0;
			for (const auto& next : pathData[i]) {
				int validNodes = dfs(i, next.first, next.second);
				result[i] += temp * validNodes;
				temp += validNodes;
			}
		}
		return result;
}

int main() {
	vector<vector<int>> edges
	{
		{1,0,2},
		{2,1,4},
		{3,2,4},
		{4,0,3},
		{5,1,4},
		{6,2,2},
		{7,6,4},
		{8,1,2},
		{9,8,3},
	};
	int signalSpeed = 1;
	vector<int> result = countPairsOfConnectableServers(edges, signalSpeed);
	std::copy(begin(result), end(result), std::ostream_iterator<int>(cout, " "));
}