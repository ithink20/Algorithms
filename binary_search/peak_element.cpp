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

int peak_helper(vector <int> &A, int l, int h) {
	if (l <= h) {
		int mid = l + (h - l)/2;
		if (((mid == 0) || A[mid - 1] <= A[mid]) && (mid == A.size() - 1 || A[mid + 1] <= A[mid])) {
			return mid;
		} else if (mid > 0 && A[mid - 1] > A[mid]) {
			return peak_helper(A, l, mid - 1);
		} else {
			return peak_helper(A, mid + 1, h);
		}
	}
}

int getPeak(vector <int> &A) {
	return peak_helper(A, 0, A.size() - 1);
}

int main() {
	int N;
	cin >> N;
	vector <int> A(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	cout << A[getPeak(A)] << endl;
	return 0;
}