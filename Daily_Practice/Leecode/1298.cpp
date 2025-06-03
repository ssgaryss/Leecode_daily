#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
	int res = 0;
	int n = static_cast<int>(status.size());
	vector<int> opened(n, 0);
	queue<int> hand_boxes;
	unordered_map<int, bool> hand_keys;
	for (auto i : initialBoxes)
		hand_boxes.push(i);
	while (!hand_boxes.empty()) {
		bool progress_made = false;
		for (int i = 0; i < n; ++i) {
			if (hand_boxes.empty())
				break;
			int box_id = hand_boxes.front(); 
			hand_boxes.pop();
			if (opened[box_id]) 
				continue;
			if (status[box_id] == 1 || hand_keys[box_id]) {
				opened[box_id] = 1;
				progress_made = true;

				for (int key : keys[box_id])
					hand_keys[key] = true;

				for (int box : containedBoxes[box_id])
					hand_boxes.push(box);
			}
			else {
				hand_boxes.push(box_id);
			}
		}

		if (!progress_made) 
			break;
	}
	for (int i = 0; i < n; ++i) {
		if (opened[i])
			res += candies[i];
	}
	return res;
}

int main(int argc, char** argv) {
	vector<int> status{ 1,1,1 };
	vector<int> candies{ 100, 1,100 };
	vector<vector<int>> keys{
		{},{0, 2},{}
	};
	vector<vector<int>> containedBoxes{
		{}, {}, {}, {}
	};
	vector<int> initialBoxes{ 1 };
	auto res = maxCandies(status, candies, keys, containedBoxes, initialBoxes);
	cout << res << "\n";
}