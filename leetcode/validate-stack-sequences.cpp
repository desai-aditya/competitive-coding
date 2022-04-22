class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()==0)return true;
        stack<int> s;
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int ptr1=0,ptr2=0;
        while(ptr1 < pushed.size())
        {
            s.push(pushed[ptr1]);
            ptr1++;
            while( !s.empty() && ptr2 < popped.size() && s.top() == popped[ptr2] )
            {
                s.pop(); ptr2++;
            }
            
        }
    
        if(ptr2==popped.size())return true;
        return false;
        
    }
};