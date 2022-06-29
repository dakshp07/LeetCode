// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis)
    {
        if(i==n-1 && j==n-1) // means we are at last index ie our destination
        {
            // we have the ans in move string and we will push it to vector
            ans.push_back(move);
            return;
        }
        // downward vists
        if(i+1<n && !vis[i+1][j] && a[i+1][j]==1) // check if we can really go down
        {
            vis[i][j]=1; // mark the cell as visited
            solve(i+1, j, a, n, ans, move+'D', vis); // make recursive call in next downward
            vis[i][j]=0; // backtrack to make the vis 0
        }
        // left
        if(j-1>=0 && !vis[i][j-1] && a[i][j-1]==1) // check if we can really go left
        {
            vis[i][j]=1; // mark the cell as visited
            solve(i, j-1, a, n, ans, move+'L', vis); // make recursive call in next left
            vis[i][j]=0; // backtrack to make the vis 0
        }
        // right
        if(j+1<n && !vis[i][j+1] && a[i][j+1]==1) // check if we can really go right
        {
            vis[i][j]=1; // mark the cell as visited
            solve(i, j+1, a, n, ans, move+'R', vis); // make recursive call in next right
            vis[i][j]=0; // backtrack to make the vis 0
        }
        // upwards
        if(i-1>=0 && !vis[i-1][j] && a[i-1][j]==1) // check if we can really go upwards
        {
            vis[i][j]=1; // mark the cell as visited
            solve(i-1, j, a, n, ans, move+'U', vis); // make recursive call in next upwards
            vis[i][j]=0; // backtrack to make the vis 0
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // very much similar to n queens
        // check if it can go or else backtrack your previous calls
        // again take all the possible ways
        // see if are vioating any rules
        // if violation then backtrack
        // note: we follow lexi order of way ie D, L, R, U in order to make sure that our ans are in lexi order too
        // we will also keep visited array to mark visited nodes as there's no meaning in viisting them again (up, down loops)
        // tc:O(4^(n*m)) as we have four options for every cell (D, L, R, U) and sc: O(n*m)
        vector<string> ans; // holds our ans strings
        vector<vector<int>> vis(n, vector<int>(n, 0)); // visited arr to keep track of visited cells
        if(m[0][0]==1) solve(0, 0, m, n, ans, "", vis); // recursive func
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends