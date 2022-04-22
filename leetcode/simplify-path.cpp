class Solution {
public:
    stack<string> s;
    string simplifyPath(string path) {
        int ptr = 0;
        while(ptr<path.size())
        {
            while(ptr<path.size() && path[ptr]=='/')ptr++;
            
            string temp = "";
                      
            while(ptr<path.size() && path[ptr]!='/')
            {
                temp+=path[ptr];
                ptr++;
            }
            if(temp!="")
            {
                if(temp == "..")
                {
                    if( !s.empty())
                        s.pop();
                }
                else if(temp == ".");
                else 
                {
                    s.push(temp);
                }
            }
                
        }
        
        string str = "";
        vector<string> v;
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        for(int i = v.size()-1; i>=0 ; i--)
        {
            str+="/"+v[i];
        }
        return str==""?"/":str;
    }
};