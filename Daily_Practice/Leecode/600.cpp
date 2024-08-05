#include <iostream>
#include <vector>
using namespace std;

int findIntegers(int n) {
	// dp[i]表示长度i的二进制数没有连续1的个数
	// 根结点为 0 的满二叉树中：其左子结点是高度为 t-1、根结点为 0 的满二叉树 + 右子结点是高度为 t-1、根结点为 1 的满二叉树
	// 根结点为 1 的满二叉树中：其左子结点是高度为 t-1、根结点为 0 的满二叉树 + 其右子结点的左子节点是高度为 t-2、根结点为 0 的满二叉树
	// dp[i] = dp[i - 1] + dp[i - 2] 树的深度为length
	vector<int> dp(31);
	dp[0] = 1, dp[1] = 1;
	for (int i = 2; i < 31; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int pre = 0, res = 0;
	for (int i = 29; i >= 0; --i) {
		int val = 1 << i;
		if (n & val) {
			res += dp[i + 1];
			if (pre == 1)
				break;
			pre = 1;
		}
		else
			pre = 0;

		if (i == 0)
			++res;
	}
	return res;
}

int main(int argc, char* argv[]) {
	int n = 5;
	cout << findIntegers(n) << "\n";
}