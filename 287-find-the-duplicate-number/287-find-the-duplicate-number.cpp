class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // kaafi methods hain
        // 1) sort karke next waale check karo (violates)
        // 2) set main seen store karo (violates)
        // 3) map main freq lagao (violates)
        // can't do any of the above kyuki that violates
        
        // tortoise-hare lagao
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(slow!=fast);
        fast=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};