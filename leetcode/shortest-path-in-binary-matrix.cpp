class Solution {
public:
    
    bool valid(int nx, int ny, vector<vector<int> > &grid, vector<vector<int> > &vis)
        {
        return (nx>= 0)&&(ny>=0)&&(nx<grid.size())&&(ny<grid[0].size())&&(grid[nx][ny]==0)&&(!vis[nx][ny]);
       }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0]==1||grid[grid.size()-1][grid[0].size()-1]==1)return -1;
        
        vector<vector<int> > vis(grid.size(), vector<int>(grid[0].size(),0));
        
        queue< pair<pair<int,int>,int> > q;
        
        q.push({{0,0},1});
        vis[0][0]=1;
        int dx[8]={1,1,0,-1,-1,-1,0,1};
        int dy[8]={0,-1,-1,-1,0,1,1,1};
        
        while(!q.empty())
            {
                pair<pair<int,int>,int> t = q.front(); q.pop();
            
            if(t.first.first==grid.size()-1 && t.first.second== grid[0].size()-1)
                return t.second;
            
            //vis[t.first.first][t.first.second]=1;
            
            for(int i=0;i<8;i++)
                {
                     int nx= t.first.first +dx[i]; int ny= t.first.second + dy[i];
                if(valid(nx,ny,grid,vis)){
                    q.push({{nx,ny},t.second+1});
                    vis[nx][ny]=1;
                    }
                }
             
            
            }
        return -1;

    }
};