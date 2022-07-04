#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // one way is to merge all arrays into once and sort them, return
    // next way is to use a min heap to push all ele in it and return a vec
    // more efficent way is to use a min heap and keep track of ele, array number in our heap (i didnt understood this approach)
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<kArrays.size(); i++)
    {
    for(int j=0; j<kArrays[i].size(); j++)
    {
        pq.push(kArrays[i][j]);
    }
    }
    vector<int> res;
    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}
