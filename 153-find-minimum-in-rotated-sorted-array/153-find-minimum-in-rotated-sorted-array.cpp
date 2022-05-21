class Solution {
public:
    int findMin(vector<int>& nums) {
        // simple sol but n*logn
        // sort(nums.begin(), nums.end());
        // return nums[0];
        
        
        // now lets see logn
        // binary lagake dekhte kyuki thats an logn solution
        int left=0;
        int right=nums.size()-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            // agar mid-1 bada hogaya mid se matlab mid hi sabse chota
            if(mid>0 && nums[mid]<nums[mid-1])
            {
                return nums[mid];
            }
            // agar left chota hain mid se and right bhi chota hain mid se toh mujhe 
            else if(nums[left]<=nums[mid] && nums[mid]>nums[right])
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return nums[left];
    }
};
