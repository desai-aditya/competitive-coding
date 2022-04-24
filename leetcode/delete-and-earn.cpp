class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0 ; i < nums.size(); i++)
        {
            m[nums[i]]+=nums[i];
        }
        vector<int> dp (m.size(),-1);
        vector<int> keys(m.size());int i = 0;
        
        for(auto itr = m.begin(); itr!=m.end(); itr++)
        {
            keys[i]=itr->first;
            i++;
        }
        
        dp[0]=m[keys[0]];
                if(m.size()==1)return dp[0];

        //dp[1]=max(m[keys[0]],m[keys[1]]);
        //        if(m.size()==2)return dp[1];

        for( i = 1; i < m.size(); i++)
        {
            int ele = keys[i-1];
            if(ele == keys[i]-1)
            {
                if(i>=2)
                    dp[i]=max(m[keys[i]]+dp[i-2],dp[i-1]);
                else
                    dp[i]=max(m[keys[i]],dp[i-1]);

            }
            else
                dp[i]=m[keys[i]]+dp[i-1];
            //cout<<dp[i]<<" ";
        }
        return dp[m.size()-1];
    }
};