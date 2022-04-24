class Solution {
public:
    int ans;
    int counter;
    int n,m;
    vector<int> d={0,1,0,-1,0};
    int valid(int x, int y)
    {
        return x>=0&&y>=0&&x<n&&y<m;
    }
    void dfs(vector<vector<int>> & grid,int x, int y)
    {
        for(int i = 0 ; i < 4; i++)
        {
            int newx = x+d[i];
            int newy = y+d[i+1];
            
            if(valid(newx,newy)&&grid[newx][newy]==1)
            {
                grid[newx][newy]=2;
                counter++;
                dfs(grid,newx,newy);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        counter=0;
        ans=0;
        n=grid.size();
        m=grid[0].size();
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ;  j < m ; j ++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]=2;
                    counter++;
                    dfs(grid,i,j);
                    ans=max(ans,counter);
                    counter=0;
                }
            }
        }
        return ans;
    }
};