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
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
    	cin>>arr[i];
    }
    vector<int> dp(n, INT_MAX);
    dp[0]=0;
    for(int i=0; i<n; i++)
    {
    	for(int j=1; j<=k; j++)
    	{
    		if(i+j<n)
    		{
    			dp[i+j]=min(dp[i+j], abs(arr[i]-arr[i+j])+dp[i]);
    		}
    	}
    }
    cout<<dp[n-1];
}
