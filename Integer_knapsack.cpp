/*
    input : n number of items each with weight wi and value vi
            and given a knapsack of capacity C
    goal : pack items into knapsack, maximize its value
            its ok to use multiple instances of items.
    Here M(j) : maximum value one can pack into a knapsack of j.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int M(const vector<pair<int, int> > &A, vector<int> &dp, vector<int> &bt, int j, int N) {

    if (j <= 0) {
        return 0;
    }
    if (dp[j] != -1) {
        return dp[j];
    }
    int ans = M(A, dp, bt, j - 1, N);
    int ans_last_index = bt[j - 1];
    for (int i = 1; i <= N; ++i) {
        if (j >= A[i].first) {
            debug_print3(j, A[i].first, A[i].second);
            int val = M(A, dp, bt, j - A[i].first, N) + A[i].second;
            if (val > ans) {
                ans = val;
                ans_last_index = i;
            }
        }
    }
    dp[j] = ans;
    bt[j] = ans_last_index;
    debug_print3(j, ans, ans_last_index);
    return ans;
}

int main() {
    int N, C;
    cin >> N >> C;
    vector<pair<int, int> > A(N + 1);
    vector<int> dp(C + 1, -1);
    vector<int> backtrack_last_item_index(C + 1, -1);
    int w, v;
    for (int i = 1; i <= N; ++i) {
        cin >> w >> v;
        A[i].first = w;
        A[i].second = v;
    }
    cout << M(A, dp, backtrack_last_item_index, C, N) << endl;
    int index = backtrack_last_item_index[C];
    int capacity_left = C;
    while (index >= 1) {
        cout << "(" << A[index].first << " , " << A[index].second << ") + ";
        capacity_left -= A[index].first;
        index = backtrack_last_item_index[capacity_left];
    }
    return 0;
}