/*      
        @author: vikaschaurasiya
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

//2n : total length
//n0 : count 0's; n1: count 1's
// Lexicographical Order

void Helper(char *X, int i, int n0, int n1, int n) {
    //Case1: (n0 < n) and (n1 < n) and n0 > n1  : continue adding 0 and 1
    if (n0 < n && n1 < n && n0 > n1) {
        i += 1;
        //Dyck 0
        X[i] = '0';
        n0 += 1;
        Helper(X, i, n0, n1, n);
        n0 -= 1;

        //Dyck 1
        X[i] = '1';
        n1 += 1;
        Helper(X, i, n0, n1, n);
        n1 -= 1;
    }
    //Case2: (n0 < n) and (n1 < n) and (n0 = n1) : continue adding 0 only
    //Case3: (n0 < n) and (n1 = n) : continue adding 0 only
    if ((n0 < n && n1 < n && n0 == n1) || (n0 < n && n1 == n)) {
        i += 1;
        //Dyck 0
        X[i] = '0';
        n0 += 1;
        Helper(X, i, n0, n1, n);
        n0 -= 1;
    }
    //Case4: (n0 = n) and (n1 < n) : continue adding 1 only
    if (n0 == n && n1 < n) {
        i += 1;
        X[i] = '1';
        n1 += 1;
        Helper(X, i, n0, n1, n);
        n1 -= 1;
    }
    //Case5: (n0 = n) and (n1 = n) : a Dyck word is obtained
    if (n0 == n && n1 == n) {
        cout << X << endl;
    }
    return;
}

void generateDyckWords(int N) {
    char X[2 * N + 1];
    int n0 = 1, n1 = 0;
    X[0] = '0';
    Helper(X, 0, n0, n1, N);
}

int main() {
    int N;
    cin >> N;
    generateDyckWords(N);
    return 0;
}
