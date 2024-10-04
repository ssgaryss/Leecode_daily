#include <iostream>
#include <vector>
using namespace std;

double nthPersonGetsNthSeat(int n) {
	return n == 1 ? 1.0 : 0.5;
}

int main() {
	int n = 2;
	cout << nthPersonGetsNthSeat(n) << "\n";
}