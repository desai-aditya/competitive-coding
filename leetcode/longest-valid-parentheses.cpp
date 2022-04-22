class Solution {
public:
    
    int ans;    
    void helper(string & s, int reversed)
    {
        char left = '(';
        char right = ')';
        if(reversed)
        {
            left = ')';
            right= '(';
        }
        int counter = 0,len=0;
        for(int i = 0 ; i < s.size() ; i ++)
        {
            if(s[i]==left)
            {
                counter++;
            }
            else
            {
                counter--;
            }
            len++;
            if(counter<=0)
            {
                if(counter<0)
                    len = 0;
                ans = max(ans,len);
                counter=0;
            }        

        }
        if(counter==0)
        {
                ans = max(ans,len);
        }
        
    }
    int longestValidParentheses(string s) {
        ans = 0;
        helper(s,0);
        int a1=ans;
        reverse(s.begin(),s.end());
        ans=0;
        helper(s,1);
        int a2 = ans;
        //cout<<a1<<" "<<a2<<endl;
        return max(a1,a2);
    }
};