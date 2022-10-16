class Solution {
public:
    void func(vector<int>& nums, int ind, vector<vector<int>> &ans)
    {
        int n=nums.size();
        // base case
        if(ind==n)
        {
            // we push nums to ans and return
            // as nums contains our ans
            ans.push_back(nums);
            return;
        }
        // now we iterate and swap indexes
        for(int i=ind; i<n; i++)
        {
            swap(nums[i], nums[ind]);
            func(nums, ind+1, ans);
            // backtrack
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // so a permutations happens when we swap two numbers
        // and from that we can generate a few more permutations
        // so we will do that and return the ans we get
        vector<vector<int>> ans;
        func(nums, 0, ans);
        return ans;
    }
};