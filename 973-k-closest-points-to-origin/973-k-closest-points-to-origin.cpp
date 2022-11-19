class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // so we need to the closest ones ie the points with min distance
        // so we use a min heap and not a max one that we used in all other previous question
        // as min heap orders ele in ascending order
        
        // declare min heap
        // heap stores: {distance, {x, y}}
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
        for(int i=0; i<points.size(); i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            double dis=sqrt(x*x+y*y);
            pq.push({dis, {x, y}});
        }
        vector<vector<int>> res;
        while(k!=0)
        {
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            res.push_back({x, y});
            k--;
        }
        return res;
    }
};
