// SUPER HARD QUESTION

class Solution {
public:
    int func(vector<int> &multipliers, int ind, int start, vector<vector<int>> &dp, vector<int> &nums)
    {
        if(ind==multipliers.size()) return 0;
        if(dp[ind][start]!=INT_MIN) return dp[ind][start];
        int end=nums.size()-(ind-start)-1;
        // the capacity is at max m ops so thats our base case
        // since we pick first, no our pick range is reduced to start+1 to end
        int first=multipliers[ind]*nums[start]+func(multipliers, ind+1, start+1, dp, nums);
        int last=multipliers[ind]*nums[end]+func(multipliers, ind+1, start, dp, nums);
        int score=max(first, last);
        return dp[ind][start]=score;
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // so we need to pick any of the two choices either 1st ele or last ele
        // if we move greedily we wont get the correct ans as the future states might get affected because of previous decision
        // so we need to explore boh possibility
        /*
        recursion: tc: O(2^n) and sc: O(m)
        func(4, 2, 2) means we have computed the ans for 4 index of multipliers and 2 ele from start of nums and 2 ele from the end of nums. means end=size()-(i-start)-1;
        int func(int ind, int start, int end)
        {
        // the capacity is at max m ops so thats our base case
        if(ind==multipliers.size()) return 0;
        // since we pick first, no our pick range is reduced to start+1 to end
        int first=multipliers[i]*nums[start]+func(ind+1, start+1, end);
        int last=multipliers[i]*nums[end]+func(ind+1, start, end-1);
        int score=max(first, last);
        return score;
        }
        // for memoization we would need a 3*3 dp which is not good
        // so we reduce the state, lets see if we can reduce the end var
        // now we can reduce one var from above recursion code
        // end will be nums.size()-(ind-start)-1
        recursion:
        int func(int ind, int start)
        {
        int end=nums.size()-(ind-start)-1;
        // the capacity is at max m ops so thats our base case
        if(ind==multipliers.size()) return 0;
        // since we pick first, no our pick range is reduced to start+1 to end
        int first=multipliers[i]*nums[start]+func(ind+1, start+1, end);
        int last=multipliers[i]*nums[end]+func(ind+1, start, end-1);
        int score=max(first, last);
        return score;
        }
        
        memoization:
        vector<vector<int>> dp(multipliers.size(), vector<int>(multipliers.size(), -1));
        int func(int ind, int start)
        {
        if(dp[ind][start]!=-1) return dp[ind][start];
        int end=nums.size()-(ind-start)-1;
        // the capacity is at max m ops so thats our base case
        if(ind==multipliers.size()) return 0;
        // since we pick first, no our pick range is reduced to start+1 to end
        int first=multipliers[i]*nums[start]+func(ind+1, start+1, end);
        int last=multipliers[i]*nums[end]+func(ind+1, start, end-1);
        int score=max(first, last);
        return dp[ind][start]=score;
        }
        */
        // memoization:
        vector<vector<int>> dp(multipliers.size(), vector<int>(multipliers.size(), INT_MIN));
        return func(multipliers, 0, 0, dp, nums);
    }
};
