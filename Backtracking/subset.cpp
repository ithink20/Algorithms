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

void subsetHelper(vector <int> &A, vector <int> &subset, vector <vector <int> > &result, int index) {
	for (int i = index; i < A.size(); ++i) {
		//choose
		subset.push_back(A[i]);
		result.push_back(subset);

		//explore
		subsetHelper(A, subset, result, i + 1);

		//unchoose : backtrack
		subset.pop_back();
	}
	return;
}

void subsets(vector <int> &A) {
	vector <int> subset;
	vector <vector <int> > result;
	result.push_back(subset);
	subsetHelper(A, subset, result, 0);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
} 

int main() {
	int N;
	cin >> N;
	vector <int> A(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	subsets(A);
	return 0;
}