class MyQueue {
public:
    // we can use 2 stacks, s1 and s2
    // when we push:
    // 1. transfer stuff from s1 to s2
    // 2. push x to s1
    // 3. transfer stuff from s2 to s1
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        // step 1
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        // step 2
        s1.push(x);
        // step 3
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int n=s1.top();
        s1.pop();
        return n;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */