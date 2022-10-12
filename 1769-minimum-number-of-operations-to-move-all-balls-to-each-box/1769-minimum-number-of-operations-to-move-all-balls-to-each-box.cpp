class Solution {
public:
    vector<int> minOperations(string boxes) {
        // brute is to check for every ith index and run a nested for loop for j
        // and check if abs(j-i)==1 and increment cnt
        // tc: O(n^2)
        
        // instead we can do two traversal, we use concept of prefix sums
        // prefix of all left balls and prefix of all right balls
        // if we store them on fly we can solve in O(n)
        // one from L-R and other from R-L
        // left[i]=0 but for any ith index we see how many balls we already had before
        // and how many balls we have at this index
        // ie left[i]=left[i-1]+boxes[i];
        // in similar fashion right[n-1]=0
        // and right[i]=right[i+1]+boxes[i]
        // our main ans will be ans[i]=left[i]+right[i]
        // tc: O(2*n)
        int n=boxes.size();
        vector<int> left(n), right(n);
        // left contains all the no of balls that we saw till now while going L-R
        // and right contains all the no of balls we have seen till now while going R-L
        // so for any ith ele left, right will tell how many balls are there before, after them
        left[0]=0;
        // since at 0 ele you will atleast have boxes[0] balls to cover
        int cnt=boxes[0]-'0';
        for(int i=1; i<n; i++)
        {
            left[i]=left[i-1]+cnt;
            // add the new balls to the cnt
            cnt+=boxes[i]-'0';
        }
        right[n-1]=0;
        // since at n-1 ele you will atleast have boxes[n-1] balls to cove
        cnt=boxes[n-1]-'0';
        for(int i=n-2; i>=0; i--)
        {
            right[i]=right[i+1]+cnt;
            // add the new balls to the cnt
            cnt+=boxes[i]-'0';
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            ans[i]=left[i]+right[i];
        }
        return ans;
    }
};