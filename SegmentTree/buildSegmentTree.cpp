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

int main() {
    int N;
    cin >> N;
    int A[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int tree[2 * N];
    buildSegmentTree(A, tree, 0, N - 1, 1);
    for (int i = 1; i < 2 * N; ++i) {
        cout << tree[i] << " ";
    }
    cout << endl;
    return 0;
}
