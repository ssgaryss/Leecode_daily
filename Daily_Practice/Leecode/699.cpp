#include <iostream>
#include <vector>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}()};

vector<int> fallingSquares(vector<vector<int>>& positions) {
	int n = (int)positions.size();
	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		int left1 = positions[i][0], right1 = left1 + positions[i][1];
		res[i] = positions[i][1];
		for (int j = 0; j < i; ++j) {
			int left2 = positions[j][0], right2 = left2 + positions[j][1];
			if (left1 < right2 && right1 > left2)
				res[i] = max(res[i], res[j] + positions[i][1]);
		}
	}
	for (int i = 1; i < n; ++i)
		res[i] = max(res[i], res[i - 1]);
	return res;
}

int main() {
	vector<vector<int>> positions{
		{1,2},{2,3},{6,1}
	};
	auto res = fallingSquares(positions);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
}