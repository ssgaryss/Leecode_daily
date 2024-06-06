#include <iostream>
#include <vector>
using namespace std;

int distributeCandies(int n, int limit) {
	int nums = 0;
	if (n > 3 * limit) return nums;
	for (int i = 0; i <= limit; ++i) {
		int remain = n - i;
		if (remain < 0) break;
		if (remain > 2 * limit)
			continue;
		else {
			if (remain > limit)
				nums += limit - (remain - limit) + 1;
			else
				nums += remain + 1;
		}
	}
	return nums;
}

int main() {
	int n = 3, limit = 1;
	int res = distributeCandies(n, limit);
	cout << res << "\n";

}