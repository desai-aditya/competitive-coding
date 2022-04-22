class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q{};
        for(auto st:stones)q.push(st);
        int st1=q.top();q.pop();
        if(q.empty())return st1;
        int st2=q.top();q.pop();
        if(q.empty())return st1-st2;
        while(!q.empty())
        {
            if(st1==st2)
            {
                
            }
            else
            {
                st1-=st2;
                q.push(st1);
                    
            }
            st1=q.top();q.pop();
                if(q.empty())return st1;
            st2=q.top();q.pop();
                if(q.empty())return st1-st2;
            
            
        }
        return 0;
    }
};