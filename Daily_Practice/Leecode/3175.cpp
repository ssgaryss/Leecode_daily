#include <iostream>
#include <vector>
using namespace std;

int findWinningPlayer(vector<int>& skills, int k) {
    int n = (int)skills.size();
    int cnt = 0;
    int i = 0, last_i = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && skills[j] < skills[i] && cnt < k) {
            j++;
            cnt++;
        }
        if (cnt == k) {
            return i;
        }
        cnt = 1;
        last_i = i;
        i = j;
    }
    return last_i;
}

int main() {
	vector skills{ 4,2,6,3,9 };
	int k = 2;
	cout << findWinningPlayer(skills, k) << "\n";
}