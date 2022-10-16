class Solution {
public:
    void func(int ind, vector<int>& candidates, int target, vector<int> &ds, vector<vector<int>> &ans)
    {
        int n=candidates.size();
        // base case:
        if(ind==n) return;
        if(target<0) return;
        // if our target is 0 that means we are done with our computation
        // so we push ds to our ans vector and return
        if(target==0) 
        {
            ans.push_back(ds); 
            return;
        }
        // now we have 2 options
        // op 1: pick candidates[ind] and look for target-candidates[ind] and move to ind
        // as we can pick any candidate multiple times
        // or op 2: dont pick candidates[ind] and look for target and move to ind+1
        
        // pick
        ds.push_back(candidates[ind]);
        func(ind, candidates, target-candidates[ind], ds, ans);
        // while coming back to our previous call, we pop back
        ds.pop_back();
        
        // not pick
        func(ind+1, candidates, target, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // so in order to return all the combinations we need to consider all possibilities
        // we explore all possibilities by using recursion
        vector<int> ds;
        vector<vector<int>> ans;
        func(0, candidates, target, ds, ans);
        return ans;
    }
};