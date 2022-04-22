class Trienode{
public:
    vector<unique_ptr<Trienode> > children;
    bool has;
    Trienode():has(false),children(26){}
    void add(string & word)
    {
        auto cur = this;
        for(int i = 0 ;i < word.size(); i++)
        {
            if(!cur->children[word[i]-'a'])cur->children[word[i]-'a']=make_unique<Trienode>();
            cur=cur->children[word[i]-'a'].get();
        }
        cur->has = true;
    }
};

class Solution {
public:
    unordered_set<string> ans;
    vector<int> dir = {0,1,0,-1,0};
    void dfs(unique_ptr<Trienode> &trie, vector<vector<char> > & board, string & s, int i, int j )
    {
        int n= board.size(), m= board[0].size();
        if(trie && trie->has)ans.insert(s);
        if(min(i,j)<0 || i>=n || j>=m || !trie || board[i][j]=='$' )return;
        s+=board[i][j];
        board[i][j]='$';
        
        for(int k = 0 ; k < 4; k++)
        {
            dfs(trie->children[s.back()-'a'],board,s,i+dir[k],j+dir[k+1]);
        }
        board[i][j]=s.back();
        s.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unique_ptr<Trienode> trie(new Trienode());
        for(auto &s:words)trie->add(s);
        string s;
        for(int i = 0 ;i  < board.size(); i++)
        {
            for(int j = 0 ; j < board[0].size(); j++)
            {
                dfs(trie,board,s,i,j);
            }
        }
        return {ans.begin(),ans.end()};
    }
};