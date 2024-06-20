#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
using namespace std;

auto _{ []() noexcept {
	std::ios::sync_with_stdio(0);
	std::cout.tie(0), std::cin.tie(0);
	return 0;
}() };

int countBeautifulPairs(vector<int>& nums) {
	function<int(int)> getFirstDigit = [](int num) {
		while (num >= 10)
		{
			num /= 10;
		}
		return num;
		};
	function<int(int)> getLastDigit = [](int num) {
		return num % 10;
		};
	int res = 0;
	for (int i = 0; i < nums.size() - 1; ++i) {
		for (int j = i + 1; j < nums.size(); ++j) {
			if (std::gcd(getFirstDigit(nums[i]), getLastDigit(nums[j])) == 1)
				res++;
		}
	}
	return res;
}

int main() {
	vector<int> nums{ 2,5,1,4 };
	int res = countBeautifulPairs(nums);
	cout << res << "\n";
}