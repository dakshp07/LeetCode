class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // sliding window lagao
        // starting ke k element ka sum dekho phir dekho ki aage ka le lu or peeche ka chor du
        int sum=accumulate(cardPoints.begin(), cardPoints.begin()+k, 0);
        int ans=sum;
        int j=cardPoints.size()-1;
        int i=k-1;
        while(i>=0)
        {
            sum-=cardPoints[i];
            sum+=cardPoints[j];
            ans=max(ans, sum);
            i--;
            j--;
        }
        return ans;
    }
};