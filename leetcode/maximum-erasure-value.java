class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int l=0,r=0,sum=0,ans=0;
        HashMap<Integer,Integer> m = new HashMap<Integer,Integer>();
        while(r<nums.length && l<nums.length)
        {
            if(m.get(nums[r])==null || m.get(nums[r])==0)
            {
                sum+=nums[r];
                m.put(nums[r],1);
                r++;
            }
            else
            {
                sum-=nums[l];
                m.put(nums[l],0);
                l++;
            }
            ans = Math.max(sum,ans);
        }
        return ans;
    }
}