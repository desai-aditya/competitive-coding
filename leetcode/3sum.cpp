class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int> > v;
        if(nums.size()<3)return {};
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size()-1; i++)
        {
            int l=i+1,r=nums.size()-1;
            while(l<r)
            {
                if(nums[i]+nums[l]+nums[r]==0)
                {
                    v.insert({nums[i],nums[l],nums[r]});
                    l++;r--;
                }
               else if(nums[i]+nums[l]+nums[r]>0)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return {v.begin(),v.end()};
    }
};