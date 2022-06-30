class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // linear traverse karo and xor kar sakte to find non duplicate
        // extra memory use kar sakte to store freq of ele
        // instead we will use binary search to get the ans
        // so we have to look for the break point where our duplicates are no present
        // obs: right half of break point: 1st instance: odd index and 2nd instance: even index
        // left half of break pointL: 1st instace: even index and 2nd instance: odd index
        // low at starting and high at end-2 (ie last second)
        int low=0, high=nums.size()-2; // high sits at right half
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            // check index
            // considering we are at left half
            if(nums[mid]==nums[mid^1]) // check even odd index using xor
            // xor of odd with 1 gives an even just before it
            // xor of even with 1 gives an odd just before it
            {
                low=mid+1; // update boundary 
            }
            else
            {
                high=mid-1;
            }
        }
        return nums[low];
    }
};