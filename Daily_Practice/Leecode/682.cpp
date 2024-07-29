#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	return 0;
	}() };

int calPoints(vector<string>& operations) {
	int n = (int)operations.size();
	vector<int> scores;
	scores.reserve(n);
	for (auto& operation : operations) {
		if (operation == "C")
			scores.pop_back();
		else if (operation == "D")
			scores.emplace_back(scores.back() * 2);
		else if (operation == "+")
			scores.emplace_back(scores.back() + *(scores.end() - 2));
		else
			scores.emplace_back(std::stoi(operation));
	}
	return reduce(scores.begin(), scores.end());
}

int main(int argc, char* argv[]) {
	vector<string> operations{ "5","2","C","D","+" };
	int res = calPoints(operations);
	cout << res << "\n";
}