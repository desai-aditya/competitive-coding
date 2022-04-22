class Solution {
public:
    int helper(vector<int> & nums, int l, int r)
    {
        if(l==r||l==r-1)
        {
            return min(nums[l],nums[r]);
        }
        int m = (l+r)>>1;
        return min(helper(nums,l,m),helper(nums,m,r));
    }
    int findMin(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};