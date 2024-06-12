#include <iostream>
using namespace std;

int accountBalanceAfterPurchase(int purchaseAmount) {
	return purchaseAmount / 10 * 10 + (purchaseAmount % 10 >= 5) * 10;
}

int main(){
	int purchaseAmount = 9;
	int res = accountBalanceAfterPurchase(purchaseAmount);
	cout << res << '\n';
}