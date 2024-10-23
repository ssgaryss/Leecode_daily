#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long countCompleteDayPairs(vector<int>& hours) {
	int n = (int)hours.size();
	unordered_map<int, int> count;
	for (auto hour : hours)
		count[hour % 24]++;
	long long res = 0;
	for (auto hour : hours) {
		count[hour % 24]--;
		res += count[(24 - (hour % 24)) % 24];
	}
	return res;
}

int main() {
	vector hours{ 72,48,24,3 };
	cout << countCompleteDayPairs(hours) << "\n";
}