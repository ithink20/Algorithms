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

void min_heapify(int *A, int i, int N) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int minimum;
	if (left <= N && A[left] < A[i]) {
		minimum = left;
	} else {
		minimum = i;
	}
	if (right <= N && A[right] < A[minimum]) {
		minimum = right;
	}
	if (minimum != i) {
		swap(A[i], A[minimum]);
		min_heapify(A, minimum, N);
	}
}

void build_min_heap(int *A, int N) {
	for (int i = N/2; i >= 0; --i) {
		min_heapify(A, i, N);
	}
}

int main() {
	int N;
	cin >> N;
	int A[N + 1];
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	build_min_heap(A, N - 1);
	for (int i = 0; i < N; ++i) {
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}