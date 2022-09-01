class Solution {
public:
    
    bool isMatch(string s, string p) {
        int m = p.length();
        int n = s.length();
        
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        
        // initialization of matrix
        int st = 0;
        while(st < m && p[st] == '*'){
            dp[++st][0] = true;
        }
            
        // filling up matrix
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                } 
                else if(p[i-1] == '*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }   
                else{
                    dp[i][j] = false;
                }   
            }
        }
        
        // ans
        return dp[m][n];
    }
};