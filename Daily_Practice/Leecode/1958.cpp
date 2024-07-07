#include <iostream>
#include <vector>
#include <iomanip>
#include <functional>
using namespace std;

bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
	bool res = false;
	function<void(int, int, int)> check = [&](int step, int i, int j) {
		int nextR = rMove + i * step, nextC = cMove + step * j;
		if (nextR < 0 || nextR > 7 || nextC < 0 || nextC > 7)
			return;
		if (board[nextR][nextC] == '.')
			return;
		if (step == 1) {
			if (board[nextR][nextC] == color) {
				return;
			}
			else
				check(step + 1, i, j);
		}
		else if (step > 1) {
			if (board[nextR][nextC] == color)
				res = true;
			else
				check(step + 1, i, j);
		}
		return;
		};

	check(1, 1, 1);
	check(1, -1, 1);
	check(1, 1, -1);
	check(1, -1, -1);
	check(1, 1, 0);
	check(1, -1, 0);
	check(1, 0, 1);
	check(1, 0, -1);

	return res;
}

int main() {
	vector<vector<char>> board{
		{'.','.','.','B','.','.','.','.'},
		{'.','.','.','W','.','.','.','.'},
		{'.','.','.','W','.','.','.','.'},
		{'.','.','.','W','.','.','.','.'},
		{'W','B','B','.','W','W','W','B'},
		{'.','.','.','B','.','.','.','.'},
		{'.','.','.','B','.','.','.','.'},
		{'.','.','.','W','.','.','.','.'},
	};
	int rMove = 4, cMove = 3;
	char color = 'B';
	bool res = checkMove(board, rMove, cMove, color);
	cout << boolalpha << res << "\n";
}