#include <iostream>
#include <vector>
using namespace std;

int numberOfStableArrays(int zero, int one, int limit) {
	// dp1[i][j]��ʾ����i��0��j��1���������Ϊ1�Ŀ����ܷ�����
	// dp0[i][j]��ʾ����i��0��j��1���������Ϊ0�Ŀ����ܷ�����
	// �����еķ����ɵȼ�Ϊ���г�Ϊlimit + 1��������ͬʱ��0��1�����
	vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0));
	vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0));
	constexpr long long mod = 1e9 + 7;
	for (int i = 0; i <= std::min(zero, limit); ++i)
		dp0[i][0] = 1; // ֻ��һ�ֿ��з���
	for (int i = 0; i <= std::min(one, limit); ++i)
		dp1[0][i] = 1; // ֻ��һ�ֿ��з���
	for (int i = 1; i <= zero; ++i) {
		for (int j = 1; j <= one; ++j) {
			if (i <= limit)  // ��ʱ�ܷ��������ǿ��еķ�����
				dp0[i][j] = (dp0[i - 1][j] + dp1[i - 1][j]) % mod;
			if (j <= limit)  // ��ʱ�ܷ��������ǿ��еķ�����
				dp1[i][j] = (dp0[i][j - 1] + dp1[i][j - 1]) % mod;
			// i > limitʱ,����dp[i-1][j]�ټ���һ��0,ֻ�е�ĩβ������i-1��0ʱ����ڲ����з���,�������з���Ϊdp1[i-1-limit][j]
			if (i > limit)  // ��ʱ�ܷ�������ȥ�����з�����
				dp0[i][j] = (dp0[i - 1][j] + dp1[i - 1][j] - dp1[i - 1 -limit][j]) % mod;
			// j > limitʱ,����dp[i][j-1]�ټ���һ��1,ֻ�е�ĩβ������j-1��1ʱ����ڲ����з���,�������з���Ϊdp0[i][j-1-limit]
			if (j > limit)  // ��ʱ�ܷ�������ȥ�����з�����
				dp1[i][j] = (dp0[i][j - 1] + dp1[i][j - 1] - dp0[i][j - 1 - limit]) % mod;
			// ����֮ǰȡģ���㵼�¿��ܳ��ָ���
			dp0[i][j] = (dp0[i][j] % mod + mod) % mod;
			dp1[i][j] = (dp1[i][j] % mod + mod) % mod;
		}
	}

	return (dp0[zero][one] + dp1[zero][one]) % mod;
}

int main() {
	int zero = 3, one = 3, limit = 2;
	int res = numberOfStableArrays(zero, one, limit);
	cout << res << "\n";
}