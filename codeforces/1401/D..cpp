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


const int MX = 1e5;
int n;
ll sum[MX+5];
vi edge[MX+5];
vl res;
const ll mod = 1e9+7;

void dfs(int u, int f)
{
    sum[u] = 1;
    for(int K = 0; K < sz(edge[u]); K++){
        if(edge[u][K] != f){
            dfs(edge[u][K], u);
            
            sum[u] += sum[edge[u][K]];
        }
    }
    
    if(f != 0) res.PB(sum[u]*(n-sum[u]));
}
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int t, m, u, v;
    
    cin >> t;
    while(t--){
        cin >> n;
        //for(int K = 0; K < n; K++) cin >> ara[K];
        
        for(int K = 1; K <= n; K++) edge[K].clear();
        for(int K = 1; K < n; K++){
            cin >> u >> v;
            edge[u].PB(v);
            edge[v].PB(u);
        }
        
        res.clear();
        dfs(1, 0);
        
        //res[1] = 1;
        sort(res.begin(), res.end());
        
        cin >> m;
        deque<ll> p(m);
        for(int K = 0; K < m; K++) cin >> p[K];
        sort(p.begin(), p.end());
        // for(int K = 1; K <= m; K++) cout << p[K] << ' ';
        // cout << "\n";
        
        while(sz(p) > n-1){
            p[sz(p)-2] *= p[sz(p)-1];
            p[sz(p)-2] %= mod;
            p.pop_back();
        }
        while(sz(p) < n-1) p.push_front(1);
        
        debug(p);
        // for(int K = 1; K <= m; K++) cout << p[K-1] << ' ';
        // cout << "\n";
        
        ll ans = 0;
        for(int K = 0; K < n-1; K++) ans = (ans + (res[K]*p[K]%mod))%mod;
        
        cout << ans << "\n";
    }
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































