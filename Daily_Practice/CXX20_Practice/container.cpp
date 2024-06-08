#include <iostream>
#include <list>
#include <deque>
#include <vector>

#include <queue>
#include <stack>

#include <map>

int main() {
	std::list<int> list1 = { 1, 2, 3, 4, 5 };
	std::list<int> list2 = { 10, 11, 12 };

	// 将 list2 中的所有元素移动到 list1 的开头
	list1.splice(list1.end(), list2);

	std::cout << "list1 : ";
	for (int n : list1) {
		std::cout << n << " ";
	}
	std::cout << std::endl;

	std::cout << "list2 : ";
	for (int n : list2) {
		std::cout << n << " ";
	}
	std::cout << std::endl;

	std::map<int, std::string> datamap;
	auto ret = datamap.insert({ 1, "hello" }); //ret类型：pair<map<int, string>::iterator, bool>
	ret = datamap.insert({ 2, "hello" });
	ret = datamap.insert({ 1, "hello" });
	if (ret.second)
		std::cout << "Insert succeeded!" << "\n";
	else
		std::cout << "Insert failed!" << "\n";

	if (auto res{ datamap.insert(std::make_pair(3, "sss")) }; res.second)
		std::cout << "Insert succeeded!" << "\n";
	else
		std::cout << "Insert failed!" << "\n";

	//虽然success = false，但是覆盖“sss”
	if (auto [iter, success] { datamap.insert_or_assign(3, "aaa") }; success)
		std::cout << "Insert succeeded!" << "\n";
	else
		std::cout << "Insert failed!" << "\n";

	std::cout << "3 : " << datamap.find(3)->second << "\n";

	std::map<int, std::string> map2;
	map2.insert(datamap.extract(1));
	std::cout << std::boolalpha;
	std::cout << "datamap have 1 : " << (bool)datamap.count(1) << "\n";
	std::cout << "map2 have 1 : " << (bool)map2.count(1) << "\n";
	std::cout << std::noboolalpha;
}