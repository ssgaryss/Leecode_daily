#include<iostream>
#include<vector>

using namespace std;

int cherryPickup(vector<vector<int>>& grid);
int getMaxValue(vector<vector<int>>& dp, int i, int j); //�жϣ�i��j����Χ9����ֵ�����ֵ

int main() {
	vector<vector<int>> grid{
		{0,8,7,10,9,10,0,9,6},
		{8,7,10,8,7,4,9,6,10},
		{8,1,1,5,1,5,5,1,2},
		{9,4,10,8,8,1,9,5,0},
		{4,3,6,10,9,2,4,8,10},
		{7,3,2,8,3,3,5,9,8},
		{1,2,6,5,6,2,0,10,0},
	};
	int num = cherryPickup(grid);
	cout << num;
	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		cout << getMaxValue(grid, i, j) << " ";
	//	}
	//	cout << "\n";
	//}
}

int cherryPickup(vector<vector<int>>& grid) {
	//��̬�滮 
	//dp[i12][j1][j2]��ʾ��(i12, j1)��(i12, j2)�����һ�е����ӣ����Ŀ
	//���Խ�i12�򻯵���ֻ��Ҫ����dp1[j1][j2]��dp2[j1][j2]���齻����¼���
	//���Լ���j1 < j2����ÿ��j2�ɴ�j1��ʼ����
	int rows = grid.size();
	int cols = grid[0].size();
	vector<vector<int>> dp1(cols, vector<int>(cols, INT_MIN)); //dp1��dp2����ʹ��
	vector<vector<int>> dp2(cols, vector<int>(cols, INT_MIN));
	int maxCherries = INT_MIN;
	dp1[0][cols - 1] = grid[0][0] + (0 != cols - 1) * grid[0][cols - 1]; //�̶������
	for (int k = 1; k < rows; k++) {
		for (int j1 = 0; j1 < cols; j1++) {
			for (int j2 = 0; j2 < cols; j2++) {
				if (k % 2 == 0) {
					dp1[j1][j2] = grid[k][j1] + (j1 != j2) * grid[k][j2]
						+ getMaxValue(dp2, j1, j2);
					maxCherries = max(maxCherries, dp1[j1][j2]);
				}
				else {
					dp2[j1][j2] = grid[k][j1] + (j1 != j2) * grid[k][j2]
						+ getMaxValue(dp1, j1, j2);
					maxCherries = max(maxCherries, dp2[j1][j2]);
				}
			}
		}
	}
	return maxCherries;
}

int getMaxValue(vector<vector<int>>& dp, int i, int j)
{
	int rows = dp.size();
	int cols = dp[0].size();
	int maxValue = dp[i][j];
	if (i < 0 || i >= rows || j < 0 || j >= cols) return INT_MIN;
	if (i - 1 >= 0) maxValue = max(maxValue, dp[i - 1][j]);
	if (j - 1 >= 0) maxValue = max(maxValue, dp[i][j - 1]);
	if (i + 1 < rows) maxValue = max(maxValue, dp[i + 1][j]);
	if (j + 1 < cols) maxValue = max(maxValue, dp[i][j + 1]);

	if (i - 1 >= 0 && j - 1 >= 0) maxValue = max(maxValue, dp[i - 1][j - 1]);
	if (i - 1 >= 0 && j + 1 < cols) maxValue = max(maxValue, dp[i - 1][j + 1]);
	if (i + 1 < rows && j - 1 >= 0) maxValue = max(maxValue, dp[i + 1][j - 1]);
	if (i + 1 < rows && j + 1 < cols) maxValue = max(maxValue, dp[i + 1][j + 1]);
	return maxValue;
}
