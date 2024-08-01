#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	return 0;
}() };

int maxmiumScore(vector<int>& cards, int cnt) {
	int n = (int)cards.size();
	sort(cards.begin(), cards.end(), greater<>());
	int res = 0;
	int minOdd = INT_MAX, minEven = INT_MAX;
	int changeOdd = -1, changEven = -1;
	for (int i = 0; i < n; ++i) {
		if (i < cnt) {
			minOdd = cards[i] % 2 == 1 ? min(minOdd, cards[i]) : minOdd;
			minEven = cards[i] % 2 == 0 ? min(minEven, cards[i]) : minEven;
			res += cards[i];
		}
		else {
			if (res % 2 == 0)
				return res;
			else {
				if (cards[i] % 2 == 0 && changEven == -1)
					changEven = cards[i];
				if (cards[i] % 2 == 1 && changeOdd == -1)
					changeOdd = cards[i];
			}
		}
	}
	if (res % 2 == 0)
		return res;
	int tempA = 0, tempB = 0;
	if (changeOdd != -1)
		tempA = res + changeOdd - minEven;
	if (changEven != -1)
		tempB = res + changEven - minOdd, res;
	return max(tempA, tempB);
}

int main() {
	vector cards{ 10 };
	int cnt = 1;
	int res = maxmiumScore(cards, cnt);
	cout << res << "\n";
}