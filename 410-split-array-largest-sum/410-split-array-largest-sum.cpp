class Solution {
public:
    bool canSplit(int mid, vector<int>& nums, int k)
    {
        // now its a greedy algo
        // we add the nums[i] to current sum
        // if at any point current sum > mid then we say that from here we can get a new subarray
        // at the end of iteration if no of subarray we formed==k we return true else false
        int curr_sum=0;
        int subarray_cnt=0;
        for(int i=0; i<nums.size(); i++)
        {
            // add our ele to curr sum
            curr_sum+=nums[i];
            // if it exceed mid
            if(curr_sum>mid)
            {
                // we start a new subarray from here
                subarray_cnt++;
                // and curr sum becomes equal to nums[i] as thats the ele from where we start a new subarray
                curr_sum=nums[i];
            }
        }
        // now the total number of subarray is subarray_cnt+1 as we started the cnt from 0
        // so we retrun true if subarray_cnt+1<=k
        if(subarray_cnt+1<=k) return true;
        return false; // else return false
    }
    int splitArray(vector<int>& nums, int k) {
        // so the brute force method is to use recursion, backtracking
        // and generate all the possible subarrays and get the minimized largest sum
        // tc: O(n^2*k) as we run a nested for loop till the time we generate k subarrays
        
        // now lets think about the range our answer would lie
        // whats the min value of ans: it could be the largest ele in array
        // as that alone could be one subarray and it is the largest sum which is minimised as its alone (tough to understand, but read this twice)
        // and whats the max value of ans: it could be the sum of all ele in array
        // as a complete array could form a subarray
        // so ans lies within [max(nums), sum(nums)]
        // now we can apply binary search on this limit
        
        // for any mid, we can check if we can split nums in k subarrays such that the largest sum is mid. we write the check func to see that
        // tc: O(n) for check func and O(log sum(nums))
        int left=*max_element(nums.begin(), nums.end());
        int right=accumulate(nums.begin(), nums.end(), 0);
        int res=INT_MAX; // since we minise it, we intialize it with max
        while(left<=right)
        {
            int mid=(left+right)/2;
            // now we pass mid to checker func to see if it could be an ans
            if(canSplit(mid, nums, k))
            {
                // if we can split, then we update ans
                res=mid;
                // and keep on looking for more small ans ie right=mid-1
                right=mid-1;
            }
            // if we cant split we keep on looking for ans on right boundary
            // ie left=mid+1
            else
            {
                left=mid+1;
            }
        }
        return res;
    }
};