class Solution {
	bool find_ans(int node,vector<vector<int>>vec,vector<int> &vis){
		if(vis[node] == -1){
			vis[node] = 1;
		}


		for(auto it:vec[node]){
			if(vis[it] == -1){
				vis[it] = 1- vis[node];
				if(find_ans(it,vec,vis) == false){
					return false;
				}
			}else if(vis[node] == vis[it]){
				return false;
			}
		}
		return true;
	}
	bool find_bfs(vector<vector<int>>vec){

	vector<int> vis(vec.size(),-1);

	for(int i=0;i<vec.size();i++){
		if(vis[i] == -1){


			queue<int>q;
			q.push(i);
			vis[i] = 1;

			while(!q.empty()){
				int node = q.front();
				q.pop();

				for(auto it:vec[node]){
					if(vis[it] == -1){
						vis[it] = 1- vis[node];
						q.push(it);

					}else if(vis[it] == vis[node]){
						return false;
					}
				}
			}

		}
	}

return true;

}
public:
	bool isBipartite(vector<vector<int>>& graph) {
		if(find_bfs(graph)){
			return true;
		}

		return false;

	}
};

/*
DFS Solution
bool find(vector<vector<int>>vec){
		vector<int>vis(vec.size(),-1);

		for(int i=0;i<vec.size();i++){
			if(vis[i] == -1){
				if(find_ans(i,vec,vis) == false){
					return false;
				}
			}
		}
		return true;
	}
*/