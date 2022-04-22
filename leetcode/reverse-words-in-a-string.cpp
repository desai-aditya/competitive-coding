class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int i=0;
        while(i<s.size())
        {
            while(i<s.size()&&s[i]==' ')i++;
            string t="";
            while(i<s.size()&&s[i]!=' ')
            {
                t+=s[i];
                i++;
            }
            if(t.size()!=0)
                 v.push_back(t);
        }
        reverse(v.begin(),v.end());
        string ans = "";
        for(int i = 0 ; i < v.size(); i++)
        {
            ans+=v[i];
            if(i!=v.size()-1)
                ans+=" ";
        }
        return ans;
    }
};