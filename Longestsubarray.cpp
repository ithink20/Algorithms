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

void getSubarray(vector <int> &A) {
	int sumLeft[A.size()];	//sum of array from indices  0 to i;

	sumLeft[0] = ((A[0] == 0) ? -1 : 1);
	int min = A[0], max = A[0], max_length = -1, start_index;


	for (int i = 1; i < A.size(); ++i) {
		sumLeft[i] = sumLeft[i - 1] + ((A[i] == 0) ? -1 : 1);
		if (sumLeft[i] > max) {
			max = sumLeft[i];
		}
		if (sumLeft[i] < min) {
			min = sumLeft[i];
		}
	}

	vector <int> hash(max - min + 1, -1);
	for (int i = 0; i < A.size(); ++i) {
		// if subarray starts from 0 index;
		if (sumLeft[i] == 0) {
			max_length = i + 1;
			//start_index = 0;
		}

		// fill the hash table, use it if already filled.
		if (hash[sumLeft[i] - min] == -1) {
			hash[sumLeft[i] - min] = i;
		} else {
			if ((i - hash[sumLeft[i] - min]) > max_length) {
				max_length = i - hash[sumLeft[i] - min];
				//start_index = hash[sumLeft[i] - min] + 1;
			}
		}
	}
	cout << max_length << endl;
	//cout start_index to start_index + max_length - 1   indices
}

int main() {
	int N;
	cin >> N;
	vector <int> A(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		(A[i] & 1) ? A[i] = 1 : A[i] = 0;
	}
	getSubarray(A);
	return 0;
}