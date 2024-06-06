#include <iostream>
#include <iterator>
#include <vector>
#include <list>
using namespace std;

template<typename T>
void iteratorTraits(T it) {
	typename iterator_traits<T>::value_type temp; //temp 为 it类型
	temp = *it;
	cout << temp << endl;
}

template<typename T>
void myPrint(T begin, T end) {
	for (auto it{ begin }; it != end; ++it) cout << *it << " ";
}

int main() {
	vector v{ 5 };
	iteratorTraits(cbegin(v));
	vector<int> test{ 1,85,6,9,5,65,6,5,58 };
	myPrint(test.begin(), test.end());
	for (auto it = cbegin(test); it != cend(test); ++it) {
		cout << *it << " ";
	}
	cout << "\n";
	copy(test.begin(), test.end(), ostream_iterator<int>(cout, ", "));
	auto it = find(begin(test), end(test), 5);
	auto it1 = find(rbegin(test), rend(test), 5);
	cout << "\n" << "it index = " << distance(test.begin(), it) << " " << distance(it, test.begin()) << "\n";
	cout << "\n" << "it index = " << distance(test.rbegin(), it1) << " " << distance(it1, test.rbegin()) << "\n";
	// 使用输入流迭代器从标准输入流读取整数，并存储到 vector 中
	vector<int> numbers;                 //back_insert_iterator
	std::copy(std::istream_iterator<int>(cin), std::istream_iterator<int>(), std::back_inserter(numbers));
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(cout, " "));
	cout << endl;
	vector<int> numbers_insert(4, -1);   //insert_iterator
	std::copy(numbers.begin(), numbers.end(), std::inserter(numbers_insert, numbers_insert.begin() + 2));
	std::copy(numbers_insert.begin(), numbers_insert.end(), std::ostream_iterator<int>(cout, " "));
	cout << endl;
	//vector numbers_front(4, -2); //vector 不能push_front，它是顺序容器
	std::list<int> numbers_front(4, -2); //front_insert_iterator
	std::copy(numbers.begin(), numbers.end(), std::front_inserter(numbers_front));
	std::copy(numbers_front.begin(), numbers_front.end(), std::ostream_iterator<int>(cout, " "));
	cout << endl;

	auto ins = std::inserter(numbers, numbers.begin() + 2);
	*ins = 100;
	*(ins++) = 101;
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(cout, " "));

}