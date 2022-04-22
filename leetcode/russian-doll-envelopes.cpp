class Solution {
public:
    static bool func(vector<int> a, vector<int> b)
    {
        if(a[0]<b[0] )return true;
        
        return false;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),func);
        
        for(int i  = 0 ;i  < envelopes.size() ;  i ++)
        {
            cout<<envelopes[i][0]<<" "<<envelopes[i][1]<<endl;
        }
        
        vector<int> length(envelopes.size(),1);
        int ans = 0;
        for(int i = 0 ; i < envelopes.size() ; i ++ )
        {
            
            for(int j = 0 ; j < i; j++)
            {
                if(envelopes[j][0]<envelopes[i][0] && envelopes[j][1]<envelopes[i][1]  )
                {
                    length[i] = max(length[i],length[j]+1);
                }
            }
            ans = max(ans,length[i]);                                
        }
        return ans;
    }
};