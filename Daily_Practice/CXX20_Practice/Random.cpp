#include <random>
#include <iostream>
#include <functional>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
	random_device seeder;
	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };
	mt19937 engine{ static_cast<std::mt19937::result_type>(seed) };
	uniform_int_distribution<int> distribution{ 0, 99 };
	uniform_int_distribution<int> distribution2{ -100, -1 };

	vector<int> values(10);
	generate(begin(values), end(values), [&distribution, &engine]() {
		return distribution(engine);
		});
	copy(begin(values), end(values), ostream_iterator<int>(cout, " "));
	cout << "\n";
	cout << static_cast<float>(std::numeric_limits<uint32_t>::max()) << "\n";
}