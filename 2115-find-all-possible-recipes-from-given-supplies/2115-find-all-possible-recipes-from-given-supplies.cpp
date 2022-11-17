class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // this is a graph question
        // reason: since we can see there are multiple ingredients to make a recipe
        // and any receipe could be a ingredient for some other recipe
        // which makes it have a dependency, that points to node and directed graphs
        
        // we make a adj list first
        /*
        ingredients -> recipe
        yeast -> bread
        bread -> sandwich
        */
        unordered_map<string, vector<string>> adj;
        // now we use the concept of topo sort as it will help us in giving the correct ans
        // since there are multiple dependencies topo sort will solve them and give us correct ans
        // we use kahn's algo for topo sort 
        unordered_map<string, int> indegree;
        // as intially for all recipes the indegree is 0, we fill map with 0s
        // note: usually we use vector for indegree so we used vector<int> indegree(n, 0)
        // but since due to question requirement we are using map, we cant prefill a map
        // so we manually fill it with 0s
        for(int i=0; i<recipes.size(); i++)
        {
            indegree[recipes[i]]=0;
        }
        // we use a set to store supplies
        unordered_set<string> st;
        for(int i=0; i<supplies.size(); i++)
        {
            st.insert(supplies[i]);
        }
        for(int i=0; i<ingredients.size(); i++)
        {
            for(int j=0; j<ingredients[i].size(); j++)
            {
                // if the ingredient required to make a recipe is not in supplies then  
                // we need to make a directed edge from that ingredient to recipe
                if(st.find(ingredients[i][j])==st.end())
                {
                    /*
                    since each receipe depends on ingredient
                    v (ingredients) -> u (recipe)
                    so the direction in graph will be from ingredients to recipe
                    and hence indegree will of recipe
                    */
                    indegree[recipes[i]]++;
                    adj[ingredients[i][j]].push_back(recipes[i]);
                }
            }
        }
        vector<string> ans;
        queue<string> q;
        // as we do in kahn's algo, we push all nodes with 0 indegree into our queue
        for(auto it: indegree)
        {
            if(it.second==0)
            {
                q.push(it.first);
            }
        }
        // peform kahn's algo
        while(!q.empty())
        {
            string node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return ans;
    }
};