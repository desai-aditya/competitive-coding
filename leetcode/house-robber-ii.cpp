class Solution {
public:
    int solve(vector<int>& nums,int s, int e, int n)
    {
        vector<int> dp(n,-1);
        vector<int> firsttaken(n,0);
        if(n==1)return nums[s];
        if(n==2)return max(nums[s],nums[1+s]);
        //if(n==3)return max(max(nums[0],nums[1]),nums[2]);
        
        dp[0]=nums[0+s];
        firsttaken[0]=1;
        
        if(nums[0+s]>nums[1+s])
        {
            firsttaken[1+s]=1;
            dp[1]=nums[0+s];
        }
        else
        {
            dp[1]=nums[1+s];
        }
        
        
        
        for(int i = 2+s; i < e; i ++)
        {
            if(i==e-1)
            {
                if(nums[i]+dp[i-2-s]>dp[i-1-s] && firsttaken[i-2-s]==0)
                {
                    dp[i-s]=nums[i]+dp[i-2-s];
                    firsttaken[i-s]=firsttaken[i-2-s];
                }
                else //if(nums[i]+dp[i-2]>dp[i-1] && firsttaken[i-2]==1)
                {
                    dp[i-s]=dp[i-1-s];
                    firsttaken[i-s]=firsttaken[i-1-s];
                }
                
            }
            else
            {
                if(nums[i]+dp[i-2-s]>dp[i-1-s])
                {
                    dp[i-s]=nums[i]+dp[i-2-s];
                    firsttaken[i-s]=firsttaken[i-2-s];
                }
                else
                {
                    dp[i-s]=dp[i-1-s];
                    firsttaken[i-s]=firsttaken[i-1-s];
                }
            }
        }
        return dp[n-1-s];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(nums[0]);
        
        int ans=max(solve(nums,0,n,n),solve(nums,1,n+1,n));
        
        return ans;
    }
};