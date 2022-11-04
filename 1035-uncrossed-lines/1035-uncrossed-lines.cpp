class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // similar to lcs
        // so if the chars match ie nums1[i]==nums2[j]
        // we move further in both strings as we cannot intersect
        // but what if chars dont match, we can move any one of them
        // eg: 1 4 2 and 1 2 4, so 1,1 match we move to 4,2 they dont match
        // so i can move ahead in nums1 or in nums2, any of the one will give me a max ans
        // so we need to explore both possibilties, hence recursion
        /*
        recursion: we start from last and reach till start
        tc: O(2^n*2^m) and sc: O(len of line)
        int func(int i, int j)
        {
        // base case:
        // out of bound is possible ie i<0 ot j<0
        if(i<0 || j<0) return 0;
        // now check possibilities
        if(num1[i]==num2[j])
        {
        // we move both 
        return 1+func(i-1, j-1);
        }
        // if they dont move we move one by one and take max
        else
        {
        return 0+max(1+func(i-1, j), 1+func(i, j-1));
        }
        }
        
        memoization: tc: O(n*m) and sc: O(len of line) + O(n*m) for dp array
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int func(int i, int j)
        {
        if(dp[i][j]!=-1) return dp[i][j]
        // base case:
        // out of bound is possible ie i<0 ot j<0
        if(i<0 || j<0) return 0;
        int ans=0;
        // now check possibilities
        if(num1[i]==num2[j])
        {
        // we move both 
        return dp[i][j]=1+func(i-1, j-1);
        }
        // if they dont move we move one by one and take max
        else
        {
        return dp[i][j]=0+max(func(i-1, j), func(i, j-1));
        }
        }
        */
        // tabulation: tc: O(n*m) and sc: O(n*m) for dp array
        // since our base case is of i<0 or j<0 we move all index by one to fit the base case
        // as array cannot have <0 indexes
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // base case:
        // now the base case is of i==0 and j==0, since our dp is filled with 0s
        // we dont follow the base case explicitly
        // for loops
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                // now check possibilities
                if(nums1[i-1]==nums2[j-1])
                {
                    // we move both 
                    dp[i][j]=1+dp[i-1][j-1];
                }
                // if they dont move we move one by one and take max
                else
                {
                    dp[i][j]=0+max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // our destination is to reach end of array in both, so our ans will be stored there
        return dp[n][m];
    }
};