class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // since its subsets, we can change the order of elements
        // so we sort the ele
        // arr: [a,b,c] if c is divisble by b and b is divisible by a then c is also divisible by a
        // the above statement holds true only when array is sorted
        // rest all will be similar to lis code
        // just the condition of arr[ind]>arr[prev] will change to arr[ind]%arr[prev]==0
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        for(int i=0; i<=n-1; i++)
        {
            hash[i] = i; // initializing with current index
            for(int prev_index = 0; prev_index <=i-1; prev_index ++)
            {
                if(nums[i]%nums[prev_index] == 0 && 1 + dp[prev_index] > dp[i])
                {
                    dp[i] = 1 + dp[prev_index];
                    hash[i] = prev_index;
                }
            }
        }
        int ans = -1;
        int lastIndex =-1;
        for(int i=0; i<=n-1; i++)
        {
            if(dp[i]> ans)
            {
                ans = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex)
        { 
            // till not reach the initialization value
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);    
        }
        // reverse the array 
        reverse(temp.begin(),temp.end()); 
        return temp;
    }
};