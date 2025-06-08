#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

vector<int> lexicalOrder(int n) {
	vector<int> res(n);
	std::iota(res.begin(), res.end(), 1);
	std::sort(res.begin(), res.end(), [](int a, int b) {
		return std::to_string(a) < std::to_string(b);
		});
	return res;
}

int main(int argc, char** argv) {
	int n = 13;
	auto res = lexicalOrder(n);
	std::copy(res.begin(), res.end(), std::ostream_iterator<int>(cout, ", "));
}