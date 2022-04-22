class Solution {
public:
    
    int numprovinces = 0;
    vector<int> vis;
    int flag = 1;
    void dfs(int cur, vector<vector<int>>& isConnected)
    {
        if(vis[cur]==1)return;
        vis[cur]=1;
        if(flag==1){numprovinces++; flag=0;}
        for(int j = 0 ; j < isConnected.size(); j++)
        {
            if(cur!=j && isConnected[cur][j]==1)
            {
                dfs(j,isConnected);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vis = vector<int>(isConnected.size(),0);
        for(int i = 0 ; i < isConnected.size(); i++)
        {
            flag=1;
            dfs(i,isConnected);
            
        }
        return numprovinces;
    }
};