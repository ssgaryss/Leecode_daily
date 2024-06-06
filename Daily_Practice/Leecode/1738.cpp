#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kthLargestValue(vector<vector<int>>& matrix, int k) {
	//�������A ^ A = 0, A ^ 0 = A������M[i][j] = M[i-1][j] ^ M[i][j-1] ^ M[i-1][j-1] ^ matrix[i][j]
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>> M(m + 1, vector<int>(n + 1, 0)); //��һ�е�һ�о�Ϊ0����ʹ��
	vector<int> sortM;
	sortM.reserve(m * n);
	for (int i = 1; i < m + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			M[i][j] = M[i - 1][j] ^ M[i][j - 1] ^ M[i - 1][j - 1] ^ matrix[i - 1][j - 1];
			sortM.emplace_back(M[i][j]);
		}
	}
	sort(sortM.begin(), sortM.end(), [](int a, int b) { return a > b; });
	return sortM[k - 1];
}

int main() {
	vector<vector<int>> matrix
	{
		{5,2},
		{1,6}
	};
	int k = 2;
	int ans = kthLargestValue(matrix, k);
	cout << ans << "\n";

}