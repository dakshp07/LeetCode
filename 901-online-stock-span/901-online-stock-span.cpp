class StockSpanner {
public:
    // this is again similar to next greater or next smaller ele quetion
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        // ans will be intialized as 1 for all cases
        int ans=1;
        // check if the top of st is less than price
        while(!st.empty() && st.top().first<=price)
        {
            // if yes then pop and add the last ans
            ans+=st.top().second;
            st.pop();
        }
        // push the pair of ans and price
        st.push(make_pair(price, ans));
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */