class Solution {
public:
    int climbStairs(int n) {
        if(n<=3)return n;
        int x = 2;
        int y = 3;
        int ans=3;
        for(int i = 4; i <= n; i++)
        {
            ans=x+y;
            x=y;
            y=ans;
        }
        return ans;
    }
};