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
const ll MOD=1e9+7;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ll h, w;
    cin>>h>>w;
    string str[1001];
    for(ll i=0; i<h; i++)
    {
        cin>>str[i];
    }
    vector<vector<ll>> dp(1001, vector<ll>(1001));
    dp[0][0]=1;
    for(ll i=0; i<h; i++)
    {
        for(ll j=0; j<w; j++)
        {
            if(str[i][j]=='#')
            {
                dp[i][j]=0;
                continue;
            }
            if(i>0)
            {
                dp[i][j]+=dp[i-1][j];
            }
            dp[i][j]%=MOD;
            if(j>0)
            {
                dp[i][j]+=dp[i][j-1];
            }
            dp[i][j]%=MOD;
        }
    }
    cout<<dp[h-1][w-1];
}
