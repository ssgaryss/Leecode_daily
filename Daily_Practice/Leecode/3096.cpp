#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

auto _{ []()noexcept {
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int minimumLevels(vector<int>& possible) {
	int n = possible.size();
	int win = reduce(possible.begin(), possible.end());
	int loss = n - win;
	int sum = win - loss;
	int sumA = 0;
	int flag = sum >= 0 ? sum / 2 + 1 : (sum - 1) / 2 + 1;
	for (int i = 0; i < n - 1; ++i) {
		if (possible[i])
			sumA += 1;
		else
			sumA -= 1;
		if (sumA >= flag)
			return i + 1;
	}
	return -1;
}

int main() {
	vector possible{ 0,0,0 };
	auto res = minimumLevels(possible);
	cout << res << "\n";
}