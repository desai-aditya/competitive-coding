class Solution {
#define lli long long int
#define MOD 1000000007
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<lli, lli> m;
        vector<lli> dp(arr.size(),0);
        for(int i = 0 ;i < arr.size() ; i++)
        {
            m[arr[i]]=i;            
        }
        
        dp[0]=1;
        lli retval = 1;
        cout<<dp[0]<<endl;

        for(int i = 1 ;i < arr.size() ;  i ++)
        {
            lli ans= 0;
            for(int j = 0 ; j < i; j++)
            {
                //if((arr[i]/arr[j])*arr[j] == arr[i] )
                if( m.find(arr[i]/arr[j])!=m.end() && (arr[i]/arr[j])*arr[j] == arr[i])
                    ans = (ans%MOD + (dp[j]%MOD * dp[ m[arr[i]/arr[j]] ]%MOD ));
            }
            dp[i] = ans+1;     
            cout<<dp[i]<<endl;
            retval = (retval%MOD + dp[i]%MOD)%MOD;
        }
        return retval;
    }
};