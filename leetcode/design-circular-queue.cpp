class MyCircularQueue {
public:
    vector<int> arr;
    int front,end,n;
    MyCircularQueue(int k) {
        arr = vector<int>(k+1,0);
        front = 0;
        end = 0;
        n=k+1;
    }
    
    bool enQueue(int value) {
        if(!isFull())
        {
            arr[end]=value;
            end = (end+1)%n;
            return true;
        }
        else        
            return false;        
    }
    
    bool deQueue() {
        if(!isEmpty())
        {
            front = (front+1)%n;
            return true;
        }
        else            
            return false;
    }
    
    int Front() {
        if(isEmpty())return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty())return -1;
        int index = end;
        if(index==0)index=n-1;
        else index=(end-1);
        return arr[index];
    }
    
    bool isEmpty() {
        return front==end;
    }
    
    bool isFull() {        
        return (end+1)%n==front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */