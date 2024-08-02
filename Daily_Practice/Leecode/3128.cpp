#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	return 0;
	}() };

long long numberOfRightTriangles(vector<vector<int>>& grid) {
	int m = (int)grid.size();
	int n = (int)grid[0].size();
	vector<int> row(m), col(n);
	for (int i = 0; i < m; ++i)
		row[i] = reduce(grid[i].begin(), grid[i].end());
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < m; ++i) {
			col[j] += grid[i][j];
		}
	}
	long long res = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j])
				res += (row[i] - 1) * (col[j] - 1);
		}
	}
	return res;
}

int main() {
	vector<vector<int>> grid{
		{0,1,0},
		{0,1,1},
		{0,1,0}
	};
	auto res = numberOfRightTriangles(grid);
	cout << res << "\n";
}