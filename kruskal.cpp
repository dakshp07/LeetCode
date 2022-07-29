#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};
// comperator to sort acc to wt
bool comp(node a, node b) {
    return a.wt < b.wt; 
}
// disjoint set find parent func
int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; // we retun the parent if its there in parent arr 
    return parent[u] = findPar(parent[u], parent); // or use path compression to get parent
}
// find union of the disjoint set
void unionn(int u, int v, vector<int> &parent, vector<int> &rank) { 
    u = findPar(u, parent); // get parent of node 1
    v = findPar(v, parent); // get parent of node 2
    if(rank[u] < rank[v]) { // check the ranks
    	parent[u] = v; // we update if anyone's rank is bigger
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else { // if rank is same we increase the rank of anyone by +1
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	int N=5,m=6; // edges and nodes for the MST
	vector<node> edges; 
  // making the graph
	edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));
	sort(edges.begin(), edges.end(), comp); // sort acc to wt
	
	vector<int> parent(N); // get the parent for disjoint set
	for(int i = 0;i<N;i++) 
	    parent[i] = i; // intialize parent as self for all nodes
	vector<int> rank(N, 0); // intialize rank of all nodes as 0
	
	int cost = 0; // final MST cost
	vector<pair<int,int>> mst; // stores edges of MST
	for(auto it : edges) { // iterate over edge
	    if(findPar(it.v, parent) != findPar(it.u, parent)) { // if nodes are on diff components we add them in MST 
	        cost += it.wt; // add in cost
	        mst.push_back({it.u, it.v}); // push edge to final MST
	        unionn(it.u, it.v, parent, rank); // make them as union as they are now MST
	    }
	}
	cout << cost << endl; // output cost
	for(auto it : mst) cout << it.first << " - " << it.second << endl; // output the edges of MST
	return 0;
}
