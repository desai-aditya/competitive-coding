class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        int [][] dp = new int[n][m];
        for(int i = 0 ;i < n;  i++)
        {
            for(int j = 0 ; j < m ; j ++)
            {
                dp[i][j]=0;
            }
        }
        
        dp[0][0]=matrix[0][0];
        
        for(int i = 1 ;i < n ; i ++)dp[i][0]+=dp[i-1][0]+matrix[i][0];
        for(int j = 1 ;j < m ; j ++)dp[0][j]+=dp[0][j-1]+matrix[0][j];
        
        for(int i = 1 ;i < n;  i++)
        {
            for(int j = 1 ; j < m ; j ++)
            {
                dp[i][j] = matrix[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        
        int count = 0;
        
        for(int i = 0 ;i < n;  i++)
        {
            for(int j = 0 ; j < m ; j ++)
            {
                for(int k = i ;k < n;  k++)
                {
                    for(int l = j ; l < m ; l ++)
                    {
                        int temp = 0;
                        if(i>0)                        
                            temp -= dp[i-1][l];
                                                
                        if(j>0)
                            temp -= dp[k][j-1];
                        
                        if(i>0 && j >0)
                            temp += dp[i-1][j-1];
                        
                        temp += dp[k][l];
                        
                        if(temp == target )
                        {
                            
                            count++;
                        }
                        
                    }
                }
            }
        }
        return count;
        
        
    }
}