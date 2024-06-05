#include<iostream>
#include<vector>

using namespace std;

int cherryPickup(vector<vector<int>>& grid);

int main() {
	vector<vector<int>> grid
	{
		{0,1,-1},
		{1,0,-1},
		{1,1,1 }
	};
	int num = cherryPickup(grid);
	cout << num;
}

int cherryPickup(vector<vector<int>>& grid) {
	int N = static_cast<int>(grid.size());
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, INT_MIN));
	dp[N - 1][N - 1] = 0; //初始化
	for (int k = 2 * N - 2; k > -1; k--) {//k为第k条对角线 0，1，...,2 * N - 2
		for (int i1 = max(0, k - N + 1); i1 <= min(N - 1, k); i1++) {
			for (int i2 = i1; i2 <= min(N - 1, k); i2++) {
				int j1 = k - i1;
				int j2 = k - i2;
				if (grid[i1][j1] == -1 || grid[i2][j2] == -1) dp[i1][i2] = INT_MIN;
				else {
					if (i1 == i2) {
						dp[i1][i2] = grid[i1][j1] +
							max(
								max(dp[i1 + 1][i2 + 1], dp[i1 + 1][i2]),
								max(dp[i1][i2 + 1], dp[i1][i2])
							);
					}
					else {
						dp[i1][i2] = grid[i1][j1] + grid[i2][j2] +
							max(max(dp[i1 + 1][i2 + 1], dp[i1 + 1][i2]),
								max(dp[i1][i2 + 1], dp[i1][i2]));
					}
				}
			}
		}
	}
	return max(0, dp[0][0]);
}

