#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int duplicateNumbersXOR(vector<int>& nums) {
	int res = 0;
	unordered_map<int, int> count;
	for (auto it : nums) {
		count[it]++;
		if (count[it] == 2)
			res ^= it;
	}
	return res;
}

int main() {
	vector nums{ 1,2,1,3 };
	cout << duplicateNumbersXOR(nums) << "\n";
}