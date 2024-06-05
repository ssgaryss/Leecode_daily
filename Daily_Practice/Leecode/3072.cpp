#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <unordered_map>
using namespace std;

auto _{ []() noexcept {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);
	return 0;
}() };

class BinaryIndexTree {
public:
	BinaryIndexTree(int n)
		: m_Tree(n + 1) {} //因为题目下标从1到n
	int lowbit(int x) {
		return x & (-x);
	}
	void add(int i) {
		while (i < m_Tree.size())
		{
			m_Tree[i]++; //此处只用于计数
			i += lowbit(i);
		}
	}
	int get(int i) {
		int res = 0;
		while (i > 0)
		{
			res += m_Tree[i];
			i -= lowbit(i);
		}
		return res;
	}
private:
	std::vector<int> m_Tree;
};

vector<int> resultArray(vector<int>& nums) {
	int n = nums.size();
	vector<int> SortNums = nums;
	std::ranges::sort(SortNums);
	unordered_map<int, int> Index; //记录排序后的nums[i]在SortNums中的index，<nums[i], index>
	for (int i = 0; i < n; ++i) {
		Index[SortNums[i]] = i + 1; //若相等index记录最大值，因为需要求严格大于
	}

	vector<int> arr1;
	vector<int> arr2;
	arr1.emplace_back(nums[0]);
	arr2.emplace_back(nums[1]);
	//tree 用于记录对应SortNums中对应index以前的所以整数个数和，即get(index)的值
	BinaryIndexTree tree1(n);
	BinaryIndexTree tree2(n);
	tree1.add(Index[nums[0]]);
	tree2.add(Index[nums[1]]);
	for (int i = 2; i < n; ++i) {
		int	count1 = arr1.size() - tree1.get(Index[nums[i]]);
		int	count2 = arr2.size() - tree2.get(Index[nums[i]]);
		if (count1 > count2) {
			arr1.emplace_back(nums[i]);
			tree1.add(Index[nums[i]]);
		}
		else if(count1 < count2){
			arr2.emplace_back(nums[i]);
			tree2.add(Index[nums[i]]);
		}
		else {
			if (arr1.size() <= arr2.size()) {
				arr1.emplace_back(nums[i]);
				tree1.add(Index[nums[i]]);
			}
			else {
				arr2.emplace_back(nums[i]);
				tree2.add(Index[nums[i]]);
			}
		}
	}
	std::copy(arr2.begin(), arr2.end(), std::back_inserter(arr1));

	return arr1;
}

int main() {
	std::vector<int> nums{ 5,14,3,1,2 };
	std::vector<int>result = resultArray(nums);
	std::copy(result.begin(), result.end(), std::ostream_iterator<int>(cout, " "));
}

//树状数组！！！！！！lowbit（x）= x & （-x）= x & （~x + 1）