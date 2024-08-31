#include <iostream>
#include <vector>
#include <iomanip>
#include <functional>
using namespace std;

bool canMakeSquare(vector<vector<char>>& grid) {
	function<int(int, int)> check = [&grid](int i, int j)->int {
		int count = 0;
		if (grid[i][j] == 'W') count++;
		else count--;
		if (grid[i + 1][j] == 'W') count++;
		else count--;
		if (grid[i][j + 1] == 'W') count++;
		else count--;
		if (grid[i + 1][j + 1] == 'W') count++;
		else count--;
		return count;
		};
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (check(i, j) != 0)
				return true;
		}
	}
	return false;
}

int main() {
	vector<vector<char>> grid{
		{'B','W','B'},
		{'B','W','W'},
		{'B','W','B'}
	};
	cout << boolalpha << canMakeSquare(grid) << "\n";
}