#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//int minimumRounds(vector<int>& tasks) {
//	sort(tasks.begin(), tasks.end());
//	tasks.emplace_back(INT_MIN);
//	int turns = 0;
//	int current = tasks[0];
//	int currentNums = 0;
//	for (int i = 0; i < tasks.size(); i++) {
//		if (tasks[i] != current || tasks[i] == INT_MIN) {
//			if (currentNums == 1)
//				return -1;
//			turns += currentNums / 3 + (currentNums % 3 != 0) * 1;
//			current = tasks[i];
//			currentNums = 1;
//		}
//		else {
//			currentNums++;
//		}
//	}
//	return turns;
//}

//用unordered_map优化速度，无需sort排序
int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> cnt;
    for (int t : tasks) {
        cnt[t]++;
    }
    int res = 0;
    for (auto [_, v] : cnt) {
        if (v == 1) {
            return -1;
        }
        else if (v % 3 == 0) {
            res += v / 3;
        }
        else {
            res += v / 3 + 1;
        }
    }
    return res;
}

int main() {
	vector<int> tasks{ 2 };
	int turns = minimumRounds(tasks);
	cout << turns;
}