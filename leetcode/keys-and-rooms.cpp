class Solution {
public:
    void helper(vector<vector<int> >& rooms, vector<int> & vis, int cur )
    {
        
        for( int i = 0 ; i < rooms[cur].size() ; i++ )
        {
            if(!vis[rooms[cur][i]])
            {
                vis[rooms[cur][i]]=1;
                helper(rooms, vis, rooms[cur][i]);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector< int > vis(rooms.size(),0);
        vis[0]=1;
        helper(rooms,vis,0);
        
        return !any_of( vis.begin() , vis.end() , [](int i){return i<=0;} );
    }
};