#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int differenceOfSum(vector<int>& nums) {
	return reduce(nums.begin(), nums.end(), 0, [](int acc, int x) {
		int sum = x;
		while (x != 0)
		{
			sum -= x % 10;
			x /= 10;
		}
		return acc + sum;
		});
}

int main() {
	vector nums{ 1,2,3,1,10,5,10,4,1,9 };
	cout << differenceOfSum(nums) << "\n";
}