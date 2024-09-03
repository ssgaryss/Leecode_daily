#include <iostream>
#include <vector>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

long long maxStrength(vector<int>& nums) {
	long long res = 1;
	int min_neg = INT_MIN;
	bool has_pos = false;
	int neg_count = 0;
	for (auto it : nums) {
		if (it > 0) {
			has_pos = true;
			res *= it;
		}
		if (it < 0) {
			neg_count++;
			res *= it;
			min_neg = max((int)min_neg, it);
		}
	}
	if (!has_pos && neg_count == 1 && nums.size() > 1) return 0;
	if (!has_pos && neg_count == 0) return 0;
	if (neg_count == 1 && nums.size() == 1) return nums[0];
	return res > 0 ? res : res / min_neg;
}

int main() {
	vector nums{ 0 };
	cout << maxStrength(nums) << "\n";
}