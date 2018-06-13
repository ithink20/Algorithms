#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef long long int lint;

bool isSafe(int node, vector <vector<int> > &A, vector <int> &color, int c, int N) {
	for (int i = 0; i < N; ++i) {
		if (A[node][i] == 1 && c == color[i]) {
			return false;
		}
	}
	return true;
}

bool graph_coloring_upto(vector <vector<int> > &A, vector<int> &color, int m, int start, int N) {
	if (start == N) {		// base case
		return true;
	}
	for (int c = 1; c <= m; ++c) {
		if (isSafe(start, A, color, c, N) == true) {
			//choose
			color[start] = c;

			//explore
			if (graph_coloring_upto(A, color, m, start + 1, N) == true) {
				return true;
			}

			//unchoose : backtrack
			color[start] = 0;
		}
	}
}

void graph_coloring(vector <vector<int> > &A, int m, int N) {
	vector<int> color(N, 0);
	if (graph_coloring_upto(A, color, m, 0, N) == false) {
		cout << "No Solution" << endl;
		return;
	}
	cout << "color assigned : ";
	for (int i = 0; i < color.size(); ++i) {
		cout << color[i] << " ";
	}
	cout << endl;
}

int main() {
	int N, M;
	cin >> N >> M;
	int u, v;
	vector <vector<int> > A(N, vector<int> (N, 0));
	for (int i = 0; i < M; ++i) {
		cin >> u >> v;
		A[u][v] = 1;
		A[v][u] = 1;
	}
	int m;
	cin >> m;
	graph_coloring(A, m, N);
	return 0;
}