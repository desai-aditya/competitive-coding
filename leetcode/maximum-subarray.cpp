class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxsum=INT_MIN;
        int maxel = INT_MIN;
        int consecutive_sum=0;
        
        for(int i = 0; i < nums.size();i++)
        {
            consecutive_sum+=nums[i];
            consecutive_sum=max(consecutive_sum,0);
            maxsum=max(maxsum,consecutive_sum);
            maxel=max(maxel,nums[i]);
        }
        if(maxsum==0)
            return maxel;
        return maxsum;
        
    }
};