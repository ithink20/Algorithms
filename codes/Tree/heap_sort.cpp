/*
	author: @vikasc	
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

void build_maxHeap(int *A, int N) {
	for (int i = N/2; i >= 0; --i) {
		max_heapify(A, i, N);
	}
}

void heap_sort(int *A, int N) {
	build_maxHeap(A, N - 1);
	int heap_size = N;
	for (int i = N - 1; i >= 1; --i) {
		swap(A[0], A[i]);
		heap_size -= 1;
		max_heapify(A, 0, heap_size - 1);
	}
}

int main() {
	int N;
	cin >> N;
	int A[N + 1];
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	heap_sort(A, N);
	for (int i = 0; i < N; ++i) {
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
