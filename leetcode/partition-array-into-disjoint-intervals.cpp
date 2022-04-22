class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        if(nums.size()==1)return 1;
        vector<int> mins = {};
        vector<int> maxs = {};
        
        int maxel = nums[0];
        for(int i = 0 ; i < nums.size() ; i++)
        {
            maxel = max(maxel,nums[i]);
            maxs.push_back(maxel);
        }
        
        int minel = nums[nums.size()-1];
        for(int i = nums.size()-1 ; i >=0 ; i--)
        {
            minel = min(minel,nums[i]);
            mins.push_back(minel);
        }
        reverse(mins.begin(),mins.end());
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(maxs[i]<=mins[i+1])return i+1;
        }
        return nums.size();
            
    }
};