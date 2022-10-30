class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // brute force will be three nested loops
        // we will also use set to make sure only unique sol comes in
        // tc for loops O(n^3) and O(log m) (m is the no of unique sets) for inserting in set
        // other optimal approach would be store one of the values in set and run 2 loops for checking the other two values
        // we will also check the values in set if they have occured previosuly we gonna ignore them
        // now this will be of tc O(n^2) and O(log m)
        // more optimal: 2 pointer approach. Sort them, a+b+c=0 is what we need. Lets make it b+c=-a;
        // so iterate the whole arry considering each element as a and then making it -a to find b+c such that they become equal to -a;
        // and then make left=pos[a]+1 and right at extreme right and use 2 pointer approach
        // we just skip left, right till we find a unique element
        // tc: O(n*n) (one n for a, one n for 2 pointer approach)
        // sc: O(m) where m is unique sets. But thats for return, usually not counted in sc
        // therefore sc: O(1)
        sort(nums.begin(), nums.end()); // sort to use 2 pointer
        vector<vector<int>> ans;
        for(int i=0; i<(int)nums.size()-2; i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1])) // to remove duplicates of i
            {
                int left=i+1;
                int right=nums.size()-1;
                // so nums[left]+nums[right]+nums[i]=0
                // now we need to change boundaries of left,right
                // so we need to look for nums[left]+nums[right]=-nums[i]
                int target=-1*nums[i];
                while(left<right)
                {
                    if(nums[left]+nums[right]==target)
                    {
                        vector<int> sum;
                        sum.push_back(nums[left]);
                        sum.push_back(nums[right]);
                        sum.push_back(nums[i]);
                        ans.push_back(sum);
                        // if we have dupliactes
                        // we skip left till we get unique
                        while(left<right && nums[left]==nums[left+1]) left++;
                        // we skip right till we get unique
                        while(left<right && nums[right]==nums[right-1]) right--;
                        // update left and right to find more triplets
                        left++;
                        right--;
                    }
                    else if(nums[left]+nums[right]>target) right--;
                    else left++;
                }
            }
        }
        return ans;
    }
};