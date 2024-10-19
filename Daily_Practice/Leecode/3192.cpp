#include <iostream>
#include <vector>
using namespace std;

int minOperations(vector<int>& nums) {
	int res = 0;
	int n = (int)nums.size();
	for (int i = n - 1; i > 0; --i) {
		if (nums[i] != nums[i - 1])
			res++;
	}
	res += nums[0] == 1 ? 0 : 1;
	return res;
}

int main() {
	vector nums{ 0,1,1,0,1 };
	cout << minOperations(nums) << "\n";
}