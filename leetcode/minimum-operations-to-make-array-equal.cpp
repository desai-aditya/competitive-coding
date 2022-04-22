class Solution {
public:
    int minOperations(int n) {
        long long int ans = 0;
        if(n%2==0)
        {
            for(int i = 0 ;i < n/2 ; i ++)
            {
                ans += 2*i+1;
            }
        }
        else
        {
            for(int i = 0 ;i < n/2 ; i ++)
            {
                ans += n-(2*i+1);
            }
            
        }
        return ans;
    }
};