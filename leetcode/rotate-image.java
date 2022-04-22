class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int varn = n;
        for(int i = 0 ; i < n; i++)
        {
            for(int j = i; j< varn-1; j++)
            {
                for(int k = 0 ;k < 3; k ++)
                {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][n-1-i];
                matrix[j][n-i-1] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = temp;
                }
            }
            varn--;
        }
        
    }
}