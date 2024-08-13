#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

bool isArraySpecial(vector<int>& nums) {
	int n = (int)nums.size();
	for (int i = 0; i < n - 1; ++i) {
		if (!((nums[i] + nums[i + 1]) % 2))
			return false;
	}
	return true;
}

int main() {
	vector nums{ 4,3,1,6 };
	auto res = isArraySpecial(nums);
	cout << boolalpha << res << "\n";
}