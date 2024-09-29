#include <iostream>
#include <vector>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
	int n = (int)tickets.size();
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (i <= k)
			res += tickets[i] >= tickets[k] ? tickets[k] : tickets[i];
		else
			res += tickets[i] >= tickets[k] - 1 ? tickets[k] - 1 : tickets[i];
	}
	return res;
}

int main() {
	vector tickets{ 2,3,2 };
	int k = 2;
	cout << timeRequiredToBuy(tickets, k) << "\n";
}