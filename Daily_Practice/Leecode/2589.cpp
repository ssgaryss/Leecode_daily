#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

////时空复杂度过高
//int findMinimumTime(vector<vector<int>>& tasks) {
//	sort(tasks.begin(), tasks.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
//		return a[1] < b[1];
//	});
//	int minimumTime = 0;
//	//计算出最大时间区间[left, right]
//	int left = INT_MAX, right = INT_MIN, serialTime = 0;
//	for (int i = 0; i < tasks.size(); i++) {
//		if (tasks[i][0] < left) left = tasks[i][0];
//		if (tasks[i][1] > right) right = tasks[i][1];
//	}
//	//并统计每个时间点最大并行任务值存于maxParallel[0]
//	vector<vector<int>> maxParallel(2, vector<int>(right - left + 1, 0));
//	//每个时间点并行的具体任务index保存到indexParallel
//	vector<vector<int>> indexParallel(right - left + 1, vector<int>(tasks.size(), -1));
//	for (int time = 0; time < maxParallel[0].size(); time++) { //time为从left时间点开始计时
//		int index = 0;
//		for (int i = 0; i < tasks.size(); i++) {
//			if (tasks[i][0] <= left + time && tasks[i][1] >= left + time) {
//				maxParallel[0][time]++;
//				indexParallel[time][index] = i;
//				index++;
//			}
//		}
//	}
//	//求minimumTime
//	for (int i = 0; i < tasks.size(); i++) {
//		vector<pair<int, int>> indexAndValue;
//		for (int time = tasks[i][0] - left; time <= tasks[i][1] - left; time++) {
//			if (tasks[i][2] > 0) {
//				if (maxParallel[1][time] == 0) {
//					pair element = make_pair(time, maxParallel[0][time]);
//					auto it = lower_bound(indexAndValue.begin(), indexAndValue.end(), element,
//						[](const std::pair<int, int>& a, const std::pair<int, int>& b) {
//							return a.second < b.second; // 按照值逆序排序
//						});
//					indexAndValue.insert(it, element);
//					maxParallel[1][time] = 1;
//					tasks[i][2]--;
//				}
//			}
//			else {
//				if (indexAndValue.size() != 0) {
//					if (maxParallel[0][time] >= indexAndValue[0].second && maxParallel[1][time] == 0) {
//						maxParallel[1][indexAndValue[0].first] = 0;
//						indexAndValue.erase(indexAndValue.begin());
//						pair element = make_pair(time, maxParallel[0][time]);
//						auto it = lower_bound(indexAndValue.begin(), indexAndValue.end(), element,
//							[](const std::pair<int, int>& a, const std::pair<int, int>& b) {
//								return a.second < b.second; // 按照值逆序排序
//							});
//						indexAndValue.insert(it, element);
//						maxParallel[1][time] = 1;
//					}
//				}
//			}
//		}
//		//对所有并行任务最--
//		for (int k = 0; k < indexAndValue.size(); k++) {
//			for (int j = 0; j < indexParallel[0].size(); j++) {
//				if (indexParallel[indexAndValue[k].first][j] == -1) break;
//				tasks[indexParallel[indexAndValue[k].first][j]][2]--;
//			}
//		}
//		//跟新maxParellel
//		for (int time = 0; time < maxParallel[0].size(); time++) { //time为从left时间点开始计时
//			if (tasks[i][0] <= left + time && tasks[i][1] >= left + time) {
//				maxParallel[0][time]--;
//			}
//		}
//	}
//	//统计最小时间
//	for (int i = 0; i < maxParallel[0].size(); i++) {
//		if (maxParallel[1][i] != 0) minimumTime++;
//	}
//	return minimumTime;
//}

int findMinimumTime(vector<vector<int>>& tasks) {
	sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {return a[1] < b[1]; });
	int minimumTime = 0;
	vector<int> run(tasks.back()[1] + 1);
	for (int i = 0; i < tasks.size(); i++) {
		int start = tasks[i][0], end = tasks[i][1], duration = tasks[i][2];
		duration -= reduce(run.begin() + start, run.begin() + end + 1); //因为此处index=0并未使用，所以+1
		for (int j = end; duration > 0; j--) {
			if (!run[j]) {
				run[j] = true;
				duration--;
				minimumTime++;
			}
		}
	}
	return minimumTime;
}

int main() {
	vector<vector<int>> tasks{
		{5,18,9},
		{13,18,4},
		{4,19,1},
		{4,11,2},
	};
	int minTime = findMinimumTime(tasks);
	cout << minTime;
}

//auto it = lower_bound(indexAndValue.begin(), indexAndValue.end(), element,
//	[](const std::pair<int, int>& a, const std::pair<int, int>& b) {
//		return a.second < b.second; // 按照值逆序排序
//	});