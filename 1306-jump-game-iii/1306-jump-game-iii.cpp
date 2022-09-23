class Solution {
public:
    bool func(int ind, vector<bool>&vis, vector<int>&arr)
    {
        int n=arr.size();
        // base case
        // we return false if we go out of bounds or if we visit a index thats already visited
        if(ind>=n || ind<0) return false;
        // we also return false if we visit a index thats already visited
        if(vis[ind]) return false;
        if(arr[ind]==0) return true;
        // trying out possibilities
        vis[ind]=true; // mark the index as visited
        bool left=false;
        left=func(ind-arr[ind], vis, arr);
        bool right=false;
        right=func(ind+arr[ind], vis, arr);
        return (left || right);
    }
    bool canReach(vector<int>& arr, int start) {
        // we have two options, so we try both
        // but there are chances when we might be stuck in an infinite loop
        // that is if we are visiting the same index again and again
        // so we use visited array to make sure we dont visited previous indexes
        vector<bool> vis(arr.size(), false);
        return func(start, vis, arr);
    }
};
