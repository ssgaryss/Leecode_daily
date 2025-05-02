#include <iostream>
#include <vector>
#include <string>

using namespace std;

string pushDominoes(string dominoes) {
	int n = static_cast<int>(dominoes.length());
	dominoes = "L" + dominoes + "R"; // 开始补一个L，最后补一个R
	char l = 'L';
	char r = 'R';
	int count = 0;
	for (int i = 0; i < n + 2; ++i) {
		if (dominoes[i] == '.') {
			count++;
		}
		else {
			if (count > 0) {
				r = dominoes[i];
				l = dominoes[i - count - 1];

				if (l == 'L' && r == 'L') {
					for (int j = i - count; j < i; ++j) {
						dominoes[j] = 'L';
					}
				}
				else if (l == 'R' && r == 'R') {
					for (int j = i - count; j < i; ++j) {
						dominoes[j] = 'R';
					}
				}
				else if (l == 'R' && r == 'L') {
					for (int j = i - count; j < i; ++j) {
						if (j < i - (count + 1) / 2) {
							dominoes[j] = 'R';
						}
						else if (j > i - ((count + 1) % 2 == 0 ? (count + 1) / 2 : (count + 1) / 2 + 1)) {
							dominoes[j] = 'L';
						}
					}
				}
				count = 0;
			}
		}
	}
	return dominoes.substr(1, n);
}

int main(int argc, char* argv[]) {
	string dominoes = ".L.R...LR..L.."s;
	auto res = pushDominoes(dominoes);
	cout << res << "\n";
}