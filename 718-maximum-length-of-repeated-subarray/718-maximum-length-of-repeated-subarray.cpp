class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // we need to explore all the paths in this one
        // so we use recursion
        /*
        recursion: tc: O(2^n) and sc: O(longest path)
        // i is pointing on nums1, j is pointing on nums2
        // i, j start from n-1 and go till 0
        int len=-1e9;
        int func(int i, int j)
        {
        if(i<0 || j<0) return 0;
        // if the ele at both index are = then we add +1 to ans and move to next ele
        if(nums1[i]==nums2[j])
        {
        len=max(1+func(i-1, j-1), len);
        }
        else
        {
        // in all other cases when they are != we have 2 options
        // either go to next ele in nums1 or go to next ele in nums2
        // we pick max of both choices
        len=max(len, max(func(i, j-1), func(i-1, j)));
        }
        return len;
        }
        
        memoization: tc: O(n) and sc: O(n)+O(nums1*nums2)
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
        int len=-1e9;
        int func(int i, int j)
        {
        if(dp[i][j]!=-1) return dp[i][j];
        if(i<0 || j<0) return 0;
        // if the ele at both index are = then we add +1 to ans and move to next ele
        if(nums1[i]==nums2[j])
        {
        len=max(1+func(i-1, j-1), len);
        }
        else
        {
        // in all other cases when they are != we have 2 options
        // either go to next ele in nums1 or go to next ele in nums2
        // we pick max of both choices
        len=max(len, max(func(i, j-1), func(i-1, j)));
        }
        return dp[i][j]=len;
        }
        */
        // tabulation: O(nums1*nums2) and sc: O(nums1*nums2)
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        // in order to cover the cases of i<0 and j<0 we shift the index
        // and hence we create a dp of size nums1+1 and nums2+1
        // since now our base case is of i==0,j==0 and we have already declared dp with 0
        // we are not supposed to handle the base case seperately
        
        // for loops also starts from 1
        int len=0;
        for(int i=1; i<=nums1.size(); i++)
        {
            for(int j=1; j<=nums2.size(); j++)
            {
                // since we shifted everything, we now check nums1[i-1] and nums2[j-1]
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=0;
                }
                len=max(len, dp[i][j]);
            }
        }
        return len;
    }
};