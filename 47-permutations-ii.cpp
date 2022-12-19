class Solution {
public:
    vector<vector<int>> ans;
    void func(vector<int>nums, int ind)
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
        sort(nums.begin()+ind, nums.end()); // sort
        // now we iterate and swap indexes
        for(int i=ind; i<n; i++)
        { 
            if((i==ind) || (i!=ind && nums[i]!=nums[i-1])) // duplicates are not included
            {
                swap(nums[i], nums[ind]);
                func(nums, ind+1);
                // backtrack
                swap(nums[i], nums[ind]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // one way is to use the same code as permutations i
        // and pass all numbers to a set and then return to make sure we get only uniques
        
        // but we sort and then use recursion
        // similar to what we did in subsets ii
        sort(nums.begin(), nums.end());
        func(nums, 0);
        return ans;
    }
};
