class Solution {
public:
    int fillCups(vector<int>& amount) {
        // greedily karenge, try to fill max cups in 1 sec ie pick 2 cups
        // max heap main store karenge
        int ans=0;
        priority_queue<int> pq;
        for(int i=0; i<amount.size(); i++)
        {
            if(amount[i]>0) pq.push(amount[i]);
        }
        // we will keep popping the top ele and put water in it
        while(pq.size()>=2)
        {
            // we will pop the top two ele
            int top_one=pq.top();
            pq.pop();
            
            int top_two=pq.top();
            pq.pop();
            
            // and now we will add wauter to them in 1 sec and add them back to heap
            ans++;
            if(top_one-1!=0) pq.push(top_one-1);
            if(top_two-1!=0) pq.push(top_two-1);
        }
        // check if we have any ele left
        if(pq.size()>0) ans+=pq.top();
        return ans;
    }
};