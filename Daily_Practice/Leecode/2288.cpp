#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

auto _{ []() noexcept{
	std::ios::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);
	return 0;
}() };

string discountPrices(string sentence, int discount) {
    istringstream sin(sentence);
    ostringstream sout;
    sout << fixed << setprecision(2);
    vector<string> words;
    string word;
    while (sin >> word)
    {
        if (word[0] == '$' && word.size() > 1 && std::all_of(word.begin() + 1, word.end(), ::isdigit)) {
            auto price = stoll(word.substr(1, word.size() - 1)) * (100.0 - (double)discount) / 100.0;
            sout << '$' << price;
        }
        else {
            sout << word;
        }
        sout << " ";
    }
    auto res = sout.str();
    res.pop_back();
    return res;
}

int main() {
	string s = "1 2 $3 4 $5 $6 7 8$ $9 $10$"s;
	int discount = 100;
	string res = discountPrices(s, discount);
	cout << res << "\n";
}