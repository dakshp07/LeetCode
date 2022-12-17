class Solution {
public:
    void func(int curr_num, int n, int capacity, vector<int> &ds, vector<vector<int>> &ans)
    {
        // base case:
        // 1. if we have picked up capacity numbers
        if(ds.size()==capacity) 
        {
            ans.push_back(ds);
            return;
        }
        // 2. if curr_num>n, we return as we can at max go to n
        if(curr_num>n) return;
        // now we either pick this number and move to next one
        ds.push_back(curr_num);
        func(curr_num+1, n, capacity, ds, ans);
        // if we dont pick then we just move to next ele
        ds.pop_back(); // backtracking
        func(curr_num+1, n, capacity, ds, ans);
    }
    vector<vector<int>> combine(int n, int k) {
        // its a pure recursion question
        // where we can either pick or not pick the element
        vector<int> ds;
        vector<vector<int>> ans;
        func(1, n, k, ds, ans);
        return ans;
    }
};
