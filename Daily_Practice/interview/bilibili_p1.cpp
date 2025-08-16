#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsOdd(int n) {
	return static_cast<bool>(n % 2);
}

int main() {
	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());
	int res = 1;
	vector<int> result;
	result.emplace_back(nums[0]);
	int	Last = nums[0];
	for (int i = 1; i < N; ++i) {
		if ((!IsOdd(nums[i]) && IsOdd(Last)) || (IsOdd(nums[i]) && !IsOdd(Last))) {
			if (nums[i] > Last) {
				result.emplace_back(nums[i]);
				Last = nums[i];
				res++;
			}
		}
	}

	cout << res;
}