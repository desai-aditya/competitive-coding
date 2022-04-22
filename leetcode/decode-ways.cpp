class Solution {
public:
    int ans;
    unordered_map<string,int> dp;
    int helper(string s)
    {
        //cout<<s<<endl;
        if(s.size()==0)return 1;
        if(s[0]=='0')return 0;
        if(dp.find(s)!=dp.end())return dp[s];
        int tempans=0;
        if(!(s[0]=='1'||s[0]=='2')&&s[0]!='0')
        {
            tempans =  helper(s.substr(1,s.size()-1))%mod;
        }
        else if((s[0]=='1'||s[0]=='2')&&s[0]!='0')
        {
            if(s.size()>=2 && s[0]=='2'&&!(s[1]>='1'&&s[1]<='6'))
            {
                tempans=helper(s.substr(2,s.size()-2))%mod;
            }
            else if(s.size()>=2 &&s[0]=='2'&&(s[1]>='1'&&s[1]<='6') )
            {
                tempans = (helper(s.substr(1,s.size()-1)) + helper(s.substr(2,s.size()-2)))%mod;
            }
            else if(s.size()>=2 &&s[0]=='1' )
            {
                tempans = (helper(s.substr(1,s.size()-1)) + helper(s.substr(2,s.size()-2)))%mod;
            }
            else if(s.size()==1)
            {
                tempans  = helper(s.substr(1,s.size()-1))%mod;
            }
            
        }
        
        dp[s]=tempans%mod;
        return tempans%mod;
    }
    int mod = INT_MAX;
    int numDecodings(string s) {
        
ans = 0;
        ans = helper(s);
        return ans;
    }
};