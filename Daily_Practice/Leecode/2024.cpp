#include <iostream>
#include <string>
#include <vector>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int maxConsecutiveAnswers(string answerKey, int k) {
	int n = (int)answerKey.size();
	int i = 0, j = 0;
	int num_t = 0, num_f = 0;
	int res = 0;
	while (j < n)
	{
		if (answerKey[j] == 'T') num_t++;
		if (answerKey[j] == 'F') num_f++;
		if (num_t > k && num_f > k) {
			if (answerKey[i] == 'T') num_t--;
			if (answerKey[i] == 'F') num_f--;
			i++;
		}
		if (num_f <= k || num_t <= k) res = max(res, num_t + num_f);
		j++;
	}
	return res;
}

int main() {
	string answerKey = "FFTFTTFTTTTTTTTTTFTTFFFTTTFTTFFFTTTTFTTFFFTFTFFTFFFTFTFFFFFFTTFFTFFFTFFTFTFFFFFTTTTFFTFFFTTFTFTFFFFF";
	int k = 48;
	cout << maxConsecutiveAnswers(answerKey, k) << "\n";
}