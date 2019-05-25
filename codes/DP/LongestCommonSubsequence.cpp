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

void printLcs(vector<vector<int> >&dp, string A, string B, int m, int n) {
    int last_index = dp[m][n];
    char matched_string[last_index + 1];  //to store matched string
    matched_string[last_index] = '\0';

    for(int i = m, j = n; i > 0 && j > 0; ) {
        if (A[i - 1] == B[j - 1]) {
            matched_string[last_index - 1] = A[i - 1];
            last_index -= 1;
            i -= 1;
            j -= 1;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i -= 1;
        } else {
            j -= 1;
        }
    }
    cout << matched_string << endl;
}

int lcs(string A, string B) {
    int m = A.length();
    int n = B.length();
    vector <vector<int> >dp(m + 1, vector<int>(n + 1, -1));
    int ans = lcs_helper(dp, A, B, m, n);
    printLcs(dp, A, B, m, n);
    return ans;
}


int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << lcs(str1, str2) << endl;
    return 0;
}
