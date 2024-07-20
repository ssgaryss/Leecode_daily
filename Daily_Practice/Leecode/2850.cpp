#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto _{ []()noexcept {
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int minimumMoves(vector<vector<int>>& grid) {
	vector<pair<int, int>> from, to;
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[0].size(); ++j) {
			if (grid[i][j]) {
				for (int k = 1; k < grid[i][j]; ++k)
					from.emplace_back(i, j);
			}
			else
				to.emplace_back(i, j);
		}
	}
	int res = INT_MAX;
	do
	{
		int total = 0;
		for (int i = 0; i < from.size(); ++i)
			total += abs(from[i].first - to[i].first) + abs(from[i].second - to[i].second);
		res = min(total, res);
	} while (next_permutation(from.begin(), from.end())); // next_permutation!!!!!
	return res;
}

int main() {
	vector<vector<int>> grid{
		{1,3,0},
		{1,0,0},
		{1,0,3}
	};
	auto res = minimumMoves(grid);
	cout << res << "\n";
}