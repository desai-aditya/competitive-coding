class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)return n;
        int f=1;
        int s=2;
        int l=3;
        for(int i = 0 ; i <= n-3; i++)
        {
            l=f+s;
            f=s;
            s=l;
        }
        return l;
    }
};