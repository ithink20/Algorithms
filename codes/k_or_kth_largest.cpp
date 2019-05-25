/*
	@author : vikasc
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <climits>
#include <utility>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long int lint;

void min_heapify(int *A, int i, int N) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int min_num;
	if (left <= N && A[left] < A[i]) {
		min_num = left;
	} else {
		min_num = i;
	}
	if (right <= N && A[right] < A[min_num]) {
		min_num = right;
	}
	if (min_num != i) {
		swap(A[i], A[min_num]);
		min_heapify(A, min_num, N);
	}
}

void __build_minHeap(int *A, int N) {
	for (int i = N / 2; i >= 0; --i) {
		min_heapify(A, i, N);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int A[N + 1];
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int k;
	cin >> k;
	__build_minHeap(A, k - 1);
	for (int i = k; i < N; ++i) {
		if (A[i] > A[0]) {
			A[0] = A[i];
			min_heapify(A, 0, k - 1);
		}
	}
	cout << A[0] << endl;
	// k largest elements
	//for (int i = 0; i < k; ++i) {
	//	cout << A[i] << " ";
	//}
	return 0;
}
