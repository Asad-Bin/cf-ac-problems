#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;


#ifndef ONLINE_JUDGE
    #define dbg(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
    #define dbg(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void solve(){
    ll n;cin>>n;
    vector<ll>v(n);
    ll ans = 0;

    for(ll i = 0; i < n; i++){
        cin>>v[i];
    }
    vector<int>x(n,0);
    // memset(x,0,sizeof(x));
    
    for(ll i = 1; i < n; i++){

        if(v[i-1] > v[i]){
            // dbg(i)
            ll tp = v[i];

            ll cnt = 0;
            while(tp < v[i-1]){
                tp*=2;
                cnt++;
            }
            x[i] = x[i-1]+cnt;
            
        }
        else{
            ll tp = v[i-1];
            ll cnt = x[i-1];
            while(cnt >0 and 2*tp <= v[i]){
                tp *= 2;
                cnt--;
            }
            x[i] = cnt;
        }
    }

    for(int i = 0; i < n; i++){
        // cerr<<x[i]<<' ';
        ans +=x[i];

    }

    cout<<ans<<endl;
}
int32_t main()
{
    fastio();
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        //cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}