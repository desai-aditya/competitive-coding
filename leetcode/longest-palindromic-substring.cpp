class Solution {
public:
    string ans="";
    
    void solveeven(string& s)
    {
        string evenlengthstr="";
        int i=0,j=1;
        string t="";
        while(j<s.size())
        {
            t="";
            int left=i;
            int right=j;
            while(left>=0 && right<s.size() && s[left]==s[right])
            {
                t = s[left] + t + s[right];
                if(ans.size()<t.size())ans=t;                
                left--;right++;
            }
            i++;j++;            
        }
    }
    
    void solveodd(string& s)
    {
        string oddlengthstr="";
        int i=0;
        string t="";
        while(i<s.size())
        {
            t=s[i];
            
            int left=i-1;
            int right=i+1;
            while(left>=0 && right<s.size() && s[left]==s[right])
            {
                t = s[left] + t + s[right];
                if(ans.size()<t.size())ans=t;                
                left--;right++;
            }
            i++;
        }
        
    }
    
    bool ispalin(string& s)
    {
        int i=0,j=s.size()-1;
        while(j>=i)
        {
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(ispalin(s))return s;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ans="";
        solveeven(s);
        solveodd(s);
        if(ans.size()==0)ans = ans +s[0];
        return ans;
        
    }
};