#include <iostream>
#include <vector>

using namespace std;

int checkAround(vector<vector<int>>& grid, int i, int j) {
	int value = grid[i][j];
	if (value == 1) {
		if (i - 1 >= 0 && grid[i - 1][j] == 2) return 2;
		if (i + 1 < grid.size() && grid[i + 1][j] == 2) return 2;
		if (j - 1 >= 0 && grid[i][j - 1] == 2) return 2;
		if (j + 1 < grid[0].size() && grid[i][j + 1] == 2) return 2;
	}
	return value;
}

int orangesRotting(vector<vector<int>>& grid) {
	int minMinutes = -1;
	vector<vector<int>> temp{ grid };
	//k为第几分钟，最多2 * (grid.size（）-1)分钟传播完
	for (int k = 0; k <= INT_MAX; k++) {
		bool end = true;
		bool can = true;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (k % 2 == 0) {
					temp[i][j] = checkAround(grid, i, j);
					if (temp[i][j] == 1) can = false;
				}
				else {
					grid[i][j] = checkAround(temp, i, j);
					if (grid[i][j] == 1) can = false;
				}
				if (temp[i][j] != grid[i][j]) end = false;
			}
		}
		if (end && can) {
			minMinutes = k;
			break;
		}
		else if (end && !can) {
			break;
		}
	}
	return minMinutes;
}

int main() {
	vector<vector<int>> grid{
		{1,2,}
	};
	int minMinutes = orangesRotting(grid);
	cout << minMinutes;
}