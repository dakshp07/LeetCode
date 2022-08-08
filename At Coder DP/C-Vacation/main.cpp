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
    vector<vector<ll>> arr(n, vector<ll>(3, 0));
    for(int i=0; i<n; i++)
    {
    	for(int j=0; j<3; j++)
    	{
    		cin>>arr[i][j];
    	}
    }
    vector<vector<ll>> dp(n, vector<ll>(3, 0));
    dp[0][0]=arr[0][0];
    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][2];
    for(int i=1; i<n; i++)
    {
    	dp[i][0]=arr[i][0]+max(dp[i-1][1], dp[i-1][2]);
    	dp[i][1]=arr[i][1]+max(dp[i-1][0], dp[i-1][2]);
    	dp[i][2]=arr[i][2]+max(dp[i-1][0], dp[i-1][1]);
    }
    cout<<max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}
