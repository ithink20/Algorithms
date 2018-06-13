#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
	int get_min_length(vector <string> &A) {
		int min_len = INT_MAX;
		for (int i = 0; i < A.size(); ++i) {
			if (A[i].size() < min_len) {
				min_len = A[i].size();
			}
		}
		return min_len;
	}

	bool all_contains_prefix(vector <string> &A, string str, int l, int h) {
		for (int  i = 0; i < A.size(); ++i) {
			for (int j = l; j <= h; ++j) {
				if (A[i][j] != str[j]) {
					return false;
				}
			}
		}
		return true;
	}

	string longestCommonPrefix(vector <string> &A) {
		if (A.empty()) {
			return "";
		}
		int min_len = get_min_length(A);
		string common_prefix;
		int l = 0, h = min_len;
		while (l <= h) {
			int mid = l + (h - l)/2;
			if (all_contains_prefix(A, A[0], l, mid)) {
				common_prefix += A[0].substr(l, mid - l + 1);
				l = mid + 1;		// right part
			} else {
				h = mid - 1;	// left part
			}
		}
		return common_prefix;
	}
};

int main() {
	int N;
	cin >> N;
	vector <string> A(N, "");
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	Solution a;
	cout << a.longestCommonPrefix(A) << endl;
	return 0;
}