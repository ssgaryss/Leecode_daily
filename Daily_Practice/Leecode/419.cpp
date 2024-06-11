#include <iostream>
#include <vector>
using namespace std;

int countBattleships(vector<vector<char>>& board) {
	int m = board.size();
	int n = board[0].size();
	int count = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 'X') {
				for (int k = j + 1; k < n; ++k) {
					if (board[i][k] == 'X') board[i][k] = '.';
					else break;
				}
				for (int k = i + 1; k < m; ++k) {
					if (board[k][j] == 'X') board[k][j] = '.';
					else break;
				}
				count++;
			}
		}
	}
	return count;
}

int main() {
	vector<vector<char>> board{
		{'X','.','.','X'},
		{'.','.','.','X'},
		{'.','.','.','X'}
	};
	int count = countBattleships(board);
	cout << count << "\n";

}