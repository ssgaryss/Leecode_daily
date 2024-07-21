#include <iostream>
#include <vector>
using namespace std;

auto _{ []()noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int maximumSum(vector<int>& arr) {
	// dp[i][k] ��arr[i]��β(ɾ��ǰ)��ɾ��k��Ԫ�ص����ǿ�������֮��
	// �Ż�Ϊdp0 dp1��¼��һ�εĽ��������Ҫ��¼����dp
	int n = arr.size();
	int dp0 = arr[0], dp1 = -1000000;
	int res = max(dp0, dp1);
	for (int i = 1; i < n; ++i) {
		dp1 = max(dp0, dp1 + arr[i]);
		dp0 = max(dp0, 0) + arr[i];
		res = max({ dp0, dp1, res });
	}
	return res;
}

int main() {
	vector arr{ 1,-2,-2,3 };
	int res = maximumSum(arr);
	cout << res << "\n";
}