class Solution {
public:
    
    string removeParenthesis(string & s)
    {
        int br=0;
        for(int i  = 0 ; i < s.size(); i++)
        {
            if( s[i]=='(' )br++;
            else if( s[i]==')' )
            {
                br--;
                if(br<0)
                {
                    br=0;
                    s.erase(s.begin()+i);
                    i--;
                }
            }
        }
        return s;
    }
    
    string invertParenthesis(string & s)
    {
        string temp = "";
        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i]=='(')temp+=')';
            else if(s[i]==')')temp+='(';
            else temp+=s[i];
        }
        return temp;
    }
    string minRemoveToMakeValid(string s) {                
        s =  removeParenthesis(s);
        reverse(s.begin(),s.end());
        s = invertParenthesis(s);
        s =  removeParenthesis(s);
        reverse(s.begin(),s.end());
        s = invertParenthesis(s);
        return s;
    }
};