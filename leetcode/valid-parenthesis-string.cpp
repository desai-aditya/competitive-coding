class Solution {
    private:
        vector<string> m_v{};
    bool getAll(string s,int idx)
    {
        if(s.size()==idx)
        {
            if(checkValid(s))
                return true;
            // m_v.push_back(s);
            //cout<<s<<endl;
            
        }
        else
        {
            
            
                if(s[idx]=='*')
                {
                    s[idx]='(';
                    if(getAll(s,idx+1))
                        return true;
                    s[idx]=')';
                    if(getAll(s,idx+1))
                        return true;
                    s.erase(s.begin()+idx);
                    if(getAll(s,idx))
                        return true;
                    
                }
                else
                {
                    if(getAll(s,idx+1))
                            return true;
                }
        }
        return false;
    }
    
    bool checkValid(const string& s)
    {
        int counter = 0;
        for(int i = 0 ; i <s.size(); i++)
        {
            if(s[i]=='(')
            {
                counter++;
            }
            else
            {
                counter--;
                if(counter<0)return false;
            }
        }
        return counter==0;
    }
    
    bool isTrue()
    {
        for(int i = 0 ; i < m_v.size(); i++)
        {
            if(checkValid(m_v[i]))
                return true;
        }
        return false;
        
    }
    
    bool tryNewFunc(string s)
    {
        int mine=0;int maxe=0;
        for(int i =  0; i < s.size(); i++)
        {
            if(s[i]=='(')
            {
                mine++;
                maxe++;
            }
            else if(s[i]==')')
            {
                mine--;
                maxe--;
            }
            else
            {
                mine--;
                maxe++;
            }
            if(maxe<0)return false;
            mine=max(0,mine);
        }
        // if(min<=0&&max>=0)return true;
        // else return false;
        return mine==0;
    }
    
    public:
        bool checkValidString(string s) {
        //if(s=="")return true;
        return tryNewFunc(s);
        // return isTrue();
    }
};