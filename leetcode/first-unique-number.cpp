class FirstUnique {
public:
    
    unordered_map<int,int> m;
    deque<int> q;
    
    FirstUnique(vector<int>& nums) {
        for(int i = 0 ; i < nums.size(); i++)
        {
            add(nums[i]);
        }
    }
    
    int showFirstUnique() {
        if(q.empty())return -1;
        return q.front();
    }
    
    void add(int value) {
        
        m[value]++;
        q.push_back(value);
        
        while(!q.empty() && m[q.front()]>1)
        {
            q.pop_front();
        }
        
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */