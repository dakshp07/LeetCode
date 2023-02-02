class Solution {
public:
    int dp[20001];
    int func(int ind, vector<int> &freq)
    {
        // base case:
        // 1. if we reach end of freq array
        if(ind==freq.size()-1) return ind*freq[ind];
        // 2. if we go beyond the bounds
        if(ind>=freq.size()) return 0;

        if(dp[ind]!=-1) return dp[ind];

        // two options
        // pick
        // we get ind*freq[ind] points and move to ind+2 as ind+1 and ind-1 ele are deleted
        int pick=ind*freq[ind]+func(ind+2, freq);

        // not pick
        // we get 0 points and move to ind+1 we didnt picked ind ele
        int not_pick=0+func(ind+1, freq);

        return dp[ind]=max(pick, not_pick);
    }
    int deleteAndEarn(vector<int>& nums) {
        // one thing is clear that we cant use greedy here
        // we have to use recursion
        // so we store the nums[i] along with their frequencies in freq vector
        // so the catch here is:
        // 1.if i pick any nums[i], ive to eventually pick all of its occurences (write some test cases t visualize)
        // 2. if i dont pick any nums[i], i will skip it entirely

        // so we have two options either to pick ith ele or not
        // if we pick we get points as i*freq[i] and move to i+2
        // as we will have to delete all nums which are i+1
        /*
        int func(int ind, vector<int> &freq)
        {
            // base case:
            // 1. if we reach end of freq array
            if(ind==freq.size()-1) return ind*freq[ind];
            // 2. if we go beyond the bounds
            if(ind>=freq.size()) return 0;

            // two options
            // pick
            // we get ind*freq[ind] points and move to ind+2 as ind+1 and ind-1 ele are deleted
            int pick=ind*freq[ind]+func(ind+2, freq);

            // not pick
            // we get 0 points and move to ind+1 we didnt picked ind ele
            int not_pick=0+func(ind+1, freq);

            return max(pick, not_pick);
        }
        */
        // memoization:
        int maxi=*max_element(nums.begin(), nums.end());
        vector<int> freq(maxi+1, 0);
        for(int i=0; i<nums.size(); i++) freq[nums[i]]++;
        memset(dp, -1, sizeof(dp));
        return func(0, freq);
    }
};
