/*    @author: vikaschaurasiya
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

pair<int, int> count_zeros(vector <int> &A) {
    int count = 0, index = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == 0) {
            count += 1;
            index = i;
        }
    }
    if (count == 1) {
        return make_pair(count, index);
    } else {
        return make_pair(count, -1);
    }
}

void all_other_product(vector <int> &A) {
    int product = 1, multiply = 1;
    for (auto &i : A) {
        product *= i;
    }
    pair<int, int> zeros = count_zeros(A);

    //case1: if array contains single 0;
    if (zeros.first == 1) {
        for (int i = 0; i < A.size(); ++i) {
            if (i != zeros.second) {
                multiply *= A[i];
            }
        }
        for (int i = 0; i < A.size(); ++i) {
            (i == zeros.second) ? A[i] = multiply : A[i] = 0;
        }
    } else if (zeros.first > 1) {
        for (int i = 0; i < A.size(); ++i) {
            A[i] = 0;
        }
    } else {
        for (int i = 0; i < A.size(); ++i) {
            A[i] = product/A[i];
        }
    }
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    vector <int> A(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    all_other_product(A);
    return 0;
}
