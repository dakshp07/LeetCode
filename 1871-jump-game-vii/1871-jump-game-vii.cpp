class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<bool>dp(n,false);
        dp[0]=1;
        int prev=0;
        for(int i=1;i<n;i++)
        {
            if(i>=minJump)
            {
                prev+=dp[i-minJump];
            }
            if(i>maxJump)
            {
                prev-=dp[i-maxJump-1];
            }
            dp[i]=((s[i]=='0') and prev>0);
        }
        return dp[n-1];
    }
};