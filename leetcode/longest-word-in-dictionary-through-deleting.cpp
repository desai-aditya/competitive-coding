class Solution {
public:
    static bool compfunc(string& s1, string& s2)
    {
        if(s1.size()>s2.size())return true;
        else if(s1.size()==s2.size())
        {
            for(int i = 0 ; i < s1.size(); i++)    
            {
                if(s1[i]<s2[i])return true;
                else if(s1[i]==s2[i])continue;
                else break;
            }
            return false;
        }
        return false;

    }
    
    bool ispresent(string &findstr, string& bigstr)
    {
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < findstr.size() && ptr2 < bigstr.size())
        {
            if(findstr[ptr1]==bigstr[ptr2])
            {
                ptr1++; ptr2++;
            }
            else ptr2++;
        }
        if(ptr1==findstr.size())return true;
        else return false;
    }
    string findLongestWord(string s, vector<string>& d) {
                ios_base::sync_with_stdio(0),cin.tie(0);

        sort(d.begin(),d.end(),compfunc);
        //for(int i = 0 ; i < d.size() ; i ++)cout<<d[i]<<" ";
        //cout<<endl;
        for(int i = 0 ; i < d.size() ; i ++)
        {
            if(ispresent(d[i],s))
            {
                return d[i];
            }
        }
        return "";
    }
};