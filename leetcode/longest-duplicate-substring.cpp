class Solution {
public:
    #define p 10000007
    vector< int> roll;
    bool rabin(int mid, string &s, string &  temp)
    {
        unordered_map<int, vector<int> > m;
        int hash =0;
        for(int i = 0 ;i <  mid; i ++) hash= (hash*26+(s[i]-'a'))%p;
        m[hash].push_back(0);
        
        for(int i = 1; i <= s.size()-mid; i++)
        {
            hash = ((hash - ((s[i-1]-'a')*roll[mid-1]))%p +p)%p;
            hash = (hash*26 + (s[i+mid-1]-'a'))%p;
            if(m.find(hash)!=m.end())
            {
                for(auto it : m[hash])
                {
                    string s1 = s.substr(i,mid);
                    string s2 = s.substr(it,mid);
                    if(s1==s2)
                    {
                        temp=s1;
                        return true;
                    }
                }
                
            }
            m[hash].push_back(i);
        }
        return false;
    }
    string longestDupSubstring(string s) {
        if(s.size()==0)return "";
        roll.resize(s.length());
        roll[0]=1;
        for (int i=1;i<s.length();i++)    roll[i]=(roll[i-1]*26) %p;
        int l = 1;
        int r = s.size();
        string ans;
        while(l<=r)
        {
            string temp;
            int mid = (l+r)>>1;
            bool has = rabin(mid,s,temp);
            
            if(has)
            {
                if(temp.size()>ans.size())ans=temp;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};