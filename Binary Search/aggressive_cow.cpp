/*
Daksh Paleria
dakshp07
*/

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
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

bool canPlaceCows(vector<int>&stalls, int n, int mid, int cows)
{
    // we want to place cows at dist of mid
    // and greedily its better to place first cow at 0
    int cnt=1; // first cow at 0
    int coordinate=stalls[0]; // coordinate of first placed cow
    for(int i=1; i<n; i++)
    {
        // if the pos of new cow and pos of last cow is greater than mid (ie what we expected)
        if(stalls[i]-coordinate>=mid)
        {
            // then we can place cow there and move to next ones
            cnt++;
            coordinate=stalls[i];
        }
    }
    // if we were able to place all cows
    if(cnt>=cows)
    {
        // we satisfy our rules and return true
        return true;
    }
    return false; // other cases
}

void solve(){
    // one of the ways is to use recursion and try all ways
    // but we will use binary search efficiently
    // our low will be at min possible ele of array ie 0
    // our high will at the diff of min and max ele in array because we can get min 2 cows ie max-min=>max-0=>max
    // and in order to maximise their distance we can place them at min and max
    // which makes high to be the max diff in this case
    // so all our rest ans will fit in window of low, high
    int n, c;
    cin>>n>>c;
    vector<int> stalls(n);
    for(int i=0; i<n; i++)
    {
        cin>>stalls[i];
    }
    sort(stalls.begin(), stalls.end()); // sort the array to get min, max at positons
    int low=0; // start from 0
    int res=-1; // intialize ans with -1
    int high=stalls[n-1]; // traverse till max
    debug(high);
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(canPlaceCows(stalls, stalls.size(), mid, c)) // if i can place cows means we got one ans
        {
            debug(mid); 
            if(mid>res) 
            {
                res=mid; // we will update mid only when we get max ans
            }
            // adjust boundaries as we need minimum ans
            low=mid+1;
        }
        else // if we cant place means
        {
            high=mid-1;
        }
    }
    cout<<res<<"\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    auto start1 = high_resolution_clock::now();
    ll tt;
    cin>>tt;
    while(tt!=0)
    {
        solve();
        tt--;
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cerr << "Time: " << duration.count()/1000 << endl;
}
