class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // so what we can do is we can keep two pointers and see if arr[i]==arr[i+1]
        // if they are equal we then change there value with arr[j]
        int i=0;
        for(int j=1; j<nums.size(); j++)
        {
            // if arr[i]!=arr[j] we keep moving
            if(nums[i]!=nums[j])
            {
                i++;
            }
            nums[i]=nums[j];
        }
        return i+1;
    }
};