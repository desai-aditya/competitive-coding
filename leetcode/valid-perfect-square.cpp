class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i; long long n=num;
        for(i = 0 ; i *i <=n; i++)
        {
            if(i*i==n)return true;
        }
        return false;
        
    }
};