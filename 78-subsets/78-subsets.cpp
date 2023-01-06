class Solution {
public:
    void recursion(int ind, vector<int>& nums, vector<int> &ds, vector<vector<int>> &ans)
    {
        // base case:
        // when we reach the end of nums array
        if(ind==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        // if we pick next index
        ds.push_back(nums[ind]);
        // now we move to next index
        recursion(ind+1, nums, ds, ans);
        ds.pop_back(); // backtrack

        // if we dont pick next one
        recursion(ind+1, nums, ds, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // lets use recursion and backtracking
        vector<int> ds;
        vector<vector<int>> ans;
        recursion(0, nums, ds, ans);
        return ans;
    }
};
