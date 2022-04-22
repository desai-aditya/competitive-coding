class Solution {
public:
    int numSquares(int n) {
        vector<int> leasts;
        vector<int> dp(n+1,INT_MAX-2);
        for(int i = 1 ; i * i <= n; i++)
        {
            leasts.push_back(i*i);
        }
        dp[0]=0;
        // dp[1]=1;
        for(int i = 1; i <= n ; i++)
        {
            for(auto leastsq : leasts)
            {
                if(i-leastsq<0)continue;
                dp[i]=min(dp[i],1+dp[i-leastsq]);
            }
        }
        return dp[n];
    }
};