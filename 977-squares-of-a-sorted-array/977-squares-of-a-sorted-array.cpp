class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // one way is to sort and then sqaure. tc: O(nlogn)
        // but we need to do in O(n) tc
        
        // we will use an extra res vector of same size
        // and put ele from behind in it through 2 pointers approach
        vector<int> res(nums.size());
        // left, right pointer and the curr pointer will be at end of res vector
        int left=0;
        int right=nums.size()-1;
        int curr=nums.size()-1;
        while(left<=right)
        {
            // if the abs value of ele at low is greater than abs val of ele at high
            // then we put low at end ie at curr position which starts from end
            if(abs(nums[left])>abs(nums[right]))
            {
                // put it in res
                res[curr]=nums[left]*nums[left];
                // decrement curr and increment left
                curr--;
                left++;
            }
            // in other case our ele at high will have a greater abs value
            else
            {
                // put it in res
                res[curr]=nums[right]*nums[right];
                // decrement curr and decrement right
                curr--;
                right--;
            }
        }
        return res;
    }
};