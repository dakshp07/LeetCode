class Solution {
public:
    void func(int ind, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &ans, int target)
    {
        if(target==0) // if we get our combination
        {
            ans.push_back(ds); // ds has the combination and we push it to ans
            return;
        }
        for(int i=ind; i<candidates.size(); i++) // loop the arr
        {
            if(i!=ind && candidates[i]==candidates[i-1]) continue; // no duplicates
            if(candidates[i]>target) break; // as the candidates are sorted
            // pick the ele
            ds.push_back(candidates[i]);
            func(i+1, candidates, ds, ans, target-candidates[i]); // as we pick we subtract from traget
            ds.pop_back(); // clear the ds for next recursive call
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // the standard approach will be similar to what we did in combination sum 1
        // in combination sum 1 we used to pick ith index till we want but here we have to go ahead to next index
        // we will also use hashset instead of vector in ans
        // this to make sure we skip duplicates
        // rest tc: O(2^n) for making subsets and O(k) where k is avg size of subsets
        // but now that k will be klogn because we put in set
        // therefore total tc: O(2^n*k*logn)
        // sc: O(k*x) where x is the no of combinations
        
        // lets make it effective
        // in initial stage i will have n-1 options with me, i can pick any of the n-1 indexes
        // lets say i pick index 0 then theres no meaning in picking an index j which has the same value of 0 ie arr[0]==arr[j] since that will ultimately form the same tree, i will go to next index where i cant get same value
        // so this helps in making the tree a little less sophisticated tree
        // tc: O(2^n) for subsets and putting in ds will take O(k). so total: O(2^n*k)
        // sc: O(k*x) where x is the no of combinations
        sort(candidates.begin(), candidates.end()); // to get duplicates in order
        vector<vector<int>> ans;
        vector<int> ds;
        func(0, candidates, ds, ans, target);
        return ans;
    }
};