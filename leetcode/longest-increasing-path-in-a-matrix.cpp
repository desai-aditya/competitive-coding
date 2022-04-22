class Solution {
public:
    int ans = 0;
    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {-1,1,0,0};
    vector<vector<int>> matrix;
    vector<vector<int>> vis;
    vector<vector<int>> dp;
    bool isvalid(int curx,int cury,int newx,int newy)
    {
        return (newx>=0 && newy >=0 && newx < matrix.size() && newy < matrix[0].size() && matrix[newx][newy]>matrix[curx][cury]);
    }
    
    int recurse(int curx, int cury, int length)
    {
        if(dp[curx][cury]!=-1)return dp[curx][cury];
        int retlen=0;
        for(int k = 0 ; k < 4; k++)
        {
            int newx = curx+dx[k];
            int newy = cury+dy[k];
            
            if(isvalid(curx,cury,newx,newy) )//&&  !vis[newx][newy])
            {
                //vis[newx][newy]=1;
                retlen = max(retlen,recurse(newx,newy,length+1));
                //vis[newx][newy]=0;
            }
            
        }
        dp[curx][cury]=retlen+1;
        ans=max(ans,dp[curx][cury]);
        return dp[curx][cury];
    }
    
    int longestIncreasingPath(vector<vector<int>>& ma) {
        matrix=ma;
        int n = matrix.size();
        int m = matrix[0].size();
        vis = vector<vector<int>>(n,vector<int>(m,0));
        dp = vector<vector<int>>(n,vector<int>(m,-1));
        
        for( int i = 0 ;i < n ; i ++)
        {
            for( int j = 0 ; j < m ; j ++)
            {
                //vis[i][j]=1;
                dp[i][j] = recurse(i,j,1);
                //vis[i][j]=0;
            }
        }
        return ans;
    }
};