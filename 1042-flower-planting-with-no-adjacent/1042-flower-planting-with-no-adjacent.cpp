class Solution {
public:
    void dfs(int garden, vector<int> adj[], vector<int> &res)
    {
        // now we visit all its adjacent nodes and color them
        // we also keep a check which color is already used
        vector<bool> color_used(5, 0); // 4 colors and starts from 1, so size is 5
        // first we check if this garden adjacent have colored or not
        // if they are colored then we cant use their color, so we mark all those color as used
        for(auto it: adj[garden]) color_used[res[it]]=1;
        // now we run through all possible 4 colors and see the one which is not used to color this garden
        for(int i=1; i<=4; i++)
        {
            if(!color_used[i])
            {
                res[garden]=i; // put the color in our res array
                break; // and break
            }
        }
        // now we visit all adj gardens of this garden
        for(auto it: adj[garden])
        {
            // if not visited we visit them
            if(!res[it])
            {
                dfs(it, adj, res);
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // so this is a graph question, since its mentioned about bideirectional paths etc
        // but we need an adj list so that i can know what are the gardens connected to ith garden
        // and then i run a dfs
        // i put one color on a garden and then visit its neighboring ones and put other colors
        vector<int> adj[n]; 
        for(int i=0; i<paths.size(); i++)
        {
            // its bidirectional so we push both sides
            adj[paths[i][0]-1].push_back(paths[i][1]-1); // as gardens start from 1 and not 0
            adj[paths[i][1]-1].push_back(paths[i][0]-1); // as gardens start from 1 and not 0
        }
        // now i know which garden is connected to what all gardens
        // ajd list is like:
        // 1->2,3,4
        // 2->3,4,...
        // now i run dfs over this adj list and try to put a color on them
        // we create vector to keep track of which garden is colored with what color but that happens inside the dfs function
        vector<int> res(n, 0);
        for(int i=0; i<n; i++)
        {
            // if garden is not visited ie its not colored we run a dfs over it
            if(res[i]==0)
            {
                dfs(i, adj, res);
            }
        }
        return res;
    }
};