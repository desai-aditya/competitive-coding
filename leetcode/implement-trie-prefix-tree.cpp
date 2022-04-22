class TrieNode{
    public:
    bool word;
    TrieNode* children[26];
    TrieNode():word(false)
    {
        memset(children,0,sizeof(children));
    }
};

class Trie {
private:
    TrieNode* root;
    TrieNode* leaf(string prefix)
    {
        TrieNode* node = root;
        for(int i = 0 ;i  <prefix.size()&&node; i++)
        {
            node = node->children[prefix[i]-'a'];
        }
        return node;
    }
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode*  node = root;
        for(int i =0;i<word.size(); i++)
        {
            if(node->children[word[i]-'a']==NULL)
            {
                node->children[word[i]-'a']=new TrieNode();
                
            }
            node = node->children[word[i]-'a'];
        }
        node->word=true;
    }
    
    bool search(string word) {
        TrieNode * node = leaf(word);
        return node!=NULL && node->word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = leaf(prefix);
        return node!=NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */