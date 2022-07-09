class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        // dp se karna hoga
        // dp+max heap lagao, heap store karega max value of the window i+k
        // dp[i] will store the max score till ith index
        priority_queue<pair<int, int>> pq;
        vector<int> dp(nums.size());
        // initialize dp
        dp[nums.size()-1]=nums[nums.size()-1];
        // initialize heap
        pq.push(make_pair(dp[nums.size()-1], nums.size()-1));
        // iterate from nums.size()-2
        for(int i=nums.size()-2; i>=0; i--)
        {
            // now we pop the ele that are exceeding index from our window ie i+k
            while(pq.size()>0 && pq.top().second>i+k)
            {
                pq.pop();
            }
            // add the ones that follow our window
            dp[i]=pq.top().first+nums[i]; // our current index + max of heap ie top of heap
            pq.push(make_pair(dp[i], i)); // push current score and index in heap
        }
        return dp[0];
    }
};