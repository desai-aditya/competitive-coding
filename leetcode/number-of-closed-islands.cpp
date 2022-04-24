class Solution {
public:
    int n,m;
    int ans;
    vector<int> d={0,1,0,-1,0};
    int valid(int x, int y)
    {
        return x>=0&&y>=0&&x<n&&y<m;
    }
    void dfs(vector<vector<int>>& grid, int x, int y) {
        for(int i = 0 ; i < 4; i++)
        {
            int nx = x+d[i];
            int ny = y+d[i+1];
            
            if(valid(nx,ny)&&grid[nx][ny]==0)
            {
                grid[nx][ny]=2;
                dfs(grid,nx,ny);
            }
        }
    }
    void floodfill(vector<vector<int>>& grid) {
        
        for(int i = 0 ;i < n;i++)
        {
            if(grid[i][0]==0)
            {
                  grid[i][0]=2;
                  dfs(grid,i,0);
                
            }
            
            
            if(grid[i][m-1]==0)
            {
                                  grid[i][m-1]=2;
                dfs(grid,i,m-1);

            }
        }
        
        for(int j = 0 ;j < m;j++)
        {
            if(grid[0][j]==0)
            {
                                  grid[0][j]=2;

                  dfs(grid,0,j);
                
            }
            
            
            if(grid[n-1][j]==0)
            {
                grid[n-1][j]=2;
                dfs(grid,n-1,j);
                
            }
        }
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        ans=0;
        n=grid.size();
        m=grid[0].size();
        floodfill(grid);
        
        for(int i= 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j  <m ; j++)
            {
                if(grid[i][j]==0)
                {
                    grid[i][j]=2;
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};