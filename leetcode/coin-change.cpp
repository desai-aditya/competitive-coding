class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>  dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int j = 0 ; j <= amount; j++)
        {
            for(auto el : coins)
            {
                if(j-el>=0)
                {
                    if(dp[j-el]!=INT_MAX)
                        dp[j] = min(dp[j],dp[j-el]+1);
                }
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};