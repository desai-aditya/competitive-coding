class Solution {

    private:
    int m_num_islands=0;
    int m_dx[4]={0,0,1,-1};
    int m_dy[4]={1,-1,0,0};
    
    bool check(int curx,int cury, int gridx,int gridy)
    {
        return curx>=0&&cury>=0&&curx<gridx&&cury<gridy;
    }
    
    void _dfs(vector<vector<char> >& grid, vector<vector<bool> >& vis, int curx, int cury)
    {
        if(!vis[curx][cury])
        {
            vis[curx][cury]=1;
            for(int s = 0 ; s<4;s++)
            {
                if(check(curx+m_dx[s],cury+m_dy[s],grid.size(),grid[0].size()) && grid[curx+m_dx[s]][cury+m_dy[s]]=='1' )
                    _dfs(grid,vis,curx+m_dx[s],cury+m_dy[s]);
            }
            
            
        }
    }
        
    void print_is(vector<vector<bool> > & vis)
    {
        for(int i = 0 ; i < vis.size(); i++)
        {
            for(int j = 0 ; j < vis[0].size(); j++)
            {
                cout<< vis[i][j]?1:0;
            }
            cout<<endl;
        }
    cout<<endl;    
    }
    
    
    public:
    int numIslands(vector<vector<char>>& grid) {
        std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0);
        if(grid.size()==0)return 0;
        if(grid[0].size()==0)return 0;
        m_num_islands=0;
        vector< vector<bool> > vis(grid.size(), vector<bool>(grid[0].size(),0));
        for(int i = 0 ;i  < grid.size(); i++)
        {
            for(int j  =0 ; j < grid[0].size(); j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    _dfs(grid,vis,i,j);        
                    m_num_islands++;
                    //print_is(vis);
                }
                    
                
            }
            
        }
        
        return m_num_islands;
    }
};