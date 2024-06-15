#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include <iomanip>

int main() {
	// remove
	std::vector<int> nums{ 85,16,5,6,6,3,26,6,6,6,8 };
	auto it = std::remove(std::begin(nums), std::end(nums), 6);
	std::copy(std::begin(nums), std::end(nums), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	nums.erase(it, std::end(nums));
	std::copy(std::begin(nums), std::end(nums), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	// unique(删除相邻重复元素，若不想排序，注意不相邻重复元素不会删除）
	std::vector<int> nums2{ 85,16,5,6,6,3,26,6,6,6,8 };
	std::sort(std::begin(nums2), std::end(nums2), std::less<>());
	std::cout << "是否已排序 ：" << std::boolalpha << std::is_sorted(std::begin(nums2), std::end(nums2));
	std::cout << std::endl;
	auto it1 = std::unique(std::begin(nums2), std::end(nums2));
	std::copy(std::begin(nums2), std::end(nums2), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	nums2.erase(it1, std::end(nums2));
	std::copy(std::begin(nums2), std::end(nums2), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	// shuffle(洗牌算法）
	std::random_device seeder;
	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };
	std::default_random_engine engine{ static_cast<std::default_random_engine>(seed) };
	std::vector<int> nums3{ 85,16,5,6,6,3,26,6,6,6,8 };
	std::copy(std::begin(nums3), std::end(nums3), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::shuffle(std::begin(nums3), std::end(nums3), engine);
	std::copy(std::begin(nums3), std::end(nums3), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//nth_element
	std::vector<int> nums4{ 85,16,5,6,6,3,26,6,6,6,8 };
	std::copy(std::begin(nums4), std::end(nums4), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::nth_element(std::begin(nums4), nums4.begin() + 1, std::end(nums4), std::less<>());
	std::copy(std::begin(nums4), std::end(nums4), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}