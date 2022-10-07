class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& v, int src, int dest) 
    {
        // so since this is an unweighted, undirected graph
        // a simple bfs will work here, we could have used djikstra
        // but the weights are constant so we use bfs which is lil bit modified
        
        // we have routes array where
        /*
        routes[i]={} shows the ith bus can go to which stops
        but for our bfs we need the relation of bus stops and buses which goes to those stops
        ith bus stop={} bus no
        eg: routes[0] = [1, 5, 7]
        we need where all stops does 1,5,7 go
        1: {}
        5: {}
        7: {}
        */
        // so we create that using a hashmap
        map<int,vector<int>>mpp;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                mpp[v[i][j]].push_back(i);
            }
        }
        // now we do bfs and we do +1 to cost everytime we come across the stops where buses can go
        queue<int>q;
        q.push(src);
        // now we keep two seen arrays one for bus stop and other for bus no
        unordered_map<int,int>vis;
        unordered_map<int,int>vis1;
        vis[src]++; // as we start from src
        int level=0;
        while(q.size()>0){
            int size=q.size();
            while(size--){
                auto ele=q.front();
                q.pop();
                if(ele==dest){
                    return level;
                }
                for(auto x:mpp[ele]){
                    if(vis1.find(x)==vis1.end())
                    {
                        for(int i=0;i<v[x].size();i++)
                        {
                            if(vis.find(v[x][i])==vis.end())
                            {
                                q.push(v[x][i]);
                                vis[v[x][i]]++;
                            }
                        }
                        vis1[x]++;
                    }
                }
            }
            level++;
        }
        return -1;
        
    }
};
