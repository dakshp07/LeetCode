class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // one of the ways is t sort the array and look for k-1 th ele which is basially kth largest ele
        // but tc will be O(nlogn) and sc: O(1)
        // but lets optimise it to O(n) and some sc: O(n)
        // we can use a heap (ie max heap) to do that and it will arrange ele in increasing order for us
        // heap insertion is O(1) and access is O(n) which is certainly removing that extra log n in our sorting complexity
        priority_queue<int> pq;
        for(int i=0; i<nums.size(); i++)
        {
            // insert in queue
            pq.push(nums[i]);
        }
        // to make k zero based index we reduce k by one
        k--;
        while(k!=0)
        {
            // we pop until we reach kth ele
            pq.pop();
            k--;
        }
        return pq.top(); // now top will have the kth largest ele
    }
};
