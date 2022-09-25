class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        // we will try to explore all paths
        // lets use recursion
        /*
        recursion: tc: exponential and sc: O(path length)
        // this sum var will be used to calculate the final ans
        int sum=0;
        int func(int ind)
        {
        // base case
        if(ind==0) return arr[ind];
        // explore possibilities
        for(int next=1; next<=k; next++)
        {
        // to make sure we never reach -ve index
        if(ind-next>=0)
        {
        int temp=arr[ind]+func(ind-next);
        sum=max(sum, temp);
        }
        }
        return sum;
        }
        
        memoization: tc: exponential and sc: O(path length) and O(n)
        vector<int> dp(100001, -1);
        int sum=0;
        int func(int ind)
        {
        if(dp[ind]!=-1) return dp[ind];
        // base case
        if(ind==0) return arr[ind];
        // explore possibilities
        for(int next=1; next<=k; next++)
        {
        // to make sure we never reach -ve index
        if(ind-next>=0)
        {
        int temp=arr[ind]+func(ind-next);
        sum=max(sum, temp);
        }
        }
        return dp[ind]=sum;
        }
        */
        // tabulation: O(n*k) and sc: O(n)
        // int n=nums.size();
        // vector<int> dp(n, -1e9);
        // base case
        // dp[0]=nums[0];
        // for(int ind=1; ind<n; ind++)
        // {
        //     int sum=-1e9;
        //     for(int next=1; next<=k; next++)
        //     {
        //         if(ind-next>=0)
        //         {
        //             int temp=nums[ind]+dp[ind-next];
        //             sum=max(sum, temp);
        //         }
        //     }
        //     dp[ind]=sum;
        // }
        // return dp[n-1];
        
        // priority queue: tc: O(nlogk) and sc: O(n+n)
        // so instead of getting max fromm the dp array, we use max heap
        // and we will pop the heap till we get the next maximum sum
        priority_queue<pair<int, int>> pq;
        pq.push({nums[0], 0});
        
        for(int i=1;i<nums.size();i++){
            while(pq.size() && pq.top().second < i-k) pq.pop();
            pq.push({pq.top().first + nums[i], i});
        }
        while(pq.top().second != nums.size()-1) pq.pop();
        return pq.top().first;
    }
};