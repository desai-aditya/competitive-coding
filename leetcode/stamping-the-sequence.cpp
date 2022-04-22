class Solution {
public:
    
    int needstamp(int index, string & stamp, string & target )
    {
        int count = 0;
        
        for(int i = 0; i < stamp.size() && i+index< target.size() ; i++)
        {
            if(target[i+index] == '?')continue;
            else if(stamp[i] == target[i+index])
            {
                count++;
            }
            else
            {
                count=-1;
                break;
            }
            
        }
        
        if(count > 0)
        {
            for(int i = 0; i < stamp.size() && i+index< target.size() ; i++)
            {
                target[i+index]='?';
            }
        }
        return count;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        if(stamp[0]!=target[0])return {};      
        if(stamp[stamp.size()-1]!=target[target.size()-1])return {};
        if(stamp==target)return {0};
        vector<int> ans;
        queue<int> q;
        for(int i = 0 ; i + stamp.size()  <= target.size() ; i++)
        {
            q.push(i);
        }
        
        while(true)
        {
            int l = q.size();
            for(int i = 0 ; i < l;  i ++)
            {
                
                int f = q.front();
                q.pop();
                
                int status = needstamp(f,stamp,target);
                
                if(status>0)
                {
                    ans.push_back(f);
                }
                else if(status<0)
                {
                    q.push(f);
                }
                
            }
            
            if(l == q.size())
            {
                break;
            }
        }
        if(q.size()>0)return vector<int>();
        
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};