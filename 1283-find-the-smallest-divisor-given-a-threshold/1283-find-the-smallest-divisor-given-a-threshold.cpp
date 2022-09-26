class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // so the max divisior that we can have is the largest ele in the array
        // beacause if we divide all ele by max ele in the array then the ans will be 1*size of arr
        // so now our search range is [1,max_ele_in_array]
        // if we increase the divisor value our sum decreases and vice versa
        // we can use binary search
        int left=1;
        int right=*max_element(nums.begin(), nums.end());
        while(left<=right)
        {
            int mid=(left+right)/2;
            int sum=0;
            for(int i=0; i<nums.size(); i++)
            {
                sum+=ceil((double)nums[i]/mid);
            }
            if(sum>threshold)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return left;
    }
};