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

vector<bool> visited(10, false);
stack<int> S;

void __sortHelper(vector< vector<int> > &A, int i) {
	visited[i] = true;
	for (int j = 0; j < A[i].size(); ++j) {
		int node = A[i][j];
		if (!visited[node]) {
			__sortHelper(A, node);
		}
	}
	S.push(i);
}

void __topologicalSort(vector< vector<int> > &A, int N) {
	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {
			__sortHelper(A, i);
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << S.top() << " ";
		S.pop();
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
    cin >> N >> M;
    vector< vector<int> > A(N + 1);
    int u, v;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        A[u].push_back(v);
    }
    cout << endl;
    for (int i = 0; i < N + 1; ++i) {
		cout << i << "-- ";
		for (int j = 0; j < A[i].size(); ++j) {
			cout << A[i][j] << " ";
        }
        cout << endl;
    }
	__topologicalSort(A, N);
	return 0;
}