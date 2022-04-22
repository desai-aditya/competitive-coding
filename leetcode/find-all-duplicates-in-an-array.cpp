class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> m={};
        vector<int> ans;
        for(auto e : nums)
        {
            m[e]++;
            if(m[e]==2)ans.push_back(e);
        }
        return ans;
    }
};