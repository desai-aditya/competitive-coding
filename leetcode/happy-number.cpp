class Solution {
private:
    long long int _calc(int num)
    {
        long long int ans=0;
        while(num)
        {
            ans+=(num%10)*(num%10);
            num/=10;
        }
       // cout<<ans<<endl;
        return ans;
    }
    
public:
    bool isHappy(int n) {
        unordered_map<long long int, int> m{};
        long long int temp=_calc(n);
        //cout<<temp;
        while(!m[temp])
        {
            m[temp]++;
            if(temp==1)return true;
            
            n=temp;
            temp=_calc(n);
        }
        return false;
    }
};