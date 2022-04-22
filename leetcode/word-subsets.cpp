class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> maxalphs(26,0);
        for(auto s:B)
        {
            unordered_map<char,int> m;
            for(auto c:s)
            {
                m[c]++;
            }
            for(auto el : m)
            {
                maxalphs[el.first-'a'] = max(maxalphs[el.first-'a'] , el.second);                
            }
        }
        vector<string> ans;
        for(auto s:A)
        {
            unordered_map<char,int> m;
            for(auto c:s)
            {
                m[c]++;
            }
            int flag=1;
        
            for(int i = 0 ; i < 26; i++)
            {
                if(maxalphs[i]>m[i+'a'])
                {
                    flag=0;break;
                }       
            }

            if(flag)ans.push_back(s);            
        }
        return ans;
    }
};