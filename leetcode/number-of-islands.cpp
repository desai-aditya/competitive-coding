class Solution {
public:
    int ans,n,m;
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    int valid(int newx, int newy)
    {
        return newx>=0 && newy>=0 && newx<n && newy<m;
    }
    void dfs(vector<vector<char>>& grid,int x, int y)
    {
        for(int i = 0 ; i < 4; i ++)
        {
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(valid(newx,newy)&&grid[newx][newy]=='1')
            {
                grid[newx][newy]=2;
                dfs(grid,newx,newy);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        ans=0;
        n=grid.size();
        m= grid[0].size();
        
        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < m ; j ++)
            {
        
                if(grid[i][j]=='1')
                {
                    ans++;
                    grid[i][j]=2;
                    dfs(grid,i,j);
                }
                
            }
        }
        return ans;
    }
};