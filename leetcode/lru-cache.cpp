class LRUCache {
private:
    
    struct node{
        int key,val;
    } ;
    
    int m_capacity{};
    
    list<node> dq;
    map<int, list<node>::iterator> m;
    public:
    
    LRUCache(int capacity):m_capacity{capacity} {
        
    }
    
    int get(int key) {
        if(m.find(key)==m.end())return -1;
        node ans = *(m[key]);
        dq.erase(m[key]);
        dq.push_front(ans);
        m[key]=dq.begin();
        return ans.val;
        
    }
    
    void put(int key, int value) {
        
        if( m.find(key) == m.end())
        {
            if(dq.size() == m_capacity)
            {
                node last = dq.back();
                dq.pop_back();
                m.erase(last.key);
            }
        }
        else
            dq.erase(m[key]);
        
        dq.push_front({key,value});
        m[key]=dq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */