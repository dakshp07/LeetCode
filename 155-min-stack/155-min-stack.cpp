class MinStack {
public:
    // create a stack and store pair (number, minimum)
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        // we see if stack is empty, if yes then the curr push is minimum
        if(st.empty()) st.push(make_pair(val, val));
        // if stack isnt empty then we check the second of top and see minimum
        else
        {
            if(st.top().second<val) st.push(make_pair(val, st.top().second));
            else st.push(make_pair(val, val));
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */