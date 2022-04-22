class MedianFinder {
public:
    priority_queue <int> maxheap;
    priority_queue <int, vector<int>, greater<int> > minheap;
    /** initialize your data structure here. */
    MedianFinder() {
        maxheap = {};
        minheap = {};
    }
    
    void addNum(int num) {
        
        if(maxheap.size() == minheap.size()){
            if(maxheap.size()==0||num<maxheap.top())
                maxheap.push(num);
            else
                minheap.push(num);
        }
        else if(maxheap.size()>minheap.size() )
        {
            if(num>maxheap.top())
                minheap.push(num);
            else
            {
                int k  = maxheap.top();maxheap.pop();
                maxheap.push(num);
                minheap.push(k);
            }
        }
        else if(minheap.size()>maxheap.size())
        {
            //cout<<"A<"<<endl;
            if(num<minheap.top())
                maxheap.push(num);
            else
            {
                int k  = minheap.top();minheap.pop();
                minheap.push(num);
                maxheap.push(k);
            }
        }
        
    }
    
    double findMedian() {
        if(minheap.size()>maxheap.size())return minheap.top();
        else if(minheap.size()<maxheap.size())return maxheap.top();
        else
        {
            return ((double)minheap.top()+(double)maxheap.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */