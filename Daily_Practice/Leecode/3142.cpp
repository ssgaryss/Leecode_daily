#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool satisfiesConditions(vector<vector<int>>& grid) {
	int cur = INT_MAX;
	for (int j = 0; j < (int)grid[0].size(); ++j) {
		cur = grid[0][j];
		for (int i = 0; i < (int)grid.size(); ++i) {
			if (grid[i][j] != cur)
				return false;
		}
		if (j + 1 < (int)grid[0].size() && cur == grid[0][j + 1])
			return false;
	}
	return true;
}

int main() {
	vector<vector<int>> grid{
		{1},
		{2},
		{3},
	};
	cout << boolalpha << satisfiesConditions(grid) << "\n";
}