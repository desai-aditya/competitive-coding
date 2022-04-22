class Solution {
public:
    static bool compfun(string &a, string &b){return a.size()>b.size();}
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),compfun);
        unordered_set<string> s;
        int len = 0;
        for(int i = 0; i < words.size() ; i ++)
        {
            string t = words[i];
            reverse(t.begin(),t.end());
            int f = 1;
            string ts = "";
            
            if(s.find(t)!=s.end())
            {
                continue;
            }                    
            
            for(int j = 0 ; j < t.size(); j++)
            {
                ts+=t[j];                
                s.insert(ts);
            }
            len+=t.size()+1;                                   
        }
        return len;
        
    }
};