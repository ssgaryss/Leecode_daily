#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int maxHeightOfTriangle(int red, int blue) {
	auto maxHeight = [](int first, int second) {
		int i = 1;
		while (first >= 0 && second >= 0)
		{
			if (i % 2)
				first -= i;
			else
				second -= i;
			if (first < 0 || second < 0)
				return i - 1;
			i++;
		}
		return i;
		};
	return max(maxHeight(red, blue), maxHeight(blue, red));
}

int main() {
	int red = 2, blue = 4;
	cout << maxHeightOfTriangle(red, blue) << "\n";
}