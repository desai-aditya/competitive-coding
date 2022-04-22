class Solution {
public:
    int found;
    vector<int> dx = {-1,0,0,1};
    vector<int> dy = {0,1,-1,0};
    int valid(vector<vector<char>> & board, int x, int y)
    {
        return x>=0 && y>=0 && x<board.size() && y<board[0].size();
    }
    int _helper(vector<vector<char> > & board, vector<vector<int> > & vis, string word, int index, int curx, int cury)
    {
        if(index == word.size())
        {
            found  = true;
            return true;
        }
        for(int i = 0 ; i < 4; i ++)
        {
            int newx = curx+dx[i];
            int newy = cury + dy[i];
            
            if(valid(board,newx,newy) && !vis[newx][newy] && word[index]==board[newx][newy])
            {
                vis[newx][newy]=1;
                if(_helper(board,vis,word,index+1,newx,newy))return true;
                vis[newx][newy]=0;
            }
        }
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        found = 0;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int> > vis(n,vector<int>(m,0));
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < m ; j ++)
            {
                if(word[0]==board[i][j])
                {
                    vis[i][j]=1;
                    if(_helper(board,vis,word,1,i,j))return true;
                    vis[i][j]=0;
                }
            }
        }
        return false;
    }
};