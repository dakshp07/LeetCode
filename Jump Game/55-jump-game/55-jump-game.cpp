class Solution {
public:
    bool canJump(vector<int>& nums) {
        // we will calculate the max index that we can reach from any index i
        // if at the end we were able to reach the size of array -1 then we are good to go
        int reachable=0;
        for(int i=0; i<nums.size(); i++)
        {
            // now every arr[i] tell us the max no of steps that we can take
            // we start from index 0, so max step we can take from here is 0+arr[0]
            
            if(reachable<i) return false; // because we cant even reach next index
            // we just pick max of the value
            reachable=max(reachable, i+nums[i]);
        }
        // if our reachable==last index we return true else we return false
        return true;
    }
};