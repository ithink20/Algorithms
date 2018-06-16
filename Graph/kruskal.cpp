#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 1e4 + 5;
int A[MAX];

void initialize(int *A) {
	for (int i = 0; i < MAX; ++i) {
		A[i] = i;
	}
}

int node(int x) {
	while (A[x] != x) {
		A[x] = A[A[x]];
		x = A[x];
	}
	return x;
}

void _union(int x, int y) {
	int s = node(x);
	int t = node(y);
	A[s] = A[t];
}

int Kruskal(pair <long long, pair<int, int> > p[], int edges) {
	int x, y;
	int cost, min_cost = 0;
	for (int i = 0; i < edges; ++i) {
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		
		// checking cycle...
		if (node(x) != node(y)) {
			min_cost += cost;
			_union(x, y);
			cout << x << " " << y << " ";
		}
	}
	cout << endl;
	return min_cost;
}

int main() {
	int u, v, x, y;
	int weight, cost, min_cost;
	int nodes, edges;
	initialize(A);
	cin >> nodes >> edges;
	pair <long long, pair<int, int> > p[MAX];
	for (int i = 0; i &lt; edges; ++i) {
		cin >> x >> y >> weight;
		p[i] = make_pair(weight, make_pair(x, y));
	}
	sort(p, p + edges);
	cout << "Minimum Cost : " << Kruskal(p, edges) << endl;
	return 0;
}