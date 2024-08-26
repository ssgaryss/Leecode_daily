#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace	std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

class Employee {
public:
	int id;
	int importance;
	vector<int> subordinates;
	Employee(int id, int importance, vector<int> subordinates)
		: id{ id }, importance{ importance }, subordinates{ subordinates } {}
};

int getImportance(vector<Employee*> employees, int id) {
	int n = (int)employees.size();
	auto it = find_if(employees.begin(), employees.end(), [&id](Employee* e) {
		return e->id == id;
		});
	Employee* Root = *it;
	int res = Root->importance;
	function<void(Employee*)> dfs = [&dfs, &employees, &res](Employee* cur) {
		if (cur->subordinates.size() == 0)
			return;
		for (const auto& it : cur->subordinates) {
			auto sub = find_if(employees.begin(), employees.end(), [&it](Employee* e) {
				return e->id == it;
				});
			Employee* sub_instance = *sub;
			res += sub_instance->importance;
			dfs(sub_instance);
		}
		};
	dfs(Root);
	return res;
}

int main() {
	Employee* A = new Employee(2, 3, vector<int>());
	Employee* B = new Employee(3, 3, vector<int>());
	Employee* Root = new Employee(1, 5, { 2, 3 });
	vector<Employee*> employees;
	employees.emplace_back(Root);
	employees.emplace_back(A);
	employees.emplace_back(B);
	int res = getImportance(employees, 1);
	cout << res << "\n";
	delete Root;
	delete B;
	delete A;
}