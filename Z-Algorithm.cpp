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

void seive(int n) {
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; ++p) {
        if (prime[p]) {
            for (int i = 2 * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    //print
    /* for (int p = 2; p <= n; ++p) {
        (prime[p]) ? cout << p << " " : cout << "";
    }
    cout << endl;
    */
}

vector<int> search(string newString) {
    //cout << newString << endl;
    vector<int> Z(newString.length(), 0);
    int left = 0, right = 0;
    //meaningless for i = 0;
    for (int i = 1; i < newString.length(); ++i) {
        if (i > right) {
            left = right = i;
            while (right < newString.length() && newString[right] == newString[right - left]) {
                right += 1;
            }
            Z[i] = right - left;
            right -= 1;
        } else {
            int k = i - left;
            if (Z[k] < right - i + 1) {
                Z[i] = Z[k];
            } else {
                left = i;
                while (right < newString.length() && newString[right] == newString[right - left]) {
                    right += 1;
                }
                Z[i] = right - left;
                right -= 1;
            }
        }
    }
    return Z;
}

void patternMatching(string text, string pattern) {
    string newString = pattern + "$" + text;
    vector<int> Z = search(newString);
    for (int i = 0; i < Z.size(); ++i) {
        if (Z[i] == pattern.length()) {
            cout << i - pattern.length() - 1 << " ";
        }
        //cout << Z[i] << " ";
    }
    cout << endl;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    patternMatching(text, pattern);
    return 0;
}
