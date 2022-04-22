class Solution {
public:
    
    unordered_map<string,int> m;
    unordered_map<string,int> m2;
    int ansidx;
    string desensitize(string a)
    {
        string str = "";
        for(auto c : a)
        {
            str += tolower(c);
        }
        return str;
    }
    
    bool isvowel(char c)
    {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    
    void vowelerror(string s, int idx, string t)
    {
        if(idx>= s.size())
        {
            if(m2.find(t)!=m2.end())
            {
                ansidx = min(m2[t],ansidx);   
            }
            //cout<<t<<endl;
            return;
        }
        if(isvowel(s[idx]))
        {
            vector<char> vowels = {'a','e','i','o','u'};
            for(auto c : vowels)
            {                    
                //t.push_back(c);
                vowelerror(s,idx+1,t+c);
                //t.pop_back();
            }
        }
        else
        {
            //t.push_back(s[idx]);
            vowelerror(s,idx+1,t+s[idx]);
            //t.pop_back();
        }
        
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for(int i = 0 ; i < wordlist.size(); i++)
        {
            m[wordlist[i]]=i;
            m2[desensitize(wordlist[i])]=INT_MAX;
            
        }
        
        for(int i = 0 ; i < wordlist.size(); i++)        
        {                    
            //if(m.find(desensitize(wordlist[i]))==m.end())
            //{
                m2[desensitize(wordlist[i])] = min(i,m2[desensitize(wordlist[i])]) ;            
                //cout<<desensitize(wordlist[i])<<endl;
            //}                        
                
        }
        for (auto itr:m2)
        {
            cout<<itr.first<<" "<<itr.second<<endl;
        }
        
        vector<string> ans;
        for(int i = 0 ; i < queries.size() ; i ++)
        {
            if(m.find(queries[i])!=m.end() )
            {
                ans.push_back(wordlist[m[queries[i]]]);
            }
            else if(m2.find(desensitize(queries[i]))!=m2.end() )
            {
                ans.push_back(wordlist[m2[desensitize(queries[i])]]);
            }
            else
            {
                ansidx=INT_MAX;
                vowelerror(desensitize(queries[i]),0,"");
                if(ansidx==INT_MAX)
                {
                    ans.push_back("");
                }
                else
                {
                    ans.push_back(wordlist[ansidx]);
                }
            }
            
        }
        return ans;
        
        
        
    }
};