class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      // binary search: tc: O(n*logn) and sc: O(n)
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=0; i<nums.size(); i++)
        {
            // if curr ele is greater than the last ele of temp array then we add it to temp as that can be a part of our lis
            if(nums[i]>temp.back())
            {
                temp.push_back(nums[i]);
            }
            // else we can apply an binary search to see where we can insert our new ele and start the new lis
            else
            {
                int ind=lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();
                // so at this index we will be able to replace the temp array ele
                temp[ind]=nums[i];
                
            }
        }
        // the lis length is stored in temp array size
        return temp.size();
    }
};
