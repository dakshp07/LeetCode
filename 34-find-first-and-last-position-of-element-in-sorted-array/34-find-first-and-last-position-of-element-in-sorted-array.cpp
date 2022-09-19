class Solution {
public:
    int bs_left(vector<int> &nums, int target)
    {
        int n=nums.size();
        int low=0, high=n-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            // we keep on looking to the left if our nums[mid]==target as we need first occurence
            if(nums[mid]==target)
            {
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
    int bs_right(vector<int> &nums, int target)
    {
        int n=nums.size();
        int low=0, high=n-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            // we keep on looking to the right if our nums[mid]==target as we need last occurence
            if(nums[mid]==target)
            {
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // ek toh hain ki sort and return the indexes. tc: O(n) and sc: O(1)
        // binary laga lo, to find the index. tc: O(log n) and sc: O(1)
        vector<int> ans(2, 0);
        ans[0]=bs_left(nums, target);
        ans[1]=bs_right(nums, target);
        return ans;
    }
};