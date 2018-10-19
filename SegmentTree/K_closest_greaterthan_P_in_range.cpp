/*An array A is given to you containing N integers.
You need to operate Q queries on the array. Queries are of two types.
1 U P: You need to update value of Au to P.
2 L R P: You need to find Ak such that Ak - P is minimum and Ak > P and L<=k<=R

Input Format:
First Line of input contains a single integer N. Next line contains N space-separated integers, elements of array A.
Next line of input contains a single inter Q.
Q lines follow each containing a query as per described in statement.
Output Format:
For query of type 2,you need to print the value of Ak.if there is no such K print -1.
Print answer for each query in new line.
*/



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

pair<int, int> buildSegmentTree(int *A, vector <pair<int, int> >&tree, int start, int end, int tree_node) {
    if (start == end) {
        tree[tree_node].first = A[start];
        tree[tree_node].second = A[start];
        return make_pair(A[start], A[start]);
    }
    int mid = start + (end - start) / 2;
    pair<int, int> P;
    P.first = min(buildSegmentTree(A, tree, start, mid, 2 * tree_node + 1).first, buildSegmentTree(A, tree, mid + 1, end, 2 * tree_node + 2).first);
    P.second = max(buildSegmentTree(A, tree, start, mid, 2 * tree_node + 1).second, buildSegmentTree(A, tree, mid + 1, end, 2 * tree_node + 2).second);
    return tree[tree_node] = P;
}

void update(int *A, vector<pair<int, int> >&tree, int tree_node, int start, int end, int index, int value) {
    // leaf node
    if (start == end) {
        A[index] = value;
        tree[tree_node] = make_pair(value, value);
    } else {
        int mid = start + (end - start) / 2;
        if (start <= index && index <= mid) {
            update(A, tree, 2 * tree_node + 1, start, mid, index, value);
        } else {
            update(A, tree, 2 * tree_node + 2, mid + 1, end, index, value);
        }
        tree[tree_node] = make_pair(min(tree[2 * tree_node + 1].first, tree[2 * tree_node + 2].first),
                                max(tree[2 * tree_node + 1].second, tree[2 * tree_node + 2].second));
    }
}

// this returns min possible (Ak - P);
int query_solve(vector<pair<int, int> >&tree, int tree_node, int start, int end, int L, int R, int P) {
    //cout << tree[tree_node].second << endl;
    if (tree[tree_node].second < P) {
        return -1;
    }
    //range outside
    if (R < start || end < L) {
        return -1;
    }
    if (L <= start && end <= R && start == end) {
        return tree[tree_node].second - P;
    }
    int mid = (start + end) / 2;
    int p1 = query_solve(tree, 2 * tree_node + 1, start, mid, L, R, P);
    // cout <<"[p1, " << p1 << "] ";
    int p2 = query_solve(tree, 2 * tree_node + 2, mid + 1, end, L, R, P);
    // cout <<"[p2, " << p2 << "] ";
    if (p1 == 0 || p1 == -1) {
        return p2;
    } else if (p2 == 0 || p2 == -1) {
        return p1;
    } else {
        return min(p1, p2);
    }
}

int main() {
    int N;
    cin >> N;
    int A[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector <pair<int, int> >tree(2 * N + 1, make_pair(0, 0));
    buildSegmentTree(A, tree, 0, N - 1, 0);
    // for (int i = 0; i < 2 * N - 1; ++i) {
    //     cout << tree[i].first << " " << tree[i].second << endl;
    // }
    int Q, Q_type, L, R, U, P;
    cin >> Q;
    while (Q--) {
        cin >> Q_type;
        if (Q_type == 1) {
            cin >> U >> P;
            update(A, tree, 0, 0, N - 1, U, P);
            // for (int i = 0; i < N; ++i) {
            //     cout << A[i] << " ";
            // }
            // cout << endl;
            // for (int i = 0; i < 2 * N - 1; ++i) {
            //     cout << "(" << tree[i].first << ", " << tree[i].second << ")";
            // }
            // cout << endl;
        } else {
            cin >> L >> R >> P;
            cout << "A_k : " << query_solve(tree, 0, 0, N - 1, L, R, P) + P << endl;
        }
    }
    return 0;
}
