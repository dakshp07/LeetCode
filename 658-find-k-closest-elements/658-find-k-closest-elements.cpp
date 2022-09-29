class Solution {
public:
    struct cmp
    {
        bool operator()(const pair<int, int> a, const pair<int, int> b)
        {
            // if diff is same then we return the smallest num
            if(a.second==b.second)
            {
                return a.first>b.first;
            }
            // else we sort on basis of diff
            return a.second>b.second;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // so we need to return top k closest ele
        // if the diff is unique, then we sort on basis of diff
        // else we see the numbers
        // we can use a max_heap and probably use a cmp on it to sort
        // tc: O(n) for getting diff + O(log n) for insertion + O(nlogn) for sorting
        // in max_heap we store <num,diff>
        // we could have used vector of pairs as well, same implmentation just diff code
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        // fill max_heap with <num,diff>
        for(int i=0; i<arr.size(); i++)
        {
            pq.push({arr[i], abs(arr[i]-x)});
        }
        // now we iterate max_heap till k==0
        vector<int> ans;
        while(k!=0)
        {
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};