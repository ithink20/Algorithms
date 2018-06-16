#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <vector>
#include <set>
#include <climits>
#include <map>
#include <utility>
#include <string>
#include <fstream>

using namespace std;

typedef long long int lint;

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i) {		// testcase
		cout << "Case #" << i + 1 << ": ";
		int N;
		cin >> N;
		vector <string> S(N, "");
		string temp;
		getchar();							//to handle newline character.
		for (int i = 0; i < N; ++i) {
			getline(cin, S[i]);
		}
		sort(S.begin(), S.end());
		int max = 0;
		string result;
		for (int i = 0; i < N; ++i) {
			set<char> s;
			for (int k = 0; k < S[i].length(); ++k) {
				if (S[i][k] != ' ') {
					s.insert(S[i][k]);
				}
				if (s.size() > max) {
					max = s.size();
					result = S[i];
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}