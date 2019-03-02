/*
	@author : vikasc
	problem : Given an array arr[], find the maximum j – i such that arr[j] > arr[i].
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

void __getMaxDiff(int *A, int N) {
	int Lmin[N + 1], Rmax[N + 1];
	Lmin[0] = A[0];
	for (int i = 1; i < N; ++i) {
		Lmin[i] = min(Lmin[i - 1], A[i]);
	}
	Rmax[N - 1] = A[N - 1];
	for (int i = N - 2; i >= 0; --i) {
		Rmax[i] = max(Rmax[i + 1], A[i]);
	}
	int i = 0, j = 0, max_diff = -1;
	while (i < N && j < N) {
		if (Lmin[i] < Rmax[j]) {
			max_diff = max(max_diff, j - i);
			j += 1;
		} else {
			i += 1;
		}
	}
	cout << max_diff << endl;
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
	__getMaxDiff(A, N);
	return 0;
}