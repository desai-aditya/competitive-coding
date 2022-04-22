class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<int,int> m{};
        
        for(auto el : J)
        {
            m[el]++;
        }
        
        int ans=0;
        for(auto el : S)
        {
            if(m[el])ans++;
        }
        return ans;
    }
};