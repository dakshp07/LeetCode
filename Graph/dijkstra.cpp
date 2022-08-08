// Dijikstra algo
void shortestPath(int V, vector<pair<int, int>>, int node)
{
    vector<int> dis(V, INT_MAX); // the visited array
    piority_queue<pair<int, int>> pq; // min heap to get discout
    dis[s]=0; // make source as visited with dis as 0
    q.push(make_pair(0, s)); // add node, dis in queue
    while(!pq.empty())
    {
        int dist=q.top().first; // top of pq ie distance
        int prev=q.top().second; // top of pq ie int
        q.pop(); // pop from the queue
        auto it=0;
        for(auto it: adj[prev]) // traverse the adj node
        {
            int next=it.first; // pick our new adj nodes of prev
            int nextDis=it.second;
            if(dis[next]>dis[prev]+nextDis) // see if we can update the path
            {
                // update the value of dis if the new path is much shorter
                dis[next]=dis[prev]+next;
                pq.push(make_pair(dis[next], next)); // and also put update one on min heap
            }
        }
    }
    for(auto it: dis) cout<<it<<endl;
}
