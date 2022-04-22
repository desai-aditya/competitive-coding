class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<int> > sum_matrix(grid.size(),vector<int>(grid[0].size(),0));
        
        sum_matrix[0][0]=grid[0][0];
        for(int i = 1 ; i < grid.size();i++)sum_matrix[i][0]=grid[i][0]+sum_matrix[i-1][0];
        for(int j = 1 ; j < grid[0].size();j++)sum_matrix[0][j]=grid[0][j]+sum_matrix[0][j-1];
        
        for(int i = 1; i < grid.size(); i++)
        {
            for(int j =1; j<grid[0].size();j++)
            {
                
                sum_matrix[i][j]=grid[i][j]+min(sum_matrix[i-1][j],sum_matrix[i][j-1]);
            }
            
        }
        return sum_matrix[grid.size()-1][grid[0].size()-1];
    }
};