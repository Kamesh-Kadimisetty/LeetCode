class MyCircularDeque {
public:
    vector<int>queue;
    int rear,front,count,n;
    MyCircularDeque(int k) {
        queue=vector<int>(k);
        rear=k-1,front=0,count=0,n=k;
    }
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        front=(front-1+n)%n;
        queue[front]=value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        rear=(rear+1)%n;
        queue[rear]=value;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        front=(front+1)%n;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        rear=(rear-1+n)%n;
        count--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return queue[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return queue[rear];
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() { 
        return count==n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */