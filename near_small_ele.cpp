vector<int> Solution::prevSmaller(vector<int> &A) {
    // one of the ways is to run a loop for every element to check
    // the other way is to use a stack
    int n=A.size();
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    // we will pop ele and put it in the ans if st.top is bigger than our curr arr ele
    for(int i=0; i<n; i++)
    {
        while(st.top()>=A[i])
        {
            st.pop();
        }
        ans[i]=st.top();
        st.push(A[i]);
    }
    return ans;
}
