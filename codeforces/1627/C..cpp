// . . . Bismillahir Rahmanir Rahim . . .

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
vi ara[MX+5];
vector<pii> vvv;
int n;
int tfs(int u, int pre, int h)
{
    for(int K = 0; K < sz(ara[u]); K++){
        if(ara[u][K] != pre) return tfs(ara[u][K], u, h+1);
    }
    
    return u;
}
int cnt = 0;
int dfs(int u, int pre, int h)
{
    debug(u, pre, h);
    cnt++;
    for(int K = 0; K < sz(ara[u]); K++){
        if(ara[u][K] != pre) return dfs(ara[u][K], u, h+1);
    }
    
    return h;
}
map<pii,int > mp;
void print(int u, int pre, int num)
{
    if(u!=pre){
        mp[{u, pre}] = mp[{pre, u}] = num;
        num = (num==2 ? 3 : 2);
    }
    for(int K = 0; K < sz(ara[u]); K++){
        if(ara[u][K] != pre) print(ara[u][K], u, num);
    }
}
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int t, u, v;
    
    cin >> t;
    while(t--){
        cin >> n;
        
        vvv.clear();
        mp.clear();
        for(int K = 1; K <= n; K++) ara[K].clear();
        for(int K = 1; K < n; K++){
            cin >> u >> v;
            ara[u].PB(v);
            ara[v].PB(u);
            vvv.PB({u, v});
        }
        
        //{
            cnt = 0;
            int node = tfs(1, 1, 0);
            debug(node);
            dfs(node, node, 0);
            debug(cnt);
             bool ok = (n == cnt ? 1 : 0);
             if(ok){
                 print(node, node, 3);
                 
                 for(auto it:vvv){
                     cout << mp[it] << ' ';
                 }
                 cout << "\n";
             }
             else{
                 cout << "-1\n";
             }
        //}
    }
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































