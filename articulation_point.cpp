/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tim, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation)
{
    // we mark node as visited
    vis[node]=1;
    tim[node]=low[node]=timer++; // we mark timer for the intialize index and increment it for all other nodes
    int child=0; // to store no of children
    // we see adj nodes
    for(auto it: adj[node])
    {
        // if the current adj node is parent
        if(it==parent) continue; // we continue
        // if the ajdj node isnt visited
        if(!vis[it])
        {
            // recursively peform dfs on them to update their timer
            dfs(it, node, vis, tim, low, timer, adj, isArticulation);
            low[node]=min(low[node], low[it]); // update the lowest time of insertion by checking minimum of adj nodes
            if(low[it]>=tim[node] && parent!=-1) // formula/condtion for the edge to be a articulation point
            {
                // we will get some duplicates, so we store node in array to avoid duplicates
                isArticulation[node]=1;
            }
            child++; // if DFS is called for adj nodes, means those are its child
        }
        // if its already visisted
        else
        {
            low[node]=min(low[node], tim[it]); // we update the lowest time of insertion as its already visited
        }
    }
    // we check for the other necessary condition
    if(parent==-1 && child>1)
    {
        // we add the point if the parent is -1 but it has child
        isArticulation[node]=1;
    }
}
int main()
{
    // the concept is same as finding a bridge we just add one more condition
    // we make our graph here and also create a adj list for the same
    vector<int> tim(n, -1); // time of insertion array of n size where n is no of node
    vector<int> low(n, -1); // lowest time array
    vector<int> vis(n, 0); // visited array
    vector<int> isArticulation(n, 0); // it will store if the given node is an articulation node or not, as we need unique nodes 
    int timer=0; // starting time
    for(int i=0; i<n; i++) // iterate over all component
    {
        // if not visited already we run dfs
        if(!vis[i])
        {
            dfs(i, -1, vis, tim, low, timer, adj, isArticulation);
        }
    }
    // print the points
    for(int i=0; i<n; i++)
    {
        if(isArticulation[i]==1) cout<<i<<endl;
    }
}
