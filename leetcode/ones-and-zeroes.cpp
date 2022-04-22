class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector< vector<int> > dp(n+1, vector<int>(m+1,0));
        
        int maxel = -1;
        for(int k = 0 ; k < strs.size() ; k++)
        {
            int zeros = count(strs[k].begin(),strs[k].end(),'0');
            int  ones = strs[k].size()-zeros;

            for(int i  = n ; i >= ones; i--)
            {
                for(int j = m ; j >= zeros ; j--)
                {
                    dp[i][j] = max(dp[i][j],dp[i-ones][j-zeros]+1);
                }
            }

        }
       return dp[n][m];
    }
};