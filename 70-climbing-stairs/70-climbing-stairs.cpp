// global array for memoization
// vector<int> dp(46, -1); // make a dp array and make all ele as -1
class Solution {
public:
    int climbStairs(int n) {
        /* so the ways are from ways(n-1) + ways(n-2) as he will either take 1 step which means
        he will have n-1 stairs left, if he takes 2 step then he will have n-1 steps
        
        which is like fibonacci
        lets write recursive, memoization and tabulation code
        */
        
        // recursion (tc: O(2^n) as we make a recursive tree of size n and call n-1 & n-2 which are the 2 options) (sc: O(n) stack space for recursion as height of tree is n)
        // if(n==0)
        // {
        //     return 0; // if n==0, 0 ways  
        // }
        // // if n==1, only 1 way
        // if(n==1)
        // {
        //     return 1;
        // }
        // // if n==2, only 2 ways (1+1, 2)
        // if(n==2)
        // {
        //     return 2;
        // }
        // return climbStairs(n-1)+climbStairs(n-2);
        
        // memoization (tc: O(n) for iteration) (sc: O(n)+O(n) one for recursion stack size and other n for array)
        // global vector
        // same base case as recursion
        // if(n==0)
        // {
        //     return 0; // if n==0, 0 ways  
        // }
        // // if n==1, only 1 way
        // if(n==1)
        // {
        //     return 1;
        // }
        // // if n==2, only 2 ways (1+1, 2)
        // if(n==2)
        // {
        //     return 2;
        // }
        // if(dp[n]!=-1) // means we have the ans
        // {
        //     return dp[n]; // we return
        // }
        // // else we keep on checking by calling recursion
        // return dp[n]=climbStairs(n-1)+climbStairs(n-2);
        
        // tabulation (tc: O(n) as we do one iteration till n) (sc: O(n) as we use just an array)
        // vector<int> dp(n+1);
        // // add base cases to our dp
        // dp[0]=0;
        // dp[1]=1;
        // dp[2]=2;
        // // iterate and store the value for the other steps
        // for(int i=3; i<=n; i++)
        // {
        //     dp[i]=dp[i-1]+dp[i-2]; // the return condition of our recursive, memozation code
        // }
        // return dp[n];
        
        // no space complexity (tc: O(n) as we do one iteration till n) (sc: O(n) as we use just an array)
        if(n<=2) return n;
        int prev1=1, prev2=2, curr=0;
        for(int i=3; i<=n; i++)
        {
            curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return curr;
    }
};
