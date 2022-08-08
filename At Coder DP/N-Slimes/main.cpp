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
const ll INF=1e18;
ll dp[401][401]; // dp[l][r] = answer for [l...r]
ll siz[401][401]; // siz[l][r] = siz of [l...r]
// initial conditions:
// dp[i][i] = 0 for all i
// siz[i][i] = a[i]
 
// transitions
// dp[l][r] = min(dp[l][x] + dp[x+1][r] + siz[l][r]) for all x: x >= l && x < r
// siz[l][r] = a[l] + siz[l+1][r]
 
// final answer = dp[0][n-1]
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
        siz[i][i]=a[i];
        dp[i][i]=0;
    }

    // order of evaluation
    for(int width = 2; width <= n; width++)
    {
        for(int l = 0, r = width - 1; r < n; l++, r++)
        {
            siz[l][r] = a[l] + siz[l+1][r];
            dp[l][r] = INF;
            for(int x = l; x < r; x++)
            {
                dp[l][r] = min(dp[l][r], dp[l][x] + dp[x+1][r] + siz[l][r]);
            }
        }
    }
    cout<<dp[0][n-1];
}
