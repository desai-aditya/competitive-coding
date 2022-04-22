class Solution {
public:
    long long int ans;
    unordered_map<int,int> dp;
    long long int helper(string &s,const int& i)
    {
        //cout<<s<<" "<<i<<endl;
        if(s.size()<=i)return 1;
        if(s[i]=='0')return 0;
        long long int tempans=0;
        if(dp.find(i)!=dp.end())return dp[i];

        if((s.size()== (1+i)&&s[0+i]=='*'))
        {
            tempans = (9*helper(s,i+1))%mod;
            dp[i]=tempans%mod;
            return tempans%mod;
        }
        else if((s.size()>=(2+i)&&s[0+i]=='*'&&s[1+i]!='*' ))
        {
           // for(int i = 0; i <= 9 ;i ++)
            //{
                //cout<<to_string(i)+s.substr(1,s.size()-1)<<endl;
                tempans = (9*helper(s,i+1))%mod;
            //}
                if(s[1+i]>='0'&&s[1+i]<='6')
                {
                    tempans = (tempans%mod + (2*helper(s,i+2))%mod)%mod;
                }
            else
            {
                                    tempans = (tempans%mod + helper(s,i+2))%mod;

            }
                    dp[i]=tempans%mod;

            //cout<<tempans<<" a"<<endl;
            return tempans%mod;
        }
        
        if(!(s[0+i]=='1'||s[0+i]=='2')&&s[0+i]!='0'&&s[0+i]!='*')
        {
            tempans =  helper(s,i+1)%mod;
        }
        else if((s[0+i]=='1'||s[0+i]=='2'||s[0+i]=='*'))
        {
            if(s.size()>=2 && s[0+i]=='2'&&!(s[1+i]>='1'&&s[1+i]<='6')&&s[1+i]!='*')
            {
                tempans=helper(s,i+2)%mod;
            }
            else if(s.size()>=2+i &&s[0+i]=='2'&&(s[1+i]>='1'&&s[1+i]<='6')&& s[1+i]!='*')
            {
                tempans = (helper(s,i+1))%mod + helper(s,i+2)%mod;
            }
            else if(s.size()>=2+i &&s[0+i]=='1' &&s[1+i]!='*')
            {
                tempans = (helper(s,i+1))%mod + helper(s,i+2)%mod;
            }
            else if(s.size()>=2+i && s[0+i]=='1'&&s[1+i]=='*')
            {
                //cout<<"A<<"<<helper(s,i+2))<<endl;
                tempans = helper(s,i+1)%mod + (9*helper(s,i+2))%mod%mod;
            }
            else if(s.size()>=2+i && s[0+i]=='2'&&s[1+i]=='*')
            {
                tempans = (helper(s,i+1))%mod + (6*helper(s,i+2))%mod%mod;
            }
            else if(s.size()>=2+i && s[0+i]=='*'&&s[1+i]=='*')
            {
                //cout<<"A";
                tempans = (9*helper(s,i+1))%mod + (15*helper(s,i+2))%mod%mod;
            }
            else if(s.size()>=2+i && s[0+i]=='*'&&(s[1+i]=='1'||s[1+i]=='2'))
            {
                tempans = (9*helper(s,i+1))%mod + (2*helper(s,i+2))%mod%mod;
            }
            else if(s.size()==1+i)
            {
                tempans  = helper(s,i+1)%mod;
            }
        }
        
        dp[i]=tempans%mod;
        return tempans%mod;
    }
    int mod = 1000000007;
    int numDecodings(string s) {
        ios_base::sync_with_stdio(NULL);
        cin.tie(NULL);
ans = 0;
        ans = helper(s,0);
        return ans;
    }
};
/*


if((s.size()>=2&&s[0]=='*'&&s[1]!='*' )|| (s.size()==1&&s[0]=='*'))
        {
           // for(int i = 0; i <= 9 ;i ++)
            //{
                //cout<<to_string(i)+s.substr(1,s.size()-1)<<endl;
                tempans = (9*helper(s.substr(1,s.size()-1)))%mod;
            //}
            //cout<<tempans<<" a"<<endl;
            return tempans;
        }
        */