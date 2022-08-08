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
    ll n, k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    vector<ll> dp(100001); // dp[i]=0 means player 2 wins, dp[i]=1 means player 1 wins
    dp[0]=0; // if there are no stones in pile the player one loses as he plays first
    for(ll i=1; i<=k; i++)
    {
        dp[i]=0;
        for(ll j=0; j<n; j++)
        {
            if(i>=arr[j] && dp[i-arr[j]]==0)// means if i pick arr[j] and go to losing state means dp[i] is wining state or otherwise its a losing state
            {
                dp[i]=1;
                break;
            }
        }
    }
    if(dp[k]==1)
    {
        cout<<"First";
    }
    else
    {
        cout<<"Second";
    }
}
