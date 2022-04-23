class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //vector<int> mincosts(1+n,INT_MAX);
        int mincosts0;
        int mincosts1;
        mincosts0=0;
        mincosts1=0;
        int mincostfinal=INT_MAX;
        for(int i = 2; i <= n; i++)
        {
            mincostfinal = min(mincosts1+cost[i-1], mincosts0+cost[i-2 ]);
            mincosts0=mincosts1;
            mincosts1=mincostfinal;
        }
        return mincostfinal;
    }
};