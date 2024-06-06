#include <iostream>
#include <vector>
using namespace std;

vector<int> distributeCandies(int candies, int num_people) {
	vector<int> ans(num_people);
	int oneTime = (1 + num_people) * num_people / 2;
	int times = 0;
	while (1) {
		if (candies >= oneTime + times * num_people * num_people) {
			candies -= oneTime + times * num_people * num_people;
			times++;
		}
		else {
			break;
		}
	}
	int level = 0;
	for (int i = 0; i < num_people; ++i) {
		level++;
		if (times >= 1) ans[i] += (times - 1 + 1) * (times - 1) / 2 * num_people + (i + 1) * times;
		else ans[i] += (i + 1) * times;
		if (candies >= level + times * num_people) {
			candies -= level + times * num_people;
			ans[i] += level + times * num_people;
		}
		else {
			ans[i] += candies;
			candies = 0;
		}
	}
	return ans;
}

int main() {
	int candies = 80, num_people = 4;
	vector<int> ans = distributeCandies(candies, num_people);

}