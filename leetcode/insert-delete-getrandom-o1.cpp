class RandomizedSet {
public:
    vector<int> a;
    unordered_map<int,int> m;
    RandomizedSet() {
        a.clear();
        m={};
    }
    
    bool insert(int val) {
        auto it = m.find(val);
        if(it==m.end())
        {
            a.push_back(val);
            m[val]=a.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto it = m.find(val);
        if(it!=m.end())
        {
            a[it->second]=a.back();
            a.pop_back();
            m[a[it->second]]=it->second;
            m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return a[rand()%(a.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */