class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // we use kadane but we use it from L to R
        // and then R to L
        // why? lets see through and eg:
        /*
        To understand this, lets take test case as [3,-1,4]. When we traverse from left to right, we will get ans as 3 whereas when we traverse from right to left, we will get ans as 4 which is the required ans. I hope this makes sense.
        */
        int n=nums.size();
        int ans=INT_MIN;
        int curr=1;
        for(int i=0; i<n; i++)
        {
            curr*=nums[i];
            ans=max(ans, curr);
            if(curr==0) curr=1;
        }
        curr=1;
        for(int i=n-1; i>=0; i--)
        {
            curr*=nums[i];
            ans=max(ans, curr);
            if(curr==0) curr=1;
        }
        return ans;
    }
};