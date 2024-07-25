#include <iostream>
#include <string>
using namespace std;

int minimumOperations(string num) {
	// Ñ°ÕÒÐòÁÐ00£¬25£¬50£¬75
	int n = num.length();
	int Index0 = -1, Index5 = -1;
	int lengthA = 1000000, lengthB = 1000000;
	for (int i = n - 1; i >= 0; --i) {
		if (Index0 != -1 && (num[i] == '0' || num[i] == '5')) {
			lengthA = Index0 - i - 1;
			break;
		}
		if (Index5 != -1 && (num[i] == '2' || num[i] == '7')) {
			lengthB = Index5 - i - 1;
			break;
		}
		if (Index0 == -1 && num[i] == '0')
			Index0 = i;
		if (Index5 == -1 && num[i] == '5')
			Index5 = i;
	}
	if (lengthA == 1000000 && lengthB == 1000000) {
		if (Index0 == -1)
			return n;
		else
			return n - 1;
	}
	return min(lengthA + n - 1 - Index0, lengthB + n - 1 - Index5);
}

int main() {
	string num = "25"s;
	int res = minimumOperations(num);
	cout << res << "\n";
}