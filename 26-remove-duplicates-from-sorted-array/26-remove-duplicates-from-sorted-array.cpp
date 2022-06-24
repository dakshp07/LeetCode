class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // one of the ways could be to use some extra space and store stuffs in set
        // above sol uses extra space, not possible
        // the other could be to do it in place
        // optimal is to use 2 pointer:
        int i=0;
        for(int j=1; j<nums.size(); j++)
        {
            if(nums[i]!=nums[j]) // if they are diff
            {
                // increment i to next
                i++;
                nums[i]=nums[j]; // change the value of nums at j to nums at i
            }
        }
        return i+1;
    }
};