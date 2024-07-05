#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
	int m = matrix.size(), n = matrix[0].size();
	vector<int> maxCols(n);
	for (int j = 0; j < n; ++j) {
		int max = INT_MIN;
		for (int i = 0; i < m; ++i) {
			if (matrix[i][j] > max)
				max = matrix[i][j];
		}
		maxCols[j] = max;
	}
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < m; ++i) {
			if (matrix[i][j] == -1)
				matrix[i][j] = maxCols[j];
		}
	}

	return matrix;
}

int main() {
	vector<vector<int>> matrix{
		{1,2,-1},
		{4,-1,6},
		{7,8,9}
	};
	auto res = modifiedMatrix(matrix);
	for (auto it : res) {
		copy(it.begin(), it.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}