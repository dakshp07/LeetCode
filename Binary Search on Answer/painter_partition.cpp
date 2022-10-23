int mod = 1e7+3;
bool isPossibleToPaint(vector<long long> &C, long long mid, int painters){
    long long time = 0;
    long long painters_needed = 1;
    for(int i=0; i<C.size(); i++)
    {
        if(painters_needed>painters) return false;
        time+=C[i];
        if(time > mid)
        {
            painters_needed++;
            time = C[i];
        }
    }
    if(painters_needed <= painters) return true;
    return false;
}
int Solution::paint(int A, int B, vector<int> &D) {
    // we use bs on range of [max(C),total(C)]
    int n=D.size();
    vector<long long> C(n, 0);
    for(int i = 0; i < n; i++)
    {
        C[i]=(1LL*D[i]*B);
    }
    long long max_time = 0;
    long long total_time = 0;
    for(int i = 0; i < n; i++)
    {
        max_time=max(max_time, C[i]);
        total_time+= C[i];
    }
    // if there are more boards then painters we return sum of time
    if(A>n)
    {
        return max_time;
    }
    long long lo = max_time;
    long long hi = total_time;
    long long ans;
    while(lo<=hi){
        long long mid = lo + (hi - lo)/2;
        if(isPossibleToPaint(C, mid, A))
        {
            ans=mid;
            hi=mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans%mod;
}
