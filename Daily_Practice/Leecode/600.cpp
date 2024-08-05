#include <iostream>
#include <vector>
using namespace std;

int findIntegers(int n) {
	// dp[i]��ʾ����i�Ķ�������û������1�ĸ���
	// �����Ϊ 0 �����������У������ӽ���Ǹ߶�Ϊ t-1�������Ϊ 0 ���������� + ���ӽ���Ǹ߶�Ϊ t-1�������Ϊ 1 ����������
	// �����Ϊ 1 �����������У������ӽ���Ǹ߶�Ϊ t-1�������Ϊ 0 ���������� + �����ӽ������ӽڵ��Ǹ߶�Ϊ t-2�������Ϊ 0 ����������
	// dp[i] = dp[i - 1] + dp[i - 2] �������Ϊlength
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