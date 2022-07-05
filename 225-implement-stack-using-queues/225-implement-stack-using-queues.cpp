class MyStack {
public:
    // since a stack is lifo and queue is fifo
    // we can maintain two queues q1, q2
    // method: for push
    // 1. push x into q2
    // 2. put everything of q1 into q2 ele by ele
    // 3. swap everything from q2 to q1
    // for top: return top of q1
    // for pop remove top of q1
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        // step 1
        q2.push(x);
        // step 2
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        // step 3
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int n=q1.front();
        q1.pop();
        return n;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return (q1.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */