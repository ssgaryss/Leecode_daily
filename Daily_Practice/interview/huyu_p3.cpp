#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int l = 0; l < N; ++l) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>> Grid(n, vector<int>(m, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> Grid[i][j];
			}
		}
		vector<int> Gravity(k + 1, 0);
		for (int i = 1; i < k + 1; ++i) {
			cin >> Gravity[i];
		}

		// �㷨��ʼ
		for (int j = 0; j < m; ++j) {
			queue<int> Next; // ��¼��ǰ�����������䵽��λ��
			for (int i = n - 1; i >= 0; --i) {
				int Value = Grid[i][j];
				if (Value == 0) {
					Next.emplace(i);
				}
				else {
					if (Gravity[Value] == 0) {
						Next = queue<int>();
					}
					else if (Gravity[Value] == 1) {
						if (!Next.empty()) {
							int TargetRaw = Next.front();
							Next.pop();
							swap(Grid[i][j], Grid[TargetRaw][j]);
							Next.emplace(i);
						}
					}
				}
			}
		}

		// ���
		for (const auto& Raw : Grid) {
			copy(Raw.begin(), Raw.end(), ostream_iterator<int>(cout, " "));
			cout << "\n";
		}
	}

}