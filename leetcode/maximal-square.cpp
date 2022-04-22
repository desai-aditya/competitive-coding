class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        
        
        if(n==0 )return 0;
        int m=matrix[0].size();
        if(m==0)return 0;
            
        vector< vector< int> > dp(n,vector<int>(m,0));
        int maxel=dp[0][0];
        for(int i = 0 ; i  < n; i++)
        {
            dp[i][0]= matrix[i][0]=='1'?1:0;
             maxel=max(maxel,dp[i][0]);
        }
        for(int j = 0 ; j  < m; j++)
        {
            dp[0][j]= matrix[0][j]=='1'?1:0;
             maxel=max(maxel,dp[0][j]);
        }
        
        for(int i =  1 ; i < n ; i++)
        {
            
            for(int j = 1 ; j  <m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    dp[i][j] = min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
                }
                else
                {
                    dp[i][j]=0;
                }
                maxel=max(maxel,dp[i][j]);
            }
        }
        return maxel*maxel;
    }
};