class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue< pair<pair<int,int>,int> >  q;
        int n = grid.size();int m = grid[0].size();
        int fresh=0;
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < m ; j ++)
            {
                if(grid[i][j]==2)q.push({{i,j},0});
                if(grid[i][j]==1)fresh++;
            }
        }
        vector<int> d = {0,1,0,-1,0};
        int mint=0;
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            mint=max(mint,t.second);
            for(int k = 0 ;k < 4; k++)
            {
                int newx = t.first.first+d[k];
                int newy=t.first.second+d[k+1];
                
                if(newx<0||newy<0||newx>=n||newy>=m||grid[newx][newy]==0||grid[newx][newy]==2)continue;
                
                fresh--;
                grid[newx][newy]=2;
                q.push({{newx,newy},t.second+1});
            }
            
        }
        return fresh==0?mint:-1;
    }
};