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
const ll N=301;
lld dp[N][N][N];
// dp[x][y][z]=x 3s, y 2s, z 1s, (n-x-y-z) 0s;

// dp[x][y][z]=1+(p3*dp[x-1][y+1][z])+(p2*dp[x][y-1][z+1])+(p1*dp[x][y][z-1])+(p0*dp[x][y][z]);
// where p1, p2, p3 = probablity of picking 3 sushi, 2 sushi, 1, 0 sushi

// but the above expression is wrong since the value which is supposed to be calculated is dependent on one of the value in expression
// dp[x][y][z]-(p0*dp[x][y][z])=1+(p3*dp[x-1][y+1][z])+(p2*dp[x][y-1][z+1])+(p1*dp[x][y][z-1]);
// dp[x][y][z]*(1-p0)=1+(p3*dp[x-1][y+1][z])+(p2*dp[x][y-1][z+1])+(p1*dp[x][y][z-1]);
// therefore, dp[x][y][z]=(1+(p3*dp[x-1][y+1][z])+(p2*dp[x][y-1][z+1])+(p1*dp[x][y][z-1]))/(1-p0);


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ll n;
    cin>>n;
    ll cnt[4]={0}; // since we only need counts of 3s, 2s, 1s, 0s;
    for(ll i=0; i<n; i++)
    {
        ll x;
        cin>>x;
        cnt[x]++;
    }
    dp[0][0][0]=0; //base condition;
    for(ll three=0; three<=n; three++)
    {
        for(ll two=0; two<=n; two++)
        {
            for(ll one=0; one<=n; one++)
            {
                ll zero=n-three-two-one;
                if(zero==n) 
                {
                    continue;
                }
                if(one + two + three > n)
                {
                    continue;
                }
                lld val=1; // as i will pick 1 for sure;
                //pick 3;
                if(three>0)
                {
                    val+=(1.0*three/n)*dp[three-1][two+1][one]; //1.0* part is the probability;
                }
                //pick 2;
                if(two>0)
                {
                    val+=(1.0*two/n)*dp[three][two-1][one+1]; //1.0* part is the probability;
                }
                // pick 1;
                if(one>0)
                {
                    val+=(1.0*one/n)*dp[three][two][one-1]; //1.0* part is the probability;
                }
                dp[three][two][one]=val/(1-1.0*zero/n); // the logic we used in top comments (1-p0);
            }
        }
    }
    cout<<setprecision(9);
    cout<<fixed;
    cout<<dp[cnt[3]][cnt[2]][cnt[1]];
}
