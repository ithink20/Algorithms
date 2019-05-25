#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>


using namespace std;

typedef long long int lint;

int ways(int N, int k, vector<int> &dp) {
    if (N == 0) {
        return 1;
    }
    if (N < 0) {
        return 0;
    }
    if (dp[N] != 0) {
        return dp[N];
    }
    for (int i = 1; i <= k; ++i) {
        dp[N] += ways(N - i, k, dp);
    }    
    return dp[N];
}

int main() {
    int steps, jumps;
    cin >> steps >> jumps;
    vector<int> dp(steps + 1, 0);
    cout << ways(steps, jumps, dp) << endl;
    return 0;
}
