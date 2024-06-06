#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
	vector<pair<int, int>> dif_pro;
	//for (int i = 0; i < profit.size(); i++) {
	//	pair<int, int> temp{ make_pair(profit[i],difficulty[i]) };
	//	auto it = lower_bound(dif_pro.begin(), dif_pro.end(), temp, [](const pair<int, int>& a, const pair<int, int>& b) {
	//		return a.first > b.first;
	//		});
	//	dif_pro.insert(it, temp);
	//}	
	for (int i = 0; i < profit.size(); i++) {
		dif_pro.emplace_back(profit[i], difficulty[i]);
	}
	sort(dif_pro.begin(), dif_pro.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.first > b.first;
		});
	sort(worker.begin(), worker.end(), [](int a, int b) {
		return a > b;
		});
	int maxProfit = 0;
	for (int i = 0; i < dif_pro.size(); i++) {
		for (int j = 0; j < worker.size(); j++) {
			if (worker[j] >= dif_pro[i].second) {
				maxProfit += dif_pro[i].first;
			}
			else {
				//if (j - 1 <= 0) break;
				worker.erase(worker.begin(), worker.begin() + j);
				break;
			}
			if (j == worker.size() - 1) return maxProfit;
		}
	}
	return maxProfit;
}

int main() {
	vector<int> difficulty{ 2,4,6,8,10 };
	vector<int> profit{ 10,20,30,40,50 };
	vector<int> worker{ 4,5,6,7 };
	int maxProfit = maxProfitAssignment(difficulty, profit, worker);
	cout << maxProfit << "\n";
}

//删除begin（） --- begin（） + j - 1的元素
//worker.erase(worker.begin(), worker.begin() + j);

//用lower_bound()一个个插入非常耗时，sort效率高出非常多！！！！