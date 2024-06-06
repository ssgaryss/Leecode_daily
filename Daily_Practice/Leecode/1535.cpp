#include <iostream>
#include <vector>
using namespace std;

int getWinner(vector<int>& arr, int k) {
	//只需要遍历一遍，如果找不到符合的则是整个数组中的最大值
	int winner = arr[0];
	int winTimes = 0;
	for (int i = 1; i < arr.size(); i++) {
		if (winner > arr[i])
		{
			winTimes++;
		}
		else
		{
			winner = arr[i];
			winTimes = 1;
		}
		if (winTimes >= k) return winner;
	}
	return *max_element(arr.begin(), arr.end());
}

int main() {
	vector<int> arr{ 1,11,22,33,44,55,66,77,88,26,99 };
	int k{ 2 };
	int winner = getWinner(arr, k);
	cout << winner;
}
