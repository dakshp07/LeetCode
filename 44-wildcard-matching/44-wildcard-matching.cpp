class Solution {
public:
    bool CheckAllStar(string p,int i)
    {
        for(int ii=1; ii<=i; ii++)
        {
            if(p[ii-1]!='*') return false;
        }
        return true;
    }
    bool isMatch(string s, string p) {
        // for ? we can just check if its matching with some char or not
        // but for * we have to check all possibilties
        // from len 0 to 1,2,3....
        // so we use recursion and then optimise it further
        /*
        recursion:
        int func(int i, int j)
        {
            // base case:
            // 1. i and j both are exhausted
            if(i<0 && j<0) return true;
            // 2. if i is exhausted but j remains
            if(i<0 && j>=0) return false;
            // 3. if j gets exhausted but i remains
            // we check if the remaining item in i are stars or not
            if(j<0 && i>=0)
            {
                for(int ii=0; ii<=i; ii++)
                {
                    if(p[ii]!='*') return false;
                }
                return true;
            }

            // so either char at pos i,j match or not match
            // match:
            // 1. if s[i] and p[j] match, we move
            if(s[i]==p[j]) return func(i-1, j-1);
            // 2. if p has a ? in that place, again they match
            if(p[j]=='?') return func(i-1, j-1);

            // not match ie we have a * at j
            // 1. we consider * to represent 0 len
            if(p[j]=='*') return func(i, j-1);
            // 2. we consider * to be equal to char at ith and more
            if(p[j]=='*') return func(i-1, j);

            // now if s[i] and p[j] are both chars and not equal we return false
            return false;
        }

        memoization:
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int func(int i, int j)
        {
            if(dp[i][j]!=-1) return dp[i][j];
            // base case:
            // 1. i and j both are exhausted
            if(i<0 && j<0) return true;
            // 2. if i is exhausted but j remains
            if(i<0 && j>=0) return false;
            // 3. if j gets exhausted but i remains
            if(j<0 && i>=0)
            {
                for(int ii=0; ii<=i; ii++)
                {
                    if(p[ii]!='*') return false;
                }
                return true;
            }

            // so either char at pos i,j match or not match
            // match:
            // 1. if s[i] and p[j] match, we move
            if(s[i]==p[j]) return dp[i][j]=func(i-1, j-1);
            // 2. if p has a ? in that place, again they match
            if(p[j]=='?') return dp[i][j]=func(i-1, j-1);

            // not match ie we have a * at j
            // 1. we consider * to represent 0 len
            if(p[j]=='*') return dp[i][j]=func(i, j-1);
            // 2. we consider * to be equal to char at ith and more
            if(p[j]=='*') return dp[i][j]=func(i-1, j);

            // now if s[i] and p[j] are both chars and not equal we return false
            return dp[i][j]=false;
        }
        */
        // tabulation:
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // base case:
        // 1. i and j both are exhausted
        dp[0][0]=true;
        // other base case is handled in for loops
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                // base case:
                // 1. i and j both are exhausted
                if(i==0 && j==0) dp[i][j]=true;
                // 2. if i is exhausted but j remains
                if(j==0) dp[i][j]=false;
                // 3. if j gets exhausted but i remains
                // we check if the remaining item in i are stars or not
                if(i==0) dp[i][j]=CheckAllStar(p,j);
            }
        }
        // we shift index by -1 to handle -ve cases
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                // so either char at pos i,j match or not match
                // match:
                // 1. if s[i] and p[j] match, we move
                // 2. if p has a ? in that place, again they match
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j]=dp[i-1][j-1];

                // not match ie we have a * at j
                // 1. we consider * to represent 0 len
                // 2. we consider * to be equal to char at ith and more
                else if(p[j-1]=='*') dp[i][j]=dp[i][j-1] || dp[i-1][j];
                // now if s[i] and p[j] are both chars and not equal we return false
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};
