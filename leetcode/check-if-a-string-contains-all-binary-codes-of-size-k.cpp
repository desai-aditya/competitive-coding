class Solution {
public:
    string bintostr(int n,int k)
    {
        string s = "";
        while(n)
        {
            s+=to_string(n%2); 
            n/=2;
        }
        while(s.size()<k)s = "0"+s;
        return s;
    }
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int> m;
        string t="";
        for(int i = 0 ; i  < k && i < s.size() ; i ++)t+=s[i];
        m[t]++;
        
        for(int i = k ; i < s.size() ; i ++)
        {
            t.erase(0,1);
            t+=s[i];
            m[t]++;        
        }
        
        int flag=1;
        for(int i = 0 ; i < (1<<k); i++ )
        {
            string temp = bintostr(i,k);
            //cout<<temp<<endl;
            if(m[temp]==0)
            {
                flag=0;
                break;
            }
        }
        return flag;
    }
};