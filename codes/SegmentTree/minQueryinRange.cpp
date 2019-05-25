#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <climits>

using namespace std;
typedef long long int lint;

int buildSegmentTree(int *A, int *tree, int start, int end, int tree_node) {
    if (start == end) {
        tree[tree_node] = A[start];
        return A[start];
    }
    int mid = start + (end - start) / 2;
    return tree[tree_node] = min(buildSegmentTree(A, tree, start, mid, 2 * tree_node + 1),
                          buildSegmentTree(A, tree, mid + 1, end, 2 * tree_node + 2));
}

int minQueryHelper(int *tree, int start, int end, int l, int r, int tree_node) {
    //range inside completely;
    if (l <= start && r >= end) {
        return tree[tree_node];
    }
    //range outside
    if (end < l || start > r) {
        return INT_MAX;
    }
    int mid = (start + end) / 2;
    return min(minQueryHelper(tree, start, mid, l, r, 2 * tree_node + 1),
               minQueryHelper(tree, mid + 1, end, l, r, 2 * tree_node + 2));
}

int minQuery(int *tree, int N, int l, int r) {
    if (l < 0 || r > N - 1 || l > r) {
        return -1;      //invalid input;
    }
    return minQueryHelper(tree, 0, N - 1, l, r, 0);
}

int main() {
    int N;
    cin >> N;
    int A[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int tree[2 * N];
    buildSegmentTree(A, tree, 0, N - 1, 0);
    int Q, l, r;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << minQuery(tree, N, l, r) << endl;
    }
    return 0;
}
