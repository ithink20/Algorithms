#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>

using namespace std;
typedef long long int lint;

// uncomment line below to enable debugging
// #define ENABLE_DEBUGGING

#if defined(ENABLE_DEBUGGING) || defined(DDD)
#define SOURCE_INFO_COUT "[" << __FUNCTION__ <<  "():" << __LINE__ << "] "
#define debug_print0(...) do { cout << SOURCE_INFO_COUT << #__VA_ARGS__ << endl; } while (0)
#define debug_print1(x) do { cout << SOURCE_INFO_COUT << #x "::" << x << endl; } while (0)
#define debug_print2(x, y) do { cout << SOURCE_INFO_COUT << #x "::" << x << ", " #y "::" << y << endl; } while (0)
#define debug_print3(x, y, z) do { cout << SOURCE_INFO_COUT << #x "::" << x << ", " #y "::" << y << ", " #z "::" << z << endl; } while (0)
#define debug_print4(x, y, z, z1) do { cout << SOURCE_INFO_COUT << #x "::" << x << ", " #y "::" << y << ", " #z "::" << z << ", " #z1 "::" << z1 << endl; } while (0)
#else
#define debug_print0(...)
#define debug_print1(x)
#define debug_print2(x, y)
#define debug_print3(x, y, z)
#define debug_print4(x, y, z, z1)
#endif

//O(N)
void buildSegmentTree(int *A, int *tree, int start, int end, int tree_node) {
    // base case: leaf node is the actual input array elements;
    if (start == end) {
        tree[tree_node] = A[start];
        return;
    }
    int mid = (start + end) / 2;
    buildSegmentTree(A, tree, start, mid, 2 * tree_node);
    buildSegmentTree(A, tree, mid + 1, end, 2 * tree_node + 1);
    tree[tree_node] = tree[2 * tree_node] + tree[2 * tree_node + 1];
}


// O(logN)
int solveQuery(int *tree, int start, int end, int l, int r, int tree_node) {
    //No overlap: range completely outside.
    if (l > end || r < start) {
        return 0;
    }
    //Total overlap: range completely inside.
    if (l <= start && end <= r) {
        return tree[tree_node];
    }
    //Partial overlap: not completely inside or outside.
    int mid = (start + end) / 2;
    int left = solveQuery(tree, start, mid, l , r, 2 * tree_node);
    int right = solveQuery(tree, mid + 1, end, l, r, 2 * tree_node + 1);
    return left + right;
}

int main() {
    int N;
    cin >> N;
    int A[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int tree[2 * N];
    buildSegmentTree(A, tree, 0, N - 1, 1);
    int Q, l, r;
    cin >> Q;       //queries;
    while(Q--) {
        cin >> l >> r;
        cout << solveQuery(tree, 0, N - 1, l, r, 1) << endl;
    }
    return 0;
}
