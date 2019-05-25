//given, triangle like input, find the minimum path sum from top to bottom.


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int>dp(triangle.size() + 1);
        for(int i = triangle.size() - 1; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        return dp[0];
    }
};
