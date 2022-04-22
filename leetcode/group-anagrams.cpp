class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> > m;
        for(auto s : strs)
        {
            string t=s;
            sort(t.begin(),t.end());
            m[t].push_back(s);
        }
        vector<vector<string> > ans{};
        for(auto itr=m.begin(); itr!=m.end();itr++)
        {
            ans.push_back(itr->second);
        }
        return ans;
    }
};