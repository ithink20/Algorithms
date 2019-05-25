#include <iostream>
#include <algorithm>

using namespace std;

bool p(int *A, int N, int mid, int k) {
	int cow = 1, prev = A[0];
	for (int i = 1; i < N; ++i) {
		if (A[i] - prev >= mid) {
			prev = A[i];
			cow++;
			if (cow == k) {
				return true;
			}
		}
	}
	return false;
}

void binary_search(int *A, int N, int k) {
	int l = 0, h = A[N - 1], max = -1;
	while (l < h) {
		int mid = l + (h - l)/2;
		if (p(A, N, mid, k) == true) {
			if (max < mid)
				max = mid;
			l = mid	+ 1;
		} else {
			h = mid;
		}
	}
	cout << max << endl;
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int N, k;
		cin >> N >> k;
		int A[N + 1];
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A, A + N);
		binary_search(A, N, k);
	}	
	return 0;
}