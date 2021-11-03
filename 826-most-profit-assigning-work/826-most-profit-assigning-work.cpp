class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        vector<pair<int,int>> jobs;
        
        for(int i=0; i<n; i++)
            jobs.push_back({profit[i], difficulty[i]});
        
        sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());      
        sort(worker.begin(), worker.end(), greater<int>());
        int i=0;
        int p = 0;
        for(auto w : worker){
            
            while(w<jobs[i].second and i<n)
                i++;
            
            if(i==n) break;
            
            p += jobs[i].first;
        }
        return p;
    }
};