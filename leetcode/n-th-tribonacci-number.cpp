class Solution {
public:
    int tribonacci(int n) {
        if(n==0)return 0;
        if(n<=2)return 1;
        if(n==3)return 2;
        int i=1;
        int j=1;
        int k=2;
        int l;
        for(int p = 0 ; p < n-3; p++)
        {
            l=i+j+k;
            i=j;
            j=k;
            k=l;
        }
        return l;
        
    }
};