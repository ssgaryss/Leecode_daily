#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
	vector<int> res(2);
	unordered_map<int, int> isExists2;
	unordered_map<int, int> isExists1;
	for (int i = 0; i < nums2.size(); ++i)
		isExists2[nums2[i]]++;
	for (int i = 0; i < nums1.size(); ++i) {
		auto index = isExists2.find(nums1[i]);
		if (index != isExists2.end()) {
			res[0]++;
			if(isExists1[nums1[i]] < 1)
				res[1] += (*index).second;
		}
		isExists1[nums1[i]]++;
	}
	return res;

}

int main() {
	vector nums1{ 4,3,2,3,1 };
	vector nums2{ 2,2,5,2,3,6 };
	auto res = findIntersectionValues(nums1, nums2);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
}