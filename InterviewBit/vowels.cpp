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
const int MOD = 1e9 + 7;
typedef long long int lint;


int getsolution(int N) {
    lint dp[2][5];

    // init: dp[k][i] : string with vowels of length k using i(set of vowels);
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 5; ++i) {
            dp[j][i] = j;
        }
    }
    for (int i = 2; i <= N; ++i) {
        int k = i & 1;      //always returns 0 or 1, whether odd/even
                            // x ^ 1        flips x: if x = 1, flip it to 0 and vice-versa

        //from the table observation:
        // L        a  |  e  |  i  |  o  |  u  |
        // 1        1  |  1  |  1  |  1  |  1  |
        // 2        2  |  1  |  4  |  2  |  2  |
        // 3        5  |  4  |  7  |  4  |  3  |

        //Obvervation:
        //     a = (e + i) of N - 1
        //     e = (i) of N - 1
        //     i = (a + e + o + u) of N - 1
        //     o = (a + u) of N - 1
        //     u = (e + o) of N - 1

        dp[k][0] = (dp[k ^ 1][1] + dp[k ^ 1][2]) % MOD;
        dp[k][1] = (dp[k ^ 1][2]) % MOD;
        dp[k][2] = (dp[k ^ 1][0] + dp[k ^ 1][1] + dp[k ^ 1][3] + dp[k ^ 1][4]) % MOD;
        dp[k][3] = (dp[k ^ 1][0] + dp[k ^ 1][4]) % MOD;
        dp[k][4] = (dp[k ^ 1][1] + dp[k ^ 1][3]) % MOD;
    }
    lint ans = 0;
    for (int i = 0; i < 5; ++i) {
        ans = (ans + dp[N & 1][i]) % MOD;
    }
    return (int)ans % MOD;
}

int main() {
    int N;
    cin >> N;
    cout << getsolution(N) << endl;
    return 0;
}
