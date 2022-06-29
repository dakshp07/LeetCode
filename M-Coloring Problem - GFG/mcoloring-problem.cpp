// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(int node, int color[], bool graph[101][101], int N, int col)
{
    // check if adjacent nodes have same of diff colors
    for(int k=0; k<N; k++)
    {
        if(k!=node && graph[k][node]==1 && color[k]==col) // if any adjacent node got same color return false
        {
            return false;
        }
    }
    return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101])
{
    if(node==N) //if we get to last node means we have our ans
    {
        return true;
    }
    for(int i=1; i<=m; i++) // go through the colors
    {
        if(isSafe(node, color, graph, N, i)) // if we dont break any rule
        {
            // we now add the color for the node
            color[node]=i;
            if(solve(node+1, color, m, N, graph)) return true; // if our other recursive calls for other nodes return true
            color[node]=0; // backtrack if our color violated any rules
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N) {
    // again let try all possible ways
    // keep making recursive calls
    // again use a helper function to see if we follow rules
    // if we get any correct color, and all calls for this color are true we can then stop and return ans
    // if our helper function says false, we backtrack
    int color[N]={0}; // store colors of sepcific node
    if(solve(0, color, m, N, graph)) return true;
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends