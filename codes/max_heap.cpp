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

void max_heapify(int *A, int i, int N) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int maximum;
	if (left <= N && A[left] > A[i]) {
		maximum = left;
	} else {
		maximum = i;
	}
	if (right <= N && A[right] > A[maximum]) {
		maximum = right;
	}
	if (maximum != i) {
		swap(A[i], A[maximum]);
		max_heapify(A, maximum, N);
	}
}

void build_max_heap(int *A, int N) {
	for (int i = N/2; i >= 0; --i) {
		max_heapify(A, i, N);
	}
}

int main() {
	int N;
	cin >> N;
	int A[N + 1];
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	build_max_heap(A, N - 1);
	for (int i = 0; i < N; ++i) {
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}