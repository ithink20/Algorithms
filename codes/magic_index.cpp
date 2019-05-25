/*
  Q - A magic index in an array[0....n-1] is defined to be an index such that A[i] = i.Given a
  sorted array of distinct integers, write a method to find a magic index if one exits in array A

  additonal: what if values are not distinct?

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

/*int magic_helper(int *A, int start, int end, int A_size) { // if values are distinct & sorted.
 	if (end < start || start < 0 || end >= A_size) {
 		return -1;
 	}
 	int mid = (start + end)/2;
 	if (A[mid] == mid) {
 		return mid;
 	} else if (A[mid] > mid) {
 		magic_helper(A, start, mid - 1, A_size);
 	} else {
 		magic_helper(A, mid + 1, end, A_size);
 	}
}*/

int magic_helper(int *A, int start, int end, int A_size) {	// if values are not distinct.
	if (end < start || start < 0 || end >= A_size) {
 		return -1;
 	}
 	int midIndex = (start + end)/2;
 	int midValue = A[midIndex];
 	if (midValue == midIndex) {
 		return midIndex;
 	}

 	// search left
 	int left = magic_helper(A, start, min(midIndex - 1, midValue), A_size);
 	if (left >= 0) {
 		return left;
 	}

 	//search right
 	int right = magic_helper(A, max(midIndex + 1, midValue), end, A_size);
 	if (right >= 0) {
 		return right;
 	}
}

int magic_index(int *A, int start, int end) {
	int A_size = end + 1;
	return magic_helper(A, start, end, A_size);
}

int main() {
	int N;
	cin >> N;
	int A[N + 1];
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	cout << magic_index(A, 0, N - 1) << endl;
	return 0;
}