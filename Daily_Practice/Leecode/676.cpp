#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class MagicDictionary {
public:
	MagicDictionary() {
	}

	void buildDict(vector<string> dictionary) {
		m_Words = dictionary;
	}

	bool search(string searchWord) {
		for (const auto& word : m_Words)
		{
			if (word.size() != searchWord.size())
				continue;
			int diffChar = 0;
			for (int i = 0; i < (int)word.size(); ++i) {
				if (word[i] != searchWord[i])
					diffChar++;
				if (diffChar > 1)
					break;
			}
			if (diffChar == 1)
				return true;
		}
		return false;
	}
private:
	vector<string> m_Words;
};

int main() {
	MagicDictionary* obj = new MagicDictionary();
	obj->buildDict({ "hello", "leetcode" });
	cout << boolalpha;
	cout << obj->search("leetcodd"s);
}