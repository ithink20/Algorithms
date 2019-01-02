/*
    author : @vikasc
    time-complexity : O(n)
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
#define MAX 100000

void getPairs(int *A, int N, int target) {
    //init hash.
    bool hash[MAX] = {false};
    int other_element;
    for (int i = 0; i < N; ++i) {
        other_element = target - A[i];
        if (other_element >= 0 && hash[other_element] == true) {
            cout << "pair : " << A[i] << " " << other_element << endl;
        }
        hash[A[i]] = true;
    }
}

int main() {
    int N;
    cin >> N;
    int A[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int target_sum;
    cin >> target_sum;
    getPairs(A, N, target_sum);
    return 0;
}
