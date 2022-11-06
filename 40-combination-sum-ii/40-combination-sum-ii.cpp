class Solution {
public:
    void func(int ind, vector<int>& candidates, int target, vector<int>&ds, vector<vector<int>>&ans)
    {
        int n=candidates.size();
        // base case:
        // if i reach end and my target==0 we push the ds to ans and return
        if(ind==n)
        {
            if(target==0) ans.push_back(ds);
            return;
        }
        // if my target is <0 i return
        if(target<0) return;
        // pick the ele
        // if we pick we move to ind+1, with a target of target-candidates[ind]
        ds.push_back(candidates[ind]);
        func(ind+1, candidates, target-candidates[ind], ds, ans);
        // while our calls comes back we pop ds
        ds.pop_back();
        // not pick ele
        // we skip duplicates
        while(ind+1<n && candidates[ind]==candidates[ind+1]) ++ind;
        func(ind+1, candidates, target, ds, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // so at any index i have two options either to pick or not
        // so we go both ways
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        func(0, candidates, target, ds, ans);
        return ans;
    }
};