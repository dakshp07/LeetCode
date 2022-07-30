#include <iostream>

using namespace std;
void dfs(int node, vector<int> &vis, vector<int> &tim, vector<int> &low, int &timer, vector<int> adj[])
{
    // we mark node as visited
    vis[node]=1;
    tim[node]=low[node]=timer++; // we mark timer for the intialize index and increment it for all other nodes
    // we see adj nodes
    for(auto it: adj[node])
    {
        // if the ajdj node isnt visited
        if(!vis[it])
        {
            // recursively peform dfs on them to update their timer
            dfs(it, vis, tim, low, timer, adj);
            low[node]=min(low[node], low[it]); // update the lowest time of insertion by checking minimum of adj nodes
            if(low[it]>low[node]) // formula/condtion for the edge to be a bridge
            {
                // cout as this is our bridge
                cout<<node<<" "<<endl;
            }
        }
        // if its already visisted
        else
        {
            low[node]=min(low[node], tim[it]); // we update the lowest time of insertion as its already visited
        }
    }
}
int main()
{
    // we make our graph here and also create a adj list for the same
    vector<int> tim(n, -1); // time of insertion array of n size where n is no of node
    vector<int> low(n, -1); // lowest time array
    vector<int> vis(n, 0); // visited array
    int timer=0; // starting time
    for(int i=0; i<n; i++) // iterate over all component
    {
        // if not visited already we run dfs
        if(!vis[i])
        {
            dfs(i, -1, vis, tim, low, timer, adj);
        }
    }
    
}
