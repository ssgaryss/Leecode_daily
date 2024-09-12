#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int maxNumOfMarkedIndices(vector<int>& nums) {
	int n = (int)nums.size();
	sort(nums.begin(), nums.end());
	int i = 0, j = n / 2;
	auto check = [&n, &i, &nums](int m) {
		for (int i = 0; i < m; ++i) {
			if (2 * nums[i] > nums[n - m + i])
				return false;
		}
		return true;
		};
	while (i < j)
	{
		int m = (i + j + 1) >> 1; // Г§вд2
		if (check(m))
			i = m;
		else
			j = m - 1;
	}
	return i * 2;
}

int main() {
	vector nums{ 9,2,5,4 };
	cout << maxNumOfMarkedIndices(nums) << "\n";
}