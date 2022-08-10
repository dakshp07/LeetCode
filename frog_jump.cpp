// Quesrion Link: https://www.codingninjas.com/codestudio/problems/frog-jump_3621012


int frogJump(int n, vector<int> &heights)
{
    // one solution is the recursion one
    // we try out all possible way
    /*
    
    // recursion tc: O(2^n) and sc: O(n) stack space
    int func(int ind)
    {
    if(ind==0) return 0; if we are at first index then the cost is 0
    lets take one step
    int left=func(ind-1)+abs(heights[ind-1]-heights[ind]); // energy spent is the abs diff
    lets take 2 step
    if(ind>1)
    {
        int right=func(ind-2)+abs(heights[ind-2]-heights[ind]);
    }
    return min(left, right);
    }
    tree: 
                                    f(5)
                                    /  \
                                  f(4) f(3)
                                  /  \
                                f(3) f(2)
     we have some overlapping problem
     
     // lets see memoization
     // memoization tc: O(n) and sc: O(n) for array + O(n) for stack space
     vector<int> dp(n+1, -1);
     int func(int ind)
     {
     if(ind==0) return 0;
     if(dp[ind]!=-1) return dp[n];
     int left=func(ind-1)+abs(heights[ind-1]-heights[ind]); // energy spent is the abs diff
    lets take 2 step
    if(ind>1)
    {
        int right=func(ind-2)+abs(heights[ind-2]-heights[ind]);
    }
    return dp[n]=min(left, right);
     }
    */
    // tabulation tc: O(n) and sc: O(n)
    vector<int> dp(n, 0);
    // base conditions
    dp[0]=0;
    // lets set for 1 step
    for(int i=1; i<n-1; i++)
    {
        int step2=INT_MAX; // to make sure we pick minimum out of step1, step2
        int step1=dp[i-1]+abs(heights[i-1]-heights[i]);
        // lets set for 2 step
        if(i>1)
        {
            step2=dp[i-2]+abs(heights[i-2]-heights[i]);
        }
        dp[i]=min(step1, step2);
    }
    return dp[n-1];
    /*
    lets see if we optmize the space tc: O(n) and sc: O(1)
    we store the i-1 and i-2 in prev1 and prev2 and update them
    int prev1=0, prev2=0;
    for(int i=1; i<n; i++)
    {
        int jtwo=INT_MAX;
        int jone=prev1+abs(heights[i-1]-heights[i]);
        if(i>1) jtwo=prev2+abs(heights[i-2]-heights[i]);
        int curr=min(prev1, prev2);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
    */
}
