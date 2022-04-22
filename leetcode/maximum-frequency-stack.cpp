class FreqStack {
public:
    unordered_map<int,stack<int> > m_freq;
    unordered_map<int,int > m_count;
    vector<int> v;
    int index;
    int maxfreq;
    
    FreqStack() {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
        v.clear();        
        m_freq.clear();
        m_count.clear();
        index = 0;
        maxfreq=0;
    }
    
    void push(int x) {
        v.push_back(x);
        m_count[x]++;
        maxfreq = max(maxfreq,m_count[x]);
        m_freq[ m_count[x] ].push(index);
        index++;
    }
    
    int pop() {        
        while(m_freq[maxfreq].size()==0)maxfreq--;
        
        int idx = m_freq[maxfreq].top();
        int val = v[idx];
        m_count[val]--;
        m_freq[maxfreq].pop();
        
        
               
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */