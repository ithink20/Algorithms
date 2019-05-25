#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <vector>
#include <set>
#include <climits>
#include <map>
#include <string>
#include <utility>

using namespace std;

typedef long long int lint;

bool cmp(const pair<char, int> &a, const pair<char, int> &b) {
	return a.second > b.second;
}

int main() {
	string str;
	cin >> str;
	vector <pair<char, int> >count(256, pair<char, int>(' ', 0));
	int N = str.length();
	for (int i = 0; i < N; ++i) {
		count[(int)str[i]].first = str[i];
		count[(int)str[i]].second += 1;
	}
	string ans;
	sort(count.begin(), count.end(), cmp);
	for (int i = 0; i < 256; ++i) {
		//cout << count[i].first << " " << count[i].second;
		for (int j = 0; j < count[i].second; ++j) {
			ans.push_back(count[i].first);
		}
	}
	cout << ans << endl;
	return 0;
}