long double power(long double mid, int n){
    long double ans = 1.0;
    while(n--)
        ans *= mid;
    return ans;
}

long double findNthRootOfM(int n, long long m) {
    // we can apply binary search here 
    // as the values are monotically increasing in nature 
    // our range will be 1 to m 
    // tc: O(nlogn)
    long double low = 1.0, high = (long double)m, eps = 1e-9;
    while((high-low)>eps){
        long double mid = (high-low)/2.0 + low;
        if(power(mid,n)>(long double)m)
            high = mid;
        else
            low = mid;
    }
    return low;
}
