class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        map<int,vector<int> > f;
        for(char c : s)
            m[c]++;
        
        for(auto itr = m.begin(); itr!=m.end(); itr++)
        {
            f[itr->second].push_back(itr->first);
        }
        string ans;
        for(auto itr = f.rbegin(); itr!=f.rend(); itr++)
        {
            for(int j = 0 ;j < itr->second.size(); j++)
            {
                 for(int i = 0 ; i < itr->first; i++)
                {
                    ans+=itr->second[j];
                }
            }
        }
        return ans;
    }
};