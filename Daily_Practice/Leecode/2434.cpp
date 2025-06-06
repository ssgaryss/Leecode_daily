#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

string robotWithString(string s) {
	string res;
	stack<char> stack;
	unordered_map<char, int> count;
	for (auto c : s)
		count[c]++;

	char min = 'a';
	for (char c : s) {
		stack.emplace(c);
		count[c]--;
		while (count[min] == 0 && min < 'z') {
			min++;
		}
		while (!stack.empty() && stack.top() <= min) {
			res.push_back(stack.top());
			stack.pop();
		}
	}
	return res;
}

int main(int argc, char** argv) {
	string s = "zyxwvutsrqponmlkjihgfedcbazyxwvutsrqponmlkjihgfedcbzyxwvutsrqponmlkjihgfedczyxwvutsrqponmlkjihgfedzyxwvutsrqponmlkjihgfezyxwvutsrqponmlkjihgfzyxwvutsrqponmlkjihgzyxwvutsrqponmlkjihzyxwvutsrqponmlkjizyxwvutsrqponmlkjzyxwvutsrqponmlkzyxwvutsrqponmlzyxwvutsrqponmzyxwvutsrqponzyxwvutsrqpozyxwvutsrqpzyxwvutsrqzyxwvutsrzyxwvutszyxwvutzyxwvuzyxwvzyxwzyxzyz"s;
	auto res = robotWithString(s);
	cout << res << endl;
}