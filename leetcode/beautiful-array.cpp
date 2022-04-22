class Solution {
public:
    map<int,vector<int> > m;
    vector<int> beautifulArray(int n) {
        m = {};
        return f(n);
    }
    
    vector<int> f(int n )
    {
        if(m.find(n)!=m.end())return m[n];
        
        vector<int> ans(n);
        if(n==1)ans[0]=1;
        else
        {
            int t = 0 ; 
            vector<int> f1 = f((n+1)/2);
            for(int x : f1)
                ans[t++]=2*x-1;
            vector<int> f2 = f((n)/2);
            for(int x : f2)
                ans[t++]=2*x;
            
        }
        m[n]=ans;
        return ans;
    }
};