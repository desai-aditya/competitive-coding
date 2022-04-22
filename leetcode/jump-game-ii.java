class Solution {
    public int jump(int[] nums) {
        if(nums.length<=1)return 0;
        int[] newnums = new int[nums.length];
        Arrays.fill(newnums,1000000);
        newnums[0]=0;
        for(int i = 0 ; i < nums.length; i++)
        {
            
                for(int j = i; j <= nums[i]+i && j < nums.length; j++ )
                {
                    newnums[j] = Math.min(newnums[i] + 1,newnums[j]);
                }                
        }
        return newnums[nums.length-1];
    }
}