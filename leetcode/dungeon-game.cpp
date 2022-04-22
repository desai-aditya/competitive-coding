class Solution {
public:
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
       int m = dungeon.size(), n = dungeon[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN));

        dp[m - 1][n - 1] = dungeon[m - 1][n - 1];
        if (dp[m - 1][n - 1] > 0)dp[m - 1][n - 1] = 0;

         for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)continue;
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]) + dungeon[i][j];
                if (dp[i][j] > 0)dp[i][j] = 0;
            }
        }

        return (dp[0][0] * -1) + 1;
    }
};