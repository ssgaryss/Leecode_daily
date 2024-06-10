#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto _{ []() noexcept {
	std::ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	return 0;
	}() };

// 时间复杂度为O(n^2)
//int numRescueBoats(vector<int>& people, int limit) {
//	int n = people.size();
//	int res = 0;
//	sort(people.begin(), people.end(), std::greater());
//	for (int i = 0; i < n; ++i) {
//		if (people[i] == -1) continue;
//		int temp = limit - people[i];
//		people[i] = -1;
//		for (int j = n - 1; j > i; --j) {
//			if (people[j] == -1) continue;
//			if (people[j] <= temp) {
//				people[j] = -1;
//				break;
//			}
//		}
//		res++;
//	}
//	return res;
//}

// 改进后 O(n)
int numRescueBoats(vector<int>& people, int limit) {
	int n = people.size();
	int res = 0;
	sort(people.begin(), people.end(), std::greater());
	int i = 0, j = n - 1;
	while (i <= j)
	{
		if (people[i] + people[j] <= limit) ++i, --j;
		else ++i;
		res++;
	}
	return res;
}

int main() {
	vector<int> people{ 3,2,3,2,2 };
	int limit = 6;
	int res{ numRescueBoats(people, limit) };
	cout << res << "\n";

}