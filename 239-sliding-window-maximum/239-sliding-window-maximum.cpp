class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // brute force is to traverse through the subarrays of size 3
        // we can run a for loop till the last 3rd index of an array
        // and the sub array in between will be identified by a for loop that runs from i to i+k-1
        // tc: O(n*k)
        
        // we will use the concept of next greater element by using a deque
        // tc: O(N)+O(N)~=O(2N)
        deque<int> dq; // to store indices
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            // now if our front is the value of i-k we pop
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();
            // if a new ele in nums is bigger than our previous then we pop
            while(!dq.empty() && nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }
            // else in other cases we push
            dq.push_back(i);
            // we when we get the window of size k we push front of deque to ans vector
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};