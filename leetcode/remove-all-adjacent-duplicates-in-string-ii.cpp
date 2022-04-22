class Solution {
public:
    string removeDuplicates(string s1, int k) {
        stack< pair<char,int> > s;
        for(int i = 0 ;i < s1.size(); i++)
        {
            if(!s.empty())
            {
                auto p = s.top();
                if(s1[i] == p.first )
                {
                    s.pop();
                    if(p.second+1 != k)
                    {
                        s.push( make_pair( s1[i] , p.second+1 ) );
                    }
                }
                else
                {
                    s.push(make_pair( s1[i] , 1 ));

                }
                
            }
            else
            {
                s.push(make_pair( s1[i] , 1 ));
            }
        }
        
        string str="";
        while(!s.empty())
        {
            int times = s.top().second;
            for(int i = 0 ;i < times; i++)
            {
                str+=s.top().first;    
            }
            
            s.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};