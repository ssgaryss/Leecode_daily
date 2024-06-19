#include <iostream>
#include <vector>
#include <map>
using namespace std;

int maxIncreasingCells(vector<vector<int>>& mat) {
	// dp[i, j]����mat[i, j]�������
    int m = mat.size(), n = mat[0].size();
    map<int, vector<pair<int, int>>> mp;
    vector<int> row(m), col(n); // rowΪ��ǰÿ������dpֵ��colΪÿ�����dpֵ

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mp[mat[i][j]].push_back({ i, j });
        }
    }

    vector<int> res; // �����ͬ��ֵ�Ĵ𰸣����ں������� row �� col
    for (auto& [_, pos] : mp) {
        res.clear();
        for (auto& [x, y] : pos) {
            res.push_back(max(row[x], col[y]) + 1);
        }
        for (int i = 0; i < pos.size(); i++) {
            auto& [x, y] = pos[i];
            row[x] = max(row[x], res[i]);
            col[y] = max(col[y], res[i]);
        }
    }

    //return *max_element(row.begin(), row.end());
    return *max_element(col.begin(), col.end());
}

int main() {
	vector<vector<int>> mat{
		{3,1},
		{3,4}
	};
	int res = maxIncreasingCells(mat);
	cout << res << "\n";
}