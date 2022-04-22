class MapSum {
public:
    /** Initialize your data structure here. */
    map<string,int> m;
    MapSum() {
        m={};
    }
    
    void insert(string key, int val) {
        m[key]=val;
    }
    bool comp(string s1, string s2)
    {
        if(s1.size()>s2.size())return false;

        for(int i = 0 ;i  <s1.size()&&i<s2.size(); i++)
        {
            if(s1[i]!=s2[i])return false;
        }
        return true;
    }
    int sum(string prefix) {
        int sumel = 0;
        for(auto itr = m.begin(); itr!=m.end(); itr++)
        {
            
            if(comp(prefix,itr->first))
            {
                sumel+=itr->second;
            }
        }
        return sumel;
    }
    
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */