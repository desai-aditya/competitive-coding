class NumMatrix {
    int[][] precomputed;
    public NumMatrix(int[][] matrix) {
        int n  = matrix.length;
        int m  = matrix[0].length;
        
        precomputed = new int[n][m];
        precomputed[0][0] = matrix[0][0];
        
        for(int i  = 1 ;i < n ; i ++)
        {
            precomputed[i][0]  = matrix[i][0] + precomputed[i-1][0];
        }
        for(int j  = 1 ;j < m; j ++)
        {
            precomputed[0][j]  = matrix[0][j] + precomputed[0][j-1];
        }
        
        for(int i = 1; i < n;  i++)
        {
            for(int j = 1; j < m ; j ++)
            {
                precomputed[i][j] = precomputed[i][j-1] + precomputed[i-1][j] + matrix[i][j] - precomputed[i-1][j-1];
            }
        }
        
        
        
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = precomputed[ row2 ][col2];
        if(col1-1>=0)
        {
            ans -= precomputed[row2][Math.max(0,col1-1)];
        }
        if(row1-1>=0)
        {
            ans -= precomputed[Math.max(row1-1,0)][col2];
        }
        if(col1-1>=0 && row1-1>=0)
        {
            ans +=  precomputed[Math.max(row1-1,0)][Math.max(0,col1-1)];
        }
        return   ans;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */