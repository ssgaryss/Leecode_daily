#include <iostream>
#include <vector>
using namespace std;

long long countAlternatingSubarrays(vector<int>& nums) {
	//��nums��Ϊ�������֣�ÿ����Ϊ�ֲ������������
	long long n = nums.size();
	vector<long long> part; // ÿ���ֳ���
	long long temp = 1;
	for (long long i = 0; i < n; ++i) {
		if (i + 1 >= n) {
			part.emplace_back(temp);
			break;
		}
		if (nums[i] != nums[i + 1])
			temp++;
		else {
			part.emplace_back(temp);
			temp = 1;
		}
	}
	long long res = 0;
	for (auto i : part) {
		res += ((i + 1) * i) / 2;
	}
	return res;
}

int main() {
	vector<int> nums{ 0,1,1,1 };
	auto res = countAlternatingSubarrays(nums);
	cout << res << "\n";
}