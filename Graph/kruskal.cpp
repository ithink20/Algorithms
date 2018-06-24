#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>

using namespace std;
typedef long long int lint;
const int MAX = 1e4 + 5;

// Time Complexity : O(MlogN), M - egdes, N - vertices

void initialise(int *id) {
    for (int i = 0; i < MAX; ++i) {
        id[i] = i;
    }
}

int root(int *id, int i) {
    while (id[i] != i) {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void _union(int *id, int x, int y) {
    int root_x = root(id, x);
    int root_y = root(id, y);
    id[root_x] = id[root_y];
}

int helper(pair<int , pair<int, int> > *A, int *id, int M) {
    int x, y, cost, minimum_cost = 0;
    for (int i = 0; i < M; ++i) {

        //pick each edge in increasing order(sorted).
        x = A[i].second.first;
        y = A[i].second.second;
        cost = A[i].first;
        //check if selecting edge is creating cycle or not.
        if (root(id, x) != root(id, y)) {
            minimum_cost += cost;
            cout << "{" << x << " " << y << " : " << cost << "} ";
            _union(id, x, y);
        }
    }
    return minimum_cost;
}

int kruskal(pair<int , pair<int, int> > *A, int M) {
    int id[MAX];
    initialise(id);
    return helper(A, id, M);
}

int main() {
    pair<int , pair<int, int> >A[MAX];
    int N, M;
    cin >> N >> M;
    int u, v, wt;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v >> wt;
        A[i] = make_pair(wt, make_pair(u, v));
    }
    sort(A, A + M);
    cout << "Minimum cost : " << kruskal(A, M) << endl;
    return 0;
}
