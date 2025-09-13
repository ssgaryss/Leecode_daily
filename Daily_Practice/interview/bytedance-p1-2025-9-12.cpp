#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
		int n = 23712;
		vector<int> A{2, 4, 6};

		sort(A.begin(), A.end());
		string nStr = to_string(n);
		int m = static_cast<int>(nStr.size());
		string res;
		bool smaller = false;

		for (int i = 0; i < m; i++) {
				int cur = nStr[i] - '0';
				int chosen = -1;

				if (!smaller) {
						// 找 <= 当前位的最大数字
						for (int d : A) {
								if (d <= cur) chosen = d;
						}
						if (chosen == -1) {
								// 必须回退
								int j = i - 1;
								while (j >= 0) {
										int prev = res[j] - '0';
										int smallerPrev = -1;
										for (int d : A) {
												if (d < prev) smallerPrev = d;
										}
										if (smallerPrev != -1) {
												res[j] = char('0' + smallerPrev);
												// 后面全放最大数
												res = res.substr(0, j + 1);
												while ((int)res.size() < m) res += char('0' + A.back());
												cout << res << "\n";
												return 0;
										}
										j--;
								}
								// 如果完全退不了，构造少一位的最大数
								string alt(m - 1, char('0' + A.back()));
								cout << alt << "\n";
								return 0;
						}
						res += char('0' + chosen);
						if (chosen < cur) smaller = true;
				} else {
						// 已经比 n 小了，直接填最大
						res += char('0' + A.back());
				}
		}

		cout << res << "\n";
		return 0;
}
