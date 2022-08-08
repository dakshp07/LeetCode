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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    vector<vector<lld>> dp(3000, vector<lld>(3000));
    // dp[index][heads] = probablity
    // dp[index][heads] processed till index with heads begin stored in the array
    vector<lld> p(3000);
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>p[i];
    }
    dp[0][0]=1-p[0]; // tails
    dp[0][1]=p[0]; // heads
    for(ll i=1; i<n; i++)
    {
        for(ll j=0; j<3000; j++)
        {
            // tails
            dp[i][j]+=(1-p[i]) * (dp[i-1][j]); // independent events
            //heads
            if(j>0)
            {
                dp[i][j]+=p[i] * (dp[i-1][j-1]);
            }
        }
    }
    lld ans=0;
    for(ll i=n/2+1; i<3000; i++)
    {
        ans+=dp[n-1][i];
    }
    cout<<setprecision(9);
    cout<<fixed;
    cout<<ans;
}
