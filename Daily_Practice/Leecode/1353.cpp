#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int maxEvents(vector<vector<int>>& events) {
	int res = 0;
	std::sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[1] < b[1];
		});
	unordered_map<int, int> Record;
	for (int i = 0; i < static_cast<int>(events.size()); ++i) {
		int day = events[i][0];
		if (Record.count(day)) {
			for (int j = day; j <= events[i][1]; ++j) {
				if (!Record.count(j)) {
					Record[j]++;
					res++;
					break;
				}
			}
		}
		else {
			Record[day]++;
			res++;
		}
	}
	return res;
}

int main(int argc, char** argv) {
	vector<vector<int>> events = {
		//{1, 2},
		//{1, 2},
		//{3, 3},
		{1, 5},
		{1, 5},
	};
	auto res = maxEvents(events);
	cout << res << "\n";
}