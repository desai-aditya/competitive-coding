class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()<=1)return 0;
        if(nums.size()==2 && nums[1]<nums[0])return 2;
        if(nums.size()==2 && nums[1]>nums[0])return 0;
       
        int minel =INT_MAX; 
        int maxel = INT_MIN;
        
        int l = 0; int r = nums.size()-1;
        int st = 1, end = 0;
        
        while(r>=0)
        {
            if(nums[l]>=maxel)
            {
                maxel=nums[l];
            }
            else
            {
                end = l;
            }
            
            if(nums[r]<=minel)
            {
                minel=nums[r];
            }
            else
            {
                st = r;
            }
            
            l++;
            r--;
        }
        
        return end-st+1;
    }
};