/*
Daksh Paleria
dakshp07
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++)
    {
    	cin>>arr[i];
    }
    vector<ll> dp(n);
    dp[0] = 0;
    dp[1] = abs(arr[0] - arr[1]);
    
    for(int i=2; i<n; i++){
        dp[i] = min( abs(arr[i-2]-arr[i])+dp[i-2], abs(arr[i-1]-arr[i])+dp[i-1] );
    }
    
    cout<<dp[n-1];
}
