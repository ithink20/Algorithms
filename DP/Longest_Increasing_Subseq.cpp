
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

int M(int *A, vector<int> &dp, vector<bool> &is_marked, vector<int> &bt, int j) {
    if (j <= 0) {
        return 0;
    }
    if (is_marked[j] != false) {
        // dp[j] : length of longest increasing subsequence ending at j.
        // bt[j] : index of 2nd last element of longest increasing subsequence ending at j.
        return dp[j];
    }
    int ans = 1;
    int ans_last_index = -1;
    for (size_t i = j - 1; i >= 1; i--) {
        if (A[i] < A[j]) {
            // ans = max(ans, M(A, dp, is_marked, backtrack, i) + 1);
            int val = M(A, dp, is_marked, bt, i) + 1;
            if (val > ans) {
                ans = val;
                ans_last_index = i;
            }
        }
    }
    dp[j] = ans;
    bt[j] = ans_last_index;
    is_marked[j] = true;
    return dp[j];
}

int main() {
    int N;
    cin >> N;
    int A[N + 1];
    vector<int> dp(N + 1);
    vector<bool> is_marked(N + 1, false);
    vector<int> backtrack(N + 1, -1);
    for (size_t i = 1; i <= N; i++) {
        cin >> A[i];
    }
    // length of longest increasing subsequence ending at N.
    int ans = 0, last_index = -1;
    for (int i = N; i >= 1; --i) {
        int val = M(A, dp, is_marked, backtrack, i);
        if (val > ans) {
            ans = val;
            last_index = i;
        }
    }
    cout << ans << endl;
    // bt[j] : index of 2nd last element of longest increasing subsequence ending at j.
    if (last_index != -1) {
        int index = last_index;
        vector<int> result;
        while (index >= 1) {
            result.push_back(A[index]);
            index = backtrack[index];
        }
        for (int i = result.size() - 1; i >= 0; --i) {
            cout << result[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No element found" << endl;
    }
    return 0;
}