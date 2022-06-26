class Solution {
public:
    void func(int ind, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &ans, int target)
    {
        if(ind==candidates.size()) // meaning we at last index
        {
            if(target==0)
            {
                ans.push_back(ds); // because ds has the combination
            }
            return; // go back to main function
        }
        // lets pick ele
        if(candidates[ind]<=target)
        {
            ds.push_back(candidates[ind]); // we add it in our ds
            // we will see if we can pick up same ele one more time or not
            func(ind, candidates, ds, ans, target-candidates[ind]);
            ds.pop_back(); // we need to empty the ds after every recursive call
        }
        // not pick
        func(ind+1, candidates, ds, ans, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // basiclly the question is to find the subsets that are having a sum equal to given sum
        // we can do this by finding all the subsets and then checking who are the ones having sum equal to the given target
        // tc: o(2^n) for finding subsets + O(2^n*k) for traversing the subsets and calculating their sum where k is avg size of one subset. total tc: O(2^n+(2^n+k))
        // sc: O(2^n) for storing all the subsets and then removing the ones which are not having sum==target which will reduce sc a lil bit but eventually we have to store all of them
        
        // so we will be picking an ele at index i and reducing the target by arr[i] and then continue and next we will see if we can pick that same ele at index i or not. we pick the same ele till the target gets less than arr[i]
        // we dont pick up we continue for for next ele
        // tc: O(2^n*k) so we have 2 options, pick or not so 2^n and k is avg size of every subset we are putting it in an data structure which takes O(k) time
        // sc: O(k*x) where x= no of combinations, which we cant predict
        vector<vector<int>> ans;
        vector<int> ds;
        func(0, candidates, ds, ans, target);
        return ans;
    }
};