/*	
	by : Vikas Chaurasiya
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <vector>
#include <set>
#include <climits>
#include <map>
#include <string>

using namespace std;

typedef long long int lint;

vector <int> suffix_helper(vector <pair<string, int> >&A, const string str) {
	for (int i = 0; i < str.length(); ++i) {
		A[i].second = i;
		A[i].first = str.substr(i, str.length());
	}
	sort(A.begin(), A.end());
	vector <int> suffix_array(str.length(), 0);
	for (int i = 0; i < A.size(); ++i) {
		suffix_array[i] = A[i].second;
	}
	return suffix_array;
}

vector <int> buildSuffix(const string str) {
	vector <pair<string, int> >A(str.length(), pair<string, int> ("", 0));
	return suffix_helper(A, str);
}

int main() {
	string str;
	cin >> str;
	vector <int> suffixArray = buildSuffix(str);
	for (int i = 0; i < suffixArray.size(); ++i) {
		cout << suffixArray[i] << " ";
	}
	cout << endl;
	return 0;
}