class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // brute force is using 3 for loops
        // tc: O(n^3) and sc: O(1)
        
        // we can probably use the concept of LIS
        // the only change here is the size should be 3
        // but that will require us to create a dp array which is sc and we should do in O(1) sc
        
        // so we can keep two var i,j
        // i,j are the maximums and we track their value
        if(nums.size()<3) return false;
        int i=INT_MAX;
        int j=INT_MAX;
        for(int ind=0; ind<nums.size(); ind++)
        {
            // if we see a num which is <=i we update i with it
            if(nums[ind]<=i)
            {
                i=nums[ind];
            }
            // now if any num is <=j we update j
            else if(nums[ind]<=j)
            {
                j=nums[ind];
            }
            // now if any num is bigger than both i,j then it will be the third one
            // so triplet is i,j and nums[ind]
            // so we got out triplet and return true
            else return true;
        }
        return false; // if no triplet
    }
};