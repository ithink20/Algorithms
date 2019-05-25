/*
    @author: vikasc
    problem: Given array of 1s followed by 0s, find no of 0s
    Tag: Amazon
    Time: O(logn)
    Space: O(1)
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <climits>
#include <utility>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long int lint;

int first(int *A, int l, int h) {
    if (h >= l) {
        int mid = l + (h - l) / 2;
        if ((mid == 0 || A[mid - 1] == 1) && A[mid] == 0) {
			return mid;
		} 
		if (A[mid] == 1) {
			return first(A, mid + 1, h);
		} else {
			return first(A, l, mid - 1);
		}
	}
	return -1;
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
    //get first and last occurance of 0
	int first_occurance = first(A, 0, N - 1);
	if (first_occurance == -1) {
		cout << 0 << "\n";
	} else {
		cout << N - first_occurance << "\n";
	}
	return 0;
}