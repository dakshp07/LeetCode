class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // we can use the priority queue to make sure we have the top 2 heaviest stones
        priority_queue<int> pq;
        for(int i=0; i<stones.size(); i++)
        {
            pq.push(stones[i]);
        }
        // now we traverse through heap
        int sz=pq.size();
        // we do this step till we have just 1 ele in our heap
        while(sz>1)
        {
            int one=pq.top();
            pq.pop();
            int two=pq.top();
            pq.pop();
            // we push the diff as we would get cases where we have 0 stones left
            pq.push(one-two);
            sz=pq.size();
        }
        return pq.top();
    }
};