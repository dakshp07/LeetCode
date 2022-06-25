class Solution {
public:
    // helper to see if array is increasing
    bool isIncreasing(vector<int> nums)
    {
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
    bool checkPossibility(vector<int>& nums) {
        // the idea is to find the point where we the order of increasing is disrupted
        // when we find any disruption point, there are two possibility
        // 1) change the right element to curr element
        // 2) change the curr element to right element
        // and then we check again for both the cases if we get an increasing array
        for(int i=0; i<nums.size()-1; i++)
        {
            // storing curr, right
            int curr=nums[i];
            int right=nums[i+1];
            if(nums[i]>nums[i+1])
            {
                // lets make curr equal to right
                nums[i]=right;
                // now checking if that made array as increasing
                if(isIncreasing(nums)) return true;
                else
                {
                    // making right ele equal to curr
                    // first restore value of curr
                    nums[i]=curr;
                    nums[i+1]=curr;
                    // return if its increasing
                    return isIncreasing(nums);
                }
            }
        }
        //If there was no need for change, we simply return true, coz our array wud have been already increasing
        return true;
    }
};