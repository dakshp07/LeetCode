vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    // brute force could be to get all the sum combinations and push them in a heap
    // and return the top k sums
    // tc: O(n*2) and sc: O(n)
    
    // other idea is to sort the array and put max sum in heap ie A[n-1]+B[n-1] along with their indices
    // and then pop the max sum and go to next set of elements from behind and we will use set to make sure there is no duplicates
    int n=A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // heap
    priority_queue<pair<int, pair<int, int>>> pq; // to store the max sum combinations
    // set to make sure that we get rid of duplicates
    set<pair<int, int>> st;
    
    // intialize heap with max sum
    pq.push(make_pair(A[n-1]+B[n-1], make_pair(n-1, n-1)));
    
    // add max sum indices to set
    st.insert(make_pair(n-1, n-1));
    
    vector<int> res;
    
    // now we iterate our C
    while(C>0)
    {
        // store the heap root temp
        pair<int, pair<int, int>> top=pq.top();
        // pop the top
        pq.pop();
        // gettting the values
        int sum=top.first;
        int x=top.second.first;
        int y=top.second.second;
        // push root sum ie max sum
        res.push_back(sum);
        // next max sum combination can be formed by ele at x-1, y or x, y-1
        // we check if x-1, y is in set
        if(st.find(make_pair(x-1, y))==st.end())
        {
            // if not in set we push them to heap and add indices to set
            pq.push(make_pair(A[x-1]+B[y], make_pair(x-1, y)));
            st.insert(make_pair(x-1, y));
        }
        
        // we check if x, y-1 is in set
        if(st.find(make_pair(x, y-1))==st.end())
        {
            // if not in set we push them to heap and add indices to set
            pq.push(make_pair(A[x]+B[y-1], make_pair(x, y-1)));
            st.insert(make_pair(x, y-1));
        }
        // reduce C
        C--;
    }
    return res;
}
