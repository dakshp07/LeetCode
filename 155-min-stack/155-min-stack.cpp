class MinStack {
public:
    // we create a stack of pairs
    // and the second ele of pair will always maintain a min
    // and first ele is the one we are pushing
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        // so everytime we push we maintain a minimum in second int of pair
        // we push both ele as val if the stack is empty
        if(st.empty()) st.push({val, val});
        // if its not empty we push the ele and maintain a min
        else
        {
            // now if val is <st.top().second, we make val as minimum
            if(val<st.top().second)
            {
                st.push({val, val});
            }
            // now if val is >st.top().second, we keep st.top().second as min
            else
            {
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