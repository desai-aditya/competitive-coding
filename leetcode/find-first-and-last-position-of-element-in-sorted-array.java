class Solution {
    
    private int lowestTarget(int[] nums, int target)
    {
        int l = -1; int r = nums.length;
        // invariant l<r, right r;
        while(l+1<r)
        {
            int mid = (l+r)/2;
            
            if(nums[mid]>=target)
            {
                r=mid;
            }
            else
            {
                l=mid;
            }
        }
        if(r!=nums.length && nums[r]==target)return r;
        return -1;
    }
    
    private int highestTarget(int[] nums, int target)
    {
        int l = -1; int r = nums.length;
        // invariant l<r, right r;
        while(l+1<r)
        {
            int mid = (l+r)/2;
            
            if(nums[mid]>target)
            {
                r=mid;
            }
            else
            {
                l=mid;
            }
        }
        if(l!=-1 && nums[l]==target)return l;
        return -1;
    }
    
    public int[] searchRange(int[] nums, int target) {
        
        //System.out.println(lowestTarget(nums,target));
        int[] ans = new int[2];
        if( nums.length == 0 )
        {
            ans[0]=ans[1]=-1;
            return ans;
        
        }
        int left = lowestTarget(nums,target);
        if(left==-1 )
        {
            ans[0]=ans[1]=-1;
            return ans;
        }
        ans[0]=left;
        int right = highestTarget(nums,target);
        ans[1]=right;
        return ans;
    }
}