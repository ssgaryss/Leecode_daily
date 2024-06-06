#include <iostream>
#include <vector>
//#include <algorithm>
#include <numeric>
using namespace std;

//long long numberOfWeeks(vector<int>& milestones) {
//	//����ʹ�ö�̬�滮dp[i][j]��ʾǰi��Ԫ���Ƿ���Ժ�Ϊj
//	int sum = reduce(milestones.begin(), milestones.end());
//	vector<vector<bool>> dp(milestones.size(), vector<bool>(sum / 2 + 1, false));
//	if (milestones.size() == 1) return 1;
//	for (int i = 0; i < dp.size(); i++) {
//		for (int j = 0; j < dp[0].size(); j++) {
//			if (milestones[i] < dp[0].size()) dp[i][milestones[i]] = true;
//			if (i - 1 >= 0) {
//				if (dp[i - 1][j] == 1 && j + milestones[i] < dp[0].size()) {
//					dp[i][j] = true;
//					dp[i][j + milestones[i]] = true;
//				}
//			}
//		}
//	}
//	for (int i = dp[0].size() - 1; i >= 0; i--) {
//		if (dp[milestones.size() - 1][i]) return i * 2 + (sum - i > i);
//	}
//	return 1;
//}

long long numberOfWeeks(vector<int>& milestones) {
	//ֻҪ���������longest <= rest + 1��һ��������ɣ����� 
	//��Ϊ�������еĹ�����������������longest�ļ���м�longest + 1����֮�޷���������longest�ĺ����޷����
	long long longest = *max_element(milestones.begin(), milestones.end());
	long long rest = accumulate(milestones.begin(), milestones.end(), 0LL) - longest;
	if (longest <= rest + 1) {
		return rest + longest;
	}
	return rest * 2 + 1; 
}

int main() {
	vector<int> milestones{ 5,7,5,7,9,7 };
	long long nums = numberOfWeeks(milestones);
	cout << nums << "\n";
}

//max_element��accumulate