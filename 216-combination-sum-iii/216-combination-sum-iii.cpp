class Solution {
public:
    vector<vector<int>> ans;
    void recursion(int ind, vector<int> &arr, int k, int target, vector<int> &ds)
    {
        // we write base case
        if(target==0 && ds.size()==k)
        {
            ans.push_back(ds);
            return;
        }
        // now we check all the combinations from our arr array
        for(int i=ind; i<9; i++)
        {
            // since our arr is sorted we break if arr[i]>target
            if(arr[i]>target) break;
            ds.push_back(arr[i]); // else we push it onto ds
            // now we go recursively to other values
            recursion(i+1, arr, k, target-arr[i], ds);
            // we backtrack
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr={1,2,3,4,5,6,7,8,9};
        // so we need to recursively call
        vector<int> ds;
        recursion(0, arr, k, n, ds);
        return ans;
    }
};