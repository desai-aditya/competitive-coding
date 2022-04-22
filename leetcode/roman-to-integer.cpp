/*
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
*/
class Solution {
public:
    int romanToInt(string s) {
        s = "0" + s;
        map<char,int> m;
        m['I']=1; m['V']=5; m['X']=10; m['L']=50; m['C']=100; m['D']=500; m['M']=1000;
        int ans = 0;
        for(int i = s.size()-1 ; i >= 1 ; i-- )
        {
            if(s[i-1]=='I'&&s[i]=='V')
            {
                i-=1;
                ans+=4;
            }
            else if(s[i-1]=='I'&&s[i]=='X')
            {
                i-=1;
                ans+=9;
            }
            else if(s[i-1]=='X'&&s[i]=='L')
            {
                i-=1;
                ans+=40;
            }
            else if(s[i-1]=='X'&&s[i]=='C')
            {
                i-=1;
                ans+=90;
            }
            else if(s[i-1]=='C'&&s[i]=='D')
            {
                i-=1;
                ans+=400;
            }
            else if(s[i-1]=='C'&&s[i]=='M')
            {
                i-=1;
                ans+=900;
            }
            else
            {
                ans+=m[s[i]];
            }
            
        }
        return ans;
    }
};