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
    string s, t;
    cin>>s>>t;
    vector<vector<ll>> dp(3000, vector<ll>(3000));
    // dp[x][y] = s waali string ke x index pe hain, t string ke y index pe hain

    vector<vector<ll>> choice(3000, vector<ll>(3000));
    // 0->(i-1, j), 1->(i, j-1), 2->pick and goto (i-1, j-1)

    dp[0][0]=0;
    if(s[0]==t[0])
    {
    	dp[0][0]=1;
    	choice[0][0]=2;
    }
    for(ll i=0; i<s.length(); i++)
    {
    	for(ll j=0; j<t.length(); j++)
    	{
    		//not pick
    		if(i>0)
    		{
    			dp[i][j]=dp[i-1][j];
    			choice[i][j]=0;
    		}
    		if(j>0)
    		{
    			if(dp[i][j]<dp[i][j-1])
    			{
    				dp[i][j]=dp[i][j-1];
    				choice[i][j]=1;
    			}
    		}

    		//pick
    		if(s[i]==t[j])
    		{
    			ll ans=1;
    			if(i>0 && j>0)
    			{
    				ans=1+dp[i-1][j-1];
    			}
    			if(ans>dp[i][j])
    			{
    				dp[i][j]=ans;
    				choice[i][j]=2;
    			}
    		}
    	}
    }
    ll i=s.length()-1, j=t.length()-1;
    string str;
    while(i>=0 && j>=0)
    {
    	if(choice[i][j]==0)
    	{
    		i--;
    	}
    	else if(choice[i][j]==1)
    	{
    		j--;
    	}
    	else
    	{
    		str.push_back(s[i]); // or t[j] as both are same
    		i--;
    		j--;
    	}
    }
    reverse(str.begin(), str.end());
    cout<<str;
}
    

