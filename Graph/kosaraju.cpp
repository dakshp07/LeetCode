#include <iostream>

using namespace std;

void dfs(int node, stack<int> st, vector<int> &vis, vector<int> &adj[])
{
    // mark node as visited
    vis[node]=1;
    // visit the adj node
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it, st, vis, adj);
        }
    }
    // push the node to stack after we visited all its adj nodes
    st.push(node);
}

void revDFS(int node, vector<int> &vis, vector<int> &transpose[])
{
    // since its reverse, we print node first and then make recursive calls
    cout<<node<<" ";
    vis[node]=1;
    for(auto it: transpose[node])
    {
        if(!vis[it])
        {
            revDFS(it, vis, transpose);
        }
    }
}

int main()
{
    // there are mainly 3 steps in this algorithm
    // step 1: sort acc finishing time ie topo sort (DFS calls for left, right and push in stack as we return back to parent)
    // step 2: transpose the graph (ie reverse the edges direction)
    // step 3: peform DFS acc to finishing time
    
    // step 1
    stack<int> st; // to store topo sort
    vector<int> vis(n, 0);
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            dfs(i, st, vis, adj);
        }
    }
    
    // step 2
    vector<int> transpose[n];
    for(int i=0; i<n; i++)
    {
        vis[i]=0; // mark node as unvisited
        for(auto it: adj[node])
        {
            // make the nodes reverse their direction
            transpose[it].push_back(i);
        }
    }
    
    // step 3:
    while(!st.empty())
    {
        // we pick stack ele one by one
        int node=st.top();
        st.pop();
        if(!vis[node])
        {
            cout<<"SCC: ";
            // peform DFS acc to their finish time
            revDFS(node, vis, transpose);
            cout<<endl;
        }
    }
}
