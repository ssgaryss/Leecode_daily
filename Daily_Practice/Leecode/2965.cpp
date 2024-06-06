#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
	vector<int> gridElements;
	int n = grid.size();
	vector<int> ans(2, -1);
	gridElements.reserve(n * n);
	for (int i = 0; i < n; ++i) {
		gridElements.insert(gridElements.end(), grid[i].begin(), grid[i].end());
	}
	sort(gridElements.begin(), gridElements.end());
	for (int i = 0; i < n * n; ++i) {
		if (gridElements[0] != 1) ans[1] = 1;
		if (i + 1 == n * n - 1 && ans[1] == -1) ans[1] = n * n;
		if (gridElements[i] == gridElements[i + 1])
			ans[0] = gridElements[i];
		if (gridElements[i] + 1 < gridElements[i + 1])
			ans[1] = gridElements[i] + 1;
		if (ans[0] > 0 && ans[1] > 0) return ans;
	}
	return ans;
}

int main() {
	vector<vector<int>> grid{ {1,3} ,{2,2} };
	vector<int> ans = findMissingAndRepeatedValues(grid);
	cout << ans[0] << " " << ans[1] << "\n";
}