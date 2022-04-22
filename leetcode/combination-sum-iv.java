class Solution {
    
    
    
    public int combinationSum4(int[] nums, int target) {
        int n = nums.length;
        int[] dp = new int[target+1];
        
        Arrays.fill(dp,0);
        dp[0]=1;
        
        for(int j = 1; j <= target; j++)
        {
            for(int i = 0 ; i < n ;  i ++)
            {
                if(j - nums[i]>=0)
                {
                    dp[j]+=dp[j-nums[i]];
                }
            }
        }
        
        
        return dp[target];
        
    }
}