#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <string>

#include <vector>
#include <set>
#include <map>

typedef long long int lint;

using namespace std;

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

int M(const vector <pair<int, int> >&A, vector< vector<int> > &dp, vector<int> &bt, int j, int N) {
    if (j <= 0) {
        return 0;
    }
    if (dp[j][N] != -1) {
        return dp[j][N];
    }
    int ans = M(A, dp, bt, j, N - 1);
    int ans_last_index = bt[j];
    for (int i = 1; i <= N; ++i) {
        if (j >= A[i].first) {
            //ans = max(ans, M(A, dp, j - A[i].first, i - 1) + A[i].second);
            int val = M(A, dp, bt, j - A[i].first, i - 1) + A[i].second;
            if (val > ans) {
                ans = val;
                ans_last_index = i;
            }
        }
    }
    dp[j][N] = ans;
    bt[j] = ans_last_index;
    return ans;
}

int main() {
    int N, C;
    cin >> N >> C;
    vector <pair<int, int> > A(N + 1);
    vector<vector <int> > dp(C + 1, vector <int> (C, -1));
    vector<int> bt(C + 1);
    int w, v;
    for (int i = 1; i <= N; ++i) {
        cin >> w >> v;
        A[i].first = w;
        A[i].second = v;
    }
    cout << M(A, dp, bt, C, N) << endl;
    int index = bt[C];
    int capacity_left = C;
    while (index >= 1) {
        cout << A[index].second << " ";
        capacity_left -= A[index].first;
        index = bt[capacity_left];
    }
    return 0;
}

/* i is from 1 ----- N and j is from 1 -------- C
       M(i, j) : optimal value of filling exactly a capacity j knapsack with some subset 1 to i

       M(i, j) :   max{M(i - 1, j), M(i - 1, j - wi) + vi};
      Two cases: i'th item either rejected or accepted.

     Ex.    wi : 2 3 4 5 9   (indexing 1 to N)
        vi :    3 4 5 8 10
        capacity C = 20.

    for subset (index 1 to 4)
        max.weight = 2+3+4+5 = 14
        max.value = 3+4+5+8 = 20
    for subset (index 1 to 5 excluding index 2), optimal solution is:
        max. weight = 2+4+5+9 = 20
        max.value = 3+5+8+10 = 26.
*/
    // here index 2 should be excluded to get max optimal value.
