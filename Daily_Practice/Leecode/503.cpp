#include <iostream>
#include <vector>
#include <iterator>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
	int n = nums.size();
	vector<int> res(n, -1);
	stack<int> stk; // ����ջ������Ԫ���±꣬��ջ�׵�ջ���±��Ӧֵ����
	for (int i = 0; i < 2 * n; ++i) {
		while (!stk.empty() && nums[i % n] > nums[stk.top()])
		{
			res[stk.top()] = nums[i % n];
			stk.pop();
		}
		stk.push(i % n);
	}
	return res;
}

int main() {
	vector<int> nums{ 1,2,3,4,3 };
	vector<int> res = nextGreaterElements(nums);
	std::copy(res.begin(), res.end(), std::ostream_iterator<int>(cout, " "));
}

// ����ջ������