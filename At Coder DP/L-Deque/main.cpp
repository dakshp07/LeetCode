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
// X-Y -> this is supposed to be minimzed or maximized
// so, X-Y must be equal to a constant C
// X+Y=C -> Y=C-X substitute this in top equation
// 2*X-C -> X
ll dp[3000][3000][2]; // resulting value of X
// dp[L][R][p] = (L....R) inclusive, pth player turn
// p = 0 -> first, p = 1 -> second
 
// base cases:
// dp[i][i][0] = a[i]
// dp[i][i][1] = 0
 
// Transitions:
// pick L or pick R
// dp[L][R][0] = max(a[L] + dp[L+1][R][1],
//                  a[R] + dp[L][R-1][1])
// dp[L][R][1] = min(dp[L+1][R][0],
//                  dp[L][R-1][0])
 
// Order of Evaluation:
// increasing of (R-L)
 
// ans = 2*(dp[0][n-1][0]) - sum (sum is the constant C) 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif 
    ll n, sum=0;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(ll i=0; i<n; i++)
    {
        dp[i][i][0]=a[i];
        dp[i][i][1]=0;
    }
    for(ll rminusl=1; rminusl<n; rminusl++)
    {
        for(ll L=0; L+rminusl<n; L++)
        {
            ll R=L+rminusl;
            dp[L][R][0]=max(a[L]+dp[L+1][R][1], a[R]+dp[L][R-1][1]);

            dp[L][R][1]=min(dp[L+1][R][0], dp[L][R-1][0]);
        }
    }
    // debug(dp);
    ll X=dp[0][n-1][0]; // (0.....n-1) first player move
    ll ans=2*X-sum; // sum is constant
    cout<<ans;
}
