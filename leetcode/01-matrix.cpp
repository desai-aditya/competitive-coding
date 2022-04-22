class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue< pair<int,int> > q  = {};
        
        int n = mat.size(),m=mat[0].size();
        if(n==0)return mat;
        vector<vector<int> > dist (n,vector<int>(m,INT_MAX));
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < m ; j ++)
            {
                if(mat[i][j]==0)
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while(!q.empty())
        {
            auto p = q.front(); q.pop();
            
            for(int i = 0 ; i < 4; i++)
            {
                int new_r = p.first + dir[i][0],new_c=p.second+dir[i][1];
                if(new_r>=0&&new_r<n&&new_c>=0&&new_c<m)
                {
                    if(dist[new_r][new_c]>dist[p.first][p.second]+1)
                    {
                        dist[new_r][new_c]=dist[p.first][p.second]+1;
                        q.push({new_r,new_c});
                    }
                }
            }
        }
        return dist;
    }
};