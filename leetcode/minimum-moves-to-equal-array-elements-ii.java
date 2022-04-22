class Solution {
    public int minMoves2(int[] nums) {
        if(nums.length==0)return 0;
        Arrays.sort(nums);
        int average = 0;
        if(nums.length%2==1)
        {
            average = nums[nums.length/2];
        }
        else
        {
            average = (nums[nums.length/2] + nums[(nums.length-1)/2])/2;
        }
        // for(int i = 0 ; i < nums.length; i++)
        // {
        //     average+=nums[i];            
        // }
        // average/=nums.length;
        int ans = 0;
        for(int i = 0 ; i < nums.length; i++)
        {
            ans += Math.abs(average - nums[i]);
        }
        return ans;
    }
}