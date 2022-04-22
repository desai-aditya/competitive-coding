class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        vector<int> next(n,INT_MAX),prev(n,INT_MAX),ans(n,0);
        int ind=INT_MAX;
        for(int i=n-1;i>=0;i--)
            {
                if(s[i]==c)
                    ind=i;
                next[i]=ind;
            //cout<<next[i];
            }
        ind=INT_MAX;
        for(int i=0;i<n;i++)
            {
                if(s[i]==c)
                    ind=i;
                prev[i]=ind;
                ans[i]=next[i]-i;
            if(prev[i]!=INT_MAX)
                ans[i]=min(next[i]-i,i-prev[i]);
            }
        
        
        return ans;
        
        
        
    }
};