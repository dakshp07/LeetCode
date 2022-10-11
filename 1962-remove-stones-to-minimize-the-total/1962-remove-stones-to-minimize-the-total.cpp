class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // essentially we need to remove the k stones which have the max diff b/w piles[i] and piles[i]/2
        // we use max heap for this
        priority_queue<int> pq;
        int sum=0;
        // push all ele in heap and get the sum too
        for(int i=0; i<piles.size(); i++)
        {
            pq.push(piles[i]);
            sum+=piles[i];
        }
        // now we peform k operations
        while(k!=0)
        {
            int ele=pq.top();
            pq.pop();
            // remove ele/2 stones from ele
            // and push the remaining ele to heap
            pq.push(ele-ele/2);
            // and reduce the sum accordingly
            sum=sum-ele/2;
            // now the heap will always keep the order of max diff
            k--;
        }
        return sum;
    }
};