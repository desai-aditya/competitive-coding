class Solution {
public:
    int fib(int n) {
        long long int cur = 1;
        long long int next = 1;
        long long int last;
        if(n==0)return 0;
        if(n<=2)return 1;
        for(int i  = 0; i<n-2; i++)
        {
            last=cur+next;
            cur=next;
            next=last;
        }
        return last;
    }
};