class Solution {
public:
    void func(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        if(index==nums.size()) // means we are at last index
        {
            // we got our permutation
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++)
        {
            swap(nums[i], nums[index]); // swap with other index
            // call recursively for other index
            func(index+1, nums, ans);
            // swap back to original places
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // one of the ways is to generate all permuations and store them using extra memory
        // total no of permutations for arr of size n, will be n!
        // we can start picking one number and then add them up in data structure
        // we do this process recursively
        // tc: O(n!) for permuations and O(n) for one traversal. so total tc: O(n!*n)
        // sc: O(n) for data structure and O(n) for using a map
        
        // now we will remove extra states by using the swap method intelligently
        // we pick one number from arr and build our tree by iterating over other element
        // tc: O(n!*n)
        // sc: O(1) because we aint using any extra space, only space is for return
        vector<vector<int>> ans;
        func(0, nums, ans);
        return ans;
    }
};