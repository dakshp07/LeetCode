class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // whenever we see top k and all those type questions
        // we use heap in those cases, here we will use min heap
        // as it orders the ele from min to max
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
        // i will store distance, both ele in my min heap
        // distance will come first as we need ordering on its basis
        for(int i=0; i<points.size(); i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            double dis=sqrt(x*x+y*y);
            pq.push({dis, {x, y}});
        }
        vector<vector<int>> ans;
        while(k!=0)
        {
            auto it=pq.top();
            pq.pop();
            ans.push_back({it.second.first, it.second.second});
            k--;
        }
        return ans;
    }
};
