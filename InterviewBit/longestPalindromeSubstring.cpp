//https://articles.leetcode.com/longest-palindromic-substring-part-ii/


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

string ConvertString(string str) {
    if (str.length() == 0) {
        return "&$";
    }
    string converted = "&";
    for (int i = 0; i < str.length(); ++i) {
        converted += "#" + str.substr(i, 1);
    }
    converted += "#$";
    return converted;
}

void getLongestPalSubstring(string str) {
    string T = ConvertString(str);
    int N = T.length();
    vector <int> P(N, 0);
    int C = 0, R = 0;   // R: left Boundary at center around C

    // c : center of palindromic substring
    //c - i = i' - c ==> i' = 2 * c - i
    for (int i = 1; i < N - 1; ++i) {
        int i_dash = 2 * C - i;         // i_dash is mirror of i
        if (R - i > 0) {
            P[i] = min(R - i, P[i_dash]);
        } else {
            P[i] = 0;
        }
        //expand around center i
        while (T[i - 1 - P[i]] == T[i + 1 + P[i]]) {
            P[i] += 1;
        }

        //L1 = i' - P[i']
        //Two cases: L1 >= L and L1 < L
        //      case1 : if (L1 >= L) then P[i] <== p[i'] (mirrored)
        //      case2 : if (L1 < L) then can be expanded further.
        //                here, (i' - P[i'] >= L)
        //                      P[i'] <= i' - L  and i' - L = R - i    (see by drawing)
        //                      P[i'] <= R - i
        if (P[i_dash] > R - i) {        //update
            C = i;
            R = i + P[i];
        }
    }
    int len = 0;
    int centerIndex = 0;
    for (int i = 1; i < N - 1; ++i) {
        if (P[i] > len) {
            len = P[i];
            centerIndex = i;
        }
    }
    cout << str.substr((centerIndex - 1 - len) / 2, len) << endl;
}

int main() {
    string str;
    cin >> str;
    getLongestPalSubstring(str);
    return 0;
}
