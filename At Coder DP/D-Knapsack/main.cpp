/*
Daksh Paleria
dakshp07
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
int w[100];
int v[100];
ll dp[100][100001];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,W;
	cin>>n>>W;
	
	for(int i=0;i<n;i++){
		cin>>w[i]>>v[i];
	}
	
	dp[0][0] = 0;
	dp[0][w[0]] = v[0];
	
	for(int id=1;id<n;id++){
		dp[id][0] = 0;
		for(int j=1;j<=W;j++){
			
			// Discard current object
			dp[id][j] = dp[id-1][j];
			
			// Pick current object
			if(j >= w[id])
				dp[id][j] = max(dp[id][j], v[id] + dp[id-1][j-w[id]]);
			
		}
	}
	
	ll answer = LLONG_MIN;
	
	for(int j = 0; j <= W;j++){
		answer = max(answer, dp[n-1][j]);
	}
	
	cout<<answer;
	
	return 0;
}
