class Solution {
public:
   
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // we make an adj matrix from manager array
        // then peform a BFS with the time stored to check how much time it takes to inform all adj nodes ie employees
        vector<vector<int>>adj(n);
        int head = 0;
        for(int i=0;i<n;i++){
            if(manager[i]==-1){
                head=i;
            }else{
                adj[manager[i]].push_back(i); // make adj list
            }
        }
        // BFS
        queue<pair<int,int>>q;
        q.push({head,0}); // time taken by root is 0
        int ans =0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int emp=node.first;
            int time=node.second;
            ans=max(ans,time); // take max ans
            for(auto it:adj[emp])
            { 
                // visit adj nodes
                q.push({it,time+informTime[emp]});
            }
        }
        return ans;
    }
};