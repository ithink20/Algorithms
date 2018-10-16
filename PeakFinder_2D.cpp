//Time complexity: O(N * log(M))
// N : rows, M: cols

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

int getMax(vector<vector<int> >&A, int row, int mid, int &max) {
    int max_index = 0;
    for (int i = 0; i < row; ++i) {
        if (max < A[i][mid]) {
            max = A[i][mid];
            max_index = i;
        }
    }
    return max_index;
}

int PeakFind(vector <vector<int> > &A, int row, int col, int mid) {
    int max = 0;
    int max_index = getMax(A, row, mid, max);
    if (mid == 0 || mid == col - 1) {   //single col only.
        return max;
    }
    if (max >= A[max_index][mid - 1] && max >= A[max_index][mid + 1]) {
        return max;
    }
    if (max < A[max_index][mid - 1]) {
        return PeakFind(A, row, col, mid - mid / 2);
    }
    return PeakFind(A, row, col, mid + mid / 2);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector <int> >A(N + 1, vector<int>(M + 1, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }
    int rows = N, columns = M;
    cout << PeakFind(A, rows, columns, columns / 2) << endl;
    return 0;
}
