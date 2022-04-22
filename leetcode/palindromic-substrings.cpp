class Solution {
public:
    long long int ans;
    
    void counteven(string & s)
    {
        int i=0,j=1;
        //string t;
        while(j<s.size())
        {
            
            int left=i;
            int right=j;
            
            while(left>=0 && right<s.size() && s[left]==s[right])
            {
                ans++;
                left--;
                right++;
            }          
            i++;j++;
        }
        
    }
    
    void countodd(string & s)
    {
        int i=0;
        //string t;
        while(i<s.size())
        {
            ans++;
            int left=i-1;
            int right=i+1;
            
            while(left>=0 && right<s.size() && s[left]==s[right])
            {
                ans++;
                left--;
                right++;
            }   
            i++;
        }
        
    }
    
    int countSubstrings(string s) {
        ans=0;
        counteven(s);
        countodd(s);
        return ans;
    }
};