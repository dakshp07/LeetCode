class Solution {
public:
    int uniquePaths(int m, int n) {
        // ek toh hain ki brute force karo
        // recursively try hands around by going down and going right
        // the answer to both will add up to give final ans
        // tc will be exponantial, its recursion
        // dp ka use karlo or todhe states save karo while recursion, n*m ki tc or n*m ka sc
        // todha or optimise kar paayege if we use PnC
        // video dekho striver ka for approach
        int total=n+m-2;
        int r=m-1;
        double res=1;
        for(int i=1; i<=r; i++)
        {
            res=res*(total-r+i)/i;
        }
        return res;
    }
};