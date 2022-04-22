class Solution {
public:
    int dp[100001][2][2];
    int helper(vector<int>& prices,int idx, int buy, int num)
        {
        
        if(idx>=prices.size()||num==2)return 0;
        if(dp[idx][buy][num]!=-1)return dp[idx][buy][num];
        int profit=0;
        if(buy)
            {
            int buynow=helper(prices,idx+1,0,num)-prices[idx];
            int notbuynow=helper(prices,idx+1,1,num);
            profit=max(buynow,notbuynow);
            }
        else{
            int sell=helper(prices,idx+1,1,num+1)+prices[idx];
            int notsell=helper(prices,idx+1,0,num);
            profit=max(sell,notsell);
            
            }
        
       return dp[idx][buy][num]=profit;
        
        
        
        }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return helper(prices,0,1,0);
    }
};