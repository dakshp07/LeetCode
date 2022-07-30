#include <iostream>

using namespace std;

int main()
{
    // bellman ford algo is a shortest path algo
    // its also used to detect -ve wt cycle in an graph
    // we peform some relax operations for N-1 times, if the distance array values decreases after one more operation we retun that the graph has -ve wt cycle
    // we start from 0 as src
    int src=0;
    vector<int> dis(n, INT_MAX); // intialise the distance array with INT_MAX
    dis[src]=0; // as the src is starting point
    for(int i=1; i<=n-1; i++)
    {
        // we do relaxation for n-1 times
        for(auto it: edges)
        {
            // we update the dis acc to our formula
            if(dis[it.u]+it.wt<dis[it.v]) // u and v are the nodes who have an edge b/w them
            {
                dis[it.v]=dis[it.u]+it.wt; // update values in dis array
            }
        }
    }
    int fl=0;
    // we peform one more relaxation
    for(auto it: edges)
    {
        if(dis[it.u]+it.wt<dis[it.v]) // if the value still decreases
        {
            cout<<"Neagtive cycle"; // we say that we got a -ve cycle
            fl=1; // and update flag val
            break;
        }
    }
    if(!fl) // if no flag
    {
        for(int i=0; i<n; i++)
        {
            // cout the shortest path
            cout<<dis[i]<<" ";
        }
    }
}
