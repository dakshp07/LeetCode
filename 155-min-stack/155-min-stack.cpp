class MinStack {
public:
    // we create a stack of pair<int, int> where the second integer is essentially the minimum we have seen so far
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) st.push({val, val});
        else
        {
            // if current val is smaller than the minimum seen so far
            if(val<st.top().second)
            {
                // we update minimum
                st.push({val, val});
            }
            else
            {
                // if current val is bigger than the minimum seen so far
                // then we just push val and not update the minimum
                st.push({val, st.top().second});
            }
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