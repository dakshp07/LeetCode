class Solution {
public:
    struct comp
    {
        bool operator()(const pair<int, int> a, const pair<int, int> b)
        {
            if(a.first==b.first)
            {
                return a.second>b.second;
            }
            return a.first>b.first;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // we can use a heap to store <ele, diff> but as <diff, ele> so that the heap orders them accordingly
        // since two ele can have same diff we will use custom sort to check if same diff occurs then we sort acc to ele or else we order acc to diff;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        for(int i=0; i<arr.size(); i++)
        {
            int diff=abs(arr[i]-x);
            pq.push(make_pair(diff, arr[i]));
        }
        vector<int> res;
        while(k!=0)
        {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        sort(res.begin(), res.end());
        return res;
    }
};