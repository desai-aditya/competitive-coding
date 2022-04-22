class Solution {
public:
    
    bool helper(int node, vector<int> & color,vector<int> &vis ,vector<vector<int>>& graph)
    {
        int mycolor = color[node];
        int newcolor = (mycolor==1)?2:1;
        
        for(int i  = 0 ;i  < graph[node].size(); i++)
        {
            if(graph[node][i]!=node&&color[graph[node][i]]==mycolor&&vis[graph[node][i]])
            {
                return false;
            }
            
            if(graph[node][i]!=node&&!vis[graph[node][i]])
            {
                vis[graph[node][i]]=1;
                color[graph[node][i]]=newcolor;
                if(!helper(graph[node][i],color,vis,graph))return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size()<=2)return true;
        vector<int> color(graph.size(),0);
        vector<int > vis(graph.size(),0);
        for(int i  = 0 ; i < graph.size();i++)
        {
            if(!vis[i])
            {
                color[i]=1;
                vis[i]=1;
                if(!helper(i,color,vis,graph))return false;
            }
        }
        return true;
        
    }
};