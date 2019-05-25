/*      
        @author: vikaschaurasiya
 */



#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <vector>
#include <set>
#include <climits>
#include <map>
#include <string>

using namespace std;

typedef long long int lint;

int coinChange(vector <int>&dp, vector <int> &coins, int amount) {
	dp[0] = 0;
	for (int i = 1; i <= amount; ++i) {
		for (int j = 0; j < coins.size(); ++j) {
			if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
				if (dp[i] > 0) {
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				} else {
					dp[i] = dp[i - coins[j]] + 1;
				}
			}
		}
	}
	return dp[amount];
}

int main() {
	int N;
	cin >> N;
	vector <int> coins(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> coins[i];
	}
	sort(coins.begin(), coins.end());
	int amount;
	cin >> amount;
	vector <int> dp(amount + 1, -1);
	cout << coinChange(dp, coins, amount) << endl;
	return 0;
}
