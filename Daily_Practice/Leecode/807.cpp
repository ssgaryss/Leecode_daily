#include <iostream>
#include <vector>
using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
	int m = grid.size(), n = grid[0].size();
	vector<int> maxRow(m), maxCol(n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			maxRow[i] = max(maxRow[i], grid[i][j]);
			maxCol[j] = max(maxCol[j], grid[i][j]);
		}
	}
	int res = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			res += min(maxRow[i], maxCol[j]) - grid[i][j];
		}
	}
	return res;
}

int main() {
	vector<vector<int>> grid{
		{ 3,0,8,4 },
		{ 2,4,5,7 },
		{ 9,2,6,3 },
		{ 0,3,1,0 }
	};
	auto res = maxIncreaseKeepingSkyline(grid);
	cout << res << "\n";
}