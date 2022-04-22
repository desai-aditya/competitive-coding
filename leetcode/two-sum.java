class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> m = new HashMap<Integer,Integer>();
        for(int i = 0 ; i < nums.length; i++)
        {
            if(m.get(target-nums[i])!=null)
            {
                int[] ans = new int[2];
                ans[0]=i;
                ans[1]=m.get(target-nums[i]);
                return ans;
            }
            m.put(nums[i],i);
        }
        return new int[2];
    }
    
}