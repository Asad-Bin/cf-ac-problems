#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<long long>
#define PB push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
//#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


const int MX = 2e5;
int ara[MX+5];
ll cnt[5*MX+5];
ll sol[MX+5];
int S = sqrt(MX);

// vector<pair<pii, int> > v;
struct Node{
    int fi;
    int se;
    int idx;
    
    Node() {}
    Node(int _fi, int _se, int _idx){
        fi = _fi;
        se = _se;
        idx = _idx;
    }
    
    bool operator<(const Node &other)const {
        if ((int)fi/S != (int)other.fi/S) return (int)fi/S < (int)other.fi/S;
        return se < other.se;
    }
} v[5*MX+5];

// struct hash_pair {
    // template <class T1, class T2>
    // size_t operator()(const pair<T1, T2>& p) const
    // {
        // auto hash1 = hash<T1>{}(p.first);
        // auto hash2 = hash<T2>{}(p.second);
        // return hash1 ^ hash2;
    // }
// };
// bool cmp(pair<pii, int> a, pair<pii, int> b)
// {
    // if(a.fi == b.fi) return a.se > b.se;
    // return a.fi < b.fi;
// }
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int n, t, l, r;
    
    sii(n, t);
    
    for(int K = 1; K <= n; K++) si(ara[K]);
    
    for(int K = 0; K < t; K++){
        sii(l, r);
        v[K] = Node(l, r, K);
        //v.PB({{l, r}, K});
    }
    
    sort(v, v+t);
    
    // l = v[0].fi;
    // r = v[0].se;
    // for(int K = l; K <= r; K++){
        // cnt[ara[K]]++;
    // }
    ll ans = 0;
    // for(int K = 1; K <= 5*MX; K++) ans += (cnt[K]*cnt[K]*K);
    
    // sol[v[0].idx] = ans;
    l = r = 1;
    ans = ara[1];
    cnt[ara[1]] = 1;
    
    for(int K = 0; K < t; K++){
        debug(l, r, v[K].fi, v[K].se, ans);
        while(l < v[K].fi){
            ans -= cnt[ara[l]]*cnt[ara[l]]*ara[l];
            cnt[ara[l]]--;
            ans += cnt[ara[l]]*cnt[ara[l]]*ara[l];
            
            l++;
        }
        debug(l, r, v[K].fi, v[K].se, ans);
        while(l > v[K].fi){
            l--;
            
            ans -= cnt[ara[l]]*cnt[ara[l]]*ara[l];
            cnt[ara[l]]++;
            ans += cnt[ara[l]]*cnt[ara[l]]*ara[l];
            //debug(l, r, v[K].fi, v[K].se, ans);
        }
        debug(l, r, v[K].fi, v[K].se, ans);
        while(r < v[K].se){
            r++;
            
            ans -= cnt[ara[r]]*cnt[ara[r]]*ara[r];
            cnt[ara[r]]++;
            ans += cnt[ara[r]]*cnt[ara[r]]*ara[r];
        }
        debug(l, r, v[K].fi, v[K].se, ans);
        while(r > v[K].se){
            ans -= cnt[ara[r]]*cnt[ara[r]]*ara[r];
            cnt[ara[r]]--;
            ans += cnt[ara[r]]*cnt[ara[r]]*ara[r];
            //debug(l, r, v[K].fi, v[K].se, ans);
            
            r--;
        }
        debug(l, r, v[K].fi, v[K].se, ans);
        
        sol[v[K].idx] = ans;
    }
    
    for(int K = 0; K < t; K++) printf("%lld\n", sol[K]);
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































