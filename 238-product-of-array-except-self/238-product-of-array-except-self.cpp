class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // we can use concept of prefix,suffix sum
        // instead of sum we have product here
        // left array stores product of all ele before nums[i]
        // right array stores product of all ele after nums[i]
        // tc: O(n+n) and sc: O(2*n) as we create two array (right, left)
        int n=nums.size();
        vector<int> right(n, 1), left(n, 1);
        // we fill left first
        // start from i=1 as at i=0 we dont have any ele before it
        for(int i=1; i<n; i++)
        {
            left[i]=nums[i-1]*left[i-1];
        }
        // we fill right next
        // start from i=n-2 as at i=n-1 we dont have any ele after it
        for(int i=n-2; i>=0; i--)
        {
            right[i]=nums[i+1]*right[i+1];
        }
        // now for any ith ele left[i] has prod of all ele before it
        // and right[i] has prod of all ele after it
        // so we multiply both for all i ele and return ans
        vector<int> res(n, 1);
        for(int i=0; i<n; i++)
        {
            res[i]=left[i]*right[i];
        }
        return res;
    }
};