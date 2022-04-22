class Solution {
public:
    int ans=INT_MAX;
    void bfs(vector<vector<int>>& routes,unordered_map<int, vector<int> > & m, vector<int> &vis, int source, int target )
    {
        if(source==target)
        {
            ans=0;
            return;
        }
        
        queue< pair<int,int> > q;
        vector<int> routeslist = m[source];
        
        for(int i = 0 ; i < routeslist.size(); i++)
        {
            vis[routeslist[i]]=1;
            q.push({routeslist[i],1});    
            
        }        
        
        while(!q.empty())
        {
            pair<int,int> qf = q.front();q.pop();
            
            //if(!vis[qf.first])
            //{
                for(int i = 0 ; i < routes[qf.first].size(); i++)
                {
                    if(target==routes[qf.first][i])
                    {
                        ans=qf.second;
                        return;
                    }
                    
                    routeslist = m[routes[qf.first][i]];
                    for(int i = 0 ; i < routeslist.size(); i++)
                    {
                        if(!vis[routeslist[i]])
                        {
                            vis[routeslist[i]]=1;
                            q.push({routeslist[i],qf.second+1});        
                        }
                        
                    }     
                    
                }
            //}
            
            
        }
        
        
        
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int, vector<int> > m;
        vector<int> vis(routes.size(),0);
        
        for(int i = 0 ;i  < routes.size();  i ++)
        {
            for(int j = 0 ; j < routes[i].size() ; j++)
            {
                m[routes[i][j]].push_back(i);
            }
        }
        ans=INT_MAX;
        bfs(routes,m,vis,source,target);
        return ans==INT_MAX?-1:ans;
    }
};