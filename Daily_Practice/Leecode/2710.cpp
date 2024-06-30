#include <iostream>
#include <string>
using namespace std;

//string removeTrailingZeros(string num) {
//	int n = num.length();
//	for (int i = n - 1; i >= 0; --i) {
//		if (num[i] != '0') 
//			return num.substr(0, i + 1);
//	}
//	return num;
//}

string removeTrailingZeros(string num) {
	return num.substr(0, num.find_last_not_of('0') + 1);
}


int main() {
	string num{ "51230100" };
	auto res{ removeTrailingZeros(num) };
	cout << res << "\n";
}