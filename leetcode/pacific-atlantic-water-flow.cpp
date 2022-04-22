        

class Solution {
public:
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    
    bool isvalid(int oldx, int oldy, int newx, int newy,vector<vector<int> > & matrix,vector<vector<int> > & vis)
    {
        return newx>=0 && newx<matrix.size() && newy>=0 && newy<matrix[0].size() && matrix[newx][newy]>=matrix[oldx][oldy] && !vis[newx][newy];
    }
    void dfs(int oldx,int oldy, vector<vector<int> > & vis, vector<vector<int> > & matrix)
    {
        
        for(int i = 0; i < 4; i++)
        {
            int newx = oldx+dx[i];
            int newy = oldy+dy[i];
            if(isvalid(oldx,oldy,newx,newy,matrix,vis))
            {
                vis[newx][newy]=1;
                dfs(newx,newy,vis,matrix);
            }
        }
    }
    
    vector<vector<int> > vis1,vis2;
    void printm(vector<vector<int> > & vis)
    {
        int n= vis.size();
        int m=vis[0].size();
        for(int i = 0 ; i < n ; i ++)
        {
            for(int  j = 0 ; j  < m ; j++)
            {                
                cout<<vis[i][j]<<" ";                
            }
            cout<<endl;
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size()<=0 || matrix[0].size()<=0)return {};
        int n=matrix.size();
        int m=matrix[0].size();
        
        vis1 = vector<vector<int> >(n,vector<int>(m,0 ) );
        vis2 = vector<vector<int> >(n,vector<int>(m,0 ) );
        vector<vector<int> > ans;
        for(int i = 0; i < n; i++)
        {
            if(!vis1[i][0])
            {
                vis1[i][0]=1;
                dfs(i,0,vis1,matrix);                
            }
                
            if(!vis2[i][m-1])
            {
                vis2[i][m-1]=1;
                dfs(i,m-1,vis2,matrix);            
            }
                
        }
        
        for(int j = 0; j < m; j++)
        {
            if(!vis1[0][j])
            {
                vis1[0][j]=1;                
                dfs(0,j,vis1,matrix);               
            }
 
            if(!vis2[n-1][j])
            {
                vis2[n-1][j]=1;                
                dfs(n-1,j,vis2,matrix);            
            }
                
        }
        
        for(int i = 0 ; i < n ; i ++)
        {
            for(int  j = 0 ; j  < m ; j++)
            {
                
                if(vis1[i][j] && vis2[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        //printm(vis1);cout<<endl;printm(vis2);
        
        return ans;
        
    }
};