/*
Daksh Paleria
dakshp07
*/

#include <bits/stdc++.h>
using namespace std;
/*-----TEMPLATE STARTS-----*/
typedef long long ll;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*-----TEMPLATE ENDS-----*/
const int MOD=1e9+7;
ll dp[100][100005];
ll a[100];
// dp[x][y] = xth position and y candies ke no. of ways store honge in dp
// dp[x][0] = 1
 
// dp[first][0] = dp[first][1] = ..... dp[first][a[0]] = 1
 
// dp[x][y] = dp[x-1][y] + dp[x-1][y-1] + dp[x-1][y-2] + ...
                // ..... + dp[x-1][y-a[x]]
// dp[x-1] -> prefix_sum
// dp[x][y] = prefix_sum[y] - prefix_sum[y-a[x]-1]
 
// dp[last][k]
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ll n, k;
    cin>>n>>k;
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(ll i=0; i<=a[0]; i++)
    {
        dp[0][i]=1;
    }
    for(ll i=1; i<n; i++)
    {
        vector<ll> prefix_sum(k+1);
        prefix_sum[0]=dp[i-1][0];
        for(ll j=1; j<k+1; j++)
        {
            prefix_sum[j]=(prefix_sum[j-1]+dp[i-1][j])%MOD;
        }
        for(ll j=0; j<k+1; j++)
        {
            if(j>a[i])
                dp[i][j]=(prefix_sum[j]+MOD-prefix_sum[j-a[i]-1])%MOD;
            else
                dp[i][j]=prefix_sum[j];
        }
    }
    cout<<dp[n-1][k];
}
