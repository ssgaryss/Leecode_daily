#include <iostream>
#include <ranges>
#include <format>
#include <vector>
#include <iterator>
using namespace std;


int main() {
	//输入必须满足  < 10否则退出循环
	for (auto value : std::ranges::istream_view<int>(std::cin)
		| std::views::take_while([](auto v) {return v < 10; })
		| std::views::transform([](int v) {return v * 2; })) {
		cout << format("> {0}", value) << "\n";
	}
	cout << "Terminating ... " << endl;
	//输入的数据存入vector
	vector<int> store;
	cout << "---------------" << endl;
	std::ranges::copy(std::ranges::istream_view<int>(std::cin) | std::views::take_while([](auto v) {return v % 2 == 0; }),
		std::back_inserter(store));
	cout << "---------------" << endl;
	std::copy(store.begin(), store.end(), std::ostream_iterator<int>(std::cout, " "));
	cout << "\n" << "Terminating ... " << endl;
}