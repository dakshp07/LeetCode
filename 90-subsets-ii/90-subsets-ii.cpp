class Solution {
public:
    void findSubs(int ind, vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans)
    {
        ans.push_back(ds); // first subset will be empty, and in next recursive call we will put the value in ds to our ans
        for(int i=ind; i<nums.size(); i++) // traverse through nums
        {
            if(i!=ind && nums[i]==nums[i-1]) continue; // duplicates are not included
            ds.push_back(nums[i]); // pick the ele
            findSubs(i+1, ds, nums, ans); // continue picking for next ele
            ds.pop_back(); // we need to pop back since ds should be empty before next recursive call
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // brute force is to find all subsets recursively in O(2^n) time
        // and then put them all in a set and convert the set into vectors of vectors
        // this method will not give tle since the constraints are small
        // but we will optimse this by using normal recursion calls
        // but the recursion will be an intelligent one
        // tc: O(2^n*n) (2^n for recursion and n for putting the subset in data structure) and sc: O(2^n)*O(k) (we will be having 2^n subsets, and avg length of each subset will be k)
        // auxilary space will be the depth of recursion tree ie n. so aux space: O(n)
        vector<vector<int>> ans; // store final ans
        vector<int> ds; // for intial computations
        sort(nums.begin(), nums.end()); // sort to remove duplicates easily
        findSubs(0, ds, nums, ans); // starting at 0
        return ans;
    }
};


// CODE2: APPROACH: 2
class Solution {
public:
    void recursion(int ind, vector<int>& nums, vector<int> &ds, vector<vector<int>> &ans)
    {
        if(ind==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        recursion(ind+1, nums, ds, ans);
        while(ind+1<nums.size() && nums[ind]==nums[ind+1] ) ind++;
        ds.pop_back();

        recursion(ind+1, nums, ds, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // so here we have duplicates with us
        // we can encounter this by sorting the nums
        // and skipping over the duplicates
        sort(nums.begin(), nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        recursion(0, nums, ds, ans);
        return ans;
    }
};
