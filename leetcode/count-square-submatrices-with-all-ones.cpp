class Solution {
public:
    int dp[301][301]={0};
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        long long int sum = 0;
        for(int i = 0 ; i  < n ; i++ )
        {
            dp[i][0] = matrix[i][0];
            sum+=dp[i][0];
            
        }
        
        for(int j = 0 ; j < m; j++)
        {
            dp[0][j] = matrix[0][j];
            sum+=dp[0][j];
        }
        
        for(int i = 1 ;i < n; i++)
        {
            for(int j = 1 ; j < m; j++)
            {
                if(matrix[i][j])
                    dp[i][j] = (1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j])));
                else
                    dp[i][j] = 0;
                sum+=dp[i][j];
               //cout<<dp[i][j];
            }
            //cout<<endl;
        }
        sum-=dp[0][0];
        return sum;
        
        
    }
};