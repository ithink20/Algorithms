/*
	@author : vikasc
	problem : A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element).
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

int getCandidate(int *A, int N) {
	int maj_index = 0, count = 1;
	for (int i = 1; i < N; ++i) {
		if (A[maj_index] == A[i]) {
			count += 1;
		} else {
			count -= 1;
		}
		if (count == 0) {
			maj_index = i;
			count = 1;
		}
	}
	return A[maj_index];
}

bool isMajority(int *A, int N, int shortlisted) {
	int freq = 0;
	for (int i = 0; i < N; ++i) {
		if (A[i] == shortlisted) {
			freq += 1;
		}
	}
	if (freq > N/2) {
		return true;
	} else {
		return false;
	}
}

void __majority_element(int *A, int N) {
	int shortlisted = getCandidate(A, N);
	if (isMajority(A, N, shortlisted)) {
		cout << shortlisted << endl;
	} else {
		cout << "No Majority\n";
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
	__majority_element(A, N);
	return 0;
}