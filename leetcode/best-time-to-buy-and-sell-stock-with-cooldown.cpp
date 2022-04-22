class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MIN,sell=0,prevbuy,prevsell=0;
        for (int p:prices)
        {
            prevbuy=buy;
            buy=max(buy,prevsell-p);
            prevsell=sell;
            sell=max(sell,prevbuy+p);
            
        }
        return sell;
    }
};