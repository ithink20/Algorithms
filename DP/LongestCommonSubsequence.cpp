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

int lcs_helper(vector<vector<int> >&dp, string A, string B, int m, int n) {
    //Base Case
    if (m == 0 || n == 0) {
        dp[m][n] = 0;
    }
    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    if (A[m - 1] == B[n - 1]) {
        return dp[m][n] = 1 + lcs_helper(dp, A, B, m - 1, n - 1);
    } else {
        return dp[m][n] = max(lcs_helper(dp, A, B, m - 1, n), lcs_helper(dp, A, B, m, n - 1));
    }
}

int lcs(string A, string B) {
    int m = A.length();
    int n = B.length();
    vector <vector<int> >dp(m + 1, vector<int>(n + 1, -1));
    return lcs_helper(dp, A, B, m, n);
}


int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << lcs(str1, str2) << endl;
    return 0;
}
