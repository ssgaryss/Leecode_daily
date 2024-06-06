#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestEqualSubarray(vector<int>& nums, int k) {
	int res = 0;
	unordered_map<int, vector<size_t>> pos; //��¼��ͬԪ�����г����±�
	for (size_t i = 0; i < nums.size(); ++i) {
		pos[nums[i]].emplace_back(i);
	}
	//�ҳ�ÿ��Ԫ�����ֵ������
	for (auto& [_, vec] : pos) {
		for (size_t i = 0, j = 0; i < vec.size(); ++i) {
			//iΪ���Ҳ��index��jΪ��࣬���k�����˲��ƶ����(��������)
			while (vec[i] - vec[j] - (i - j) > k) {
				j++;
			}
			res = max(res, static_cast<int>(i - j + 1));
		}
	}
	return res;
}

int main() {
	vector<int> nums{ 1,3,2,3,1,3 };
	int k = 3;
	int res = longestEqualSubarray(nums, k);
	cout << res;
}