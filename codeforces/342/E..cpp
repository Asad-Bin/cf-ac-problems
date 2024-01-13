// . . . Bismillahir Rahmanir Rahim . . .


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg_out cout
#define debug(...) dbg_out << "DBG )> "; __f(#__VA_ARGS__, __VA_ARGS__);
template<typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2> pr) { out << "{ " << pr.first << ", " << pr.second << " }"; return out; }
template<typename T1> ostream& operator<<(ostream& out, vector<T1> vec) { out << "{ "; for (auto &x: vec) out << x << ", "; out << "}"; return out; }
template<typename T1, size_t size> ostream& operator<<(ostream& out, array<T1, size> arr) { out << "{ "; for (auto &x: arr) out << x << ", "; out << "}"; return out; }
template<typename T1, typename T2> ostream& operator<<(ostream& out, map<T1, T2> mp) { out << "{ ";for (auto &x: mp) out << x.first << ": " << x.second <<  ", "; out << "}"; return out; }
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { while (isspace(name[0])) name++; (isalpha(name[0]) || name[0] == '_') ? dbg_out << name << ": " << arg1 << "\n" : dbg_out << arg1 << "\n"; dbg_out.flush();}
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) { const char *comma = strchr(names + 1, ','); while (isspace(names[0])) names++; (isalpha(names[0]) || names[0] == '_') ? dbg_out.write(names, comma - names) << ": " << arg1 << " | " : dbg_out << arg1 << " | "; __f(comma + 1, args...);}
#else
#define debug(...)
#endif

ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll bigmod(ll a,ll b,ll mod){ 
    b %= (mod-1);
    a %= mod;

    if(b==0){
     return 1;
    } 
    ll tm=bigmod(a,b/2,mod); 
    tm=(tm*tm)%mod; 
    if(b%2==1) tm=(tm*a)%mod; 
    return tm;
}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}



const int N = 1e5;
const int inf = 1e9+7;
set<int> ara[N+5];
int cnt[N+5], par[N+5], ans[N+5];

const int LOG= 20;
int depth[N+5], up[N+5][LOG];
// vector<int> v[N];

void dfs(int pos,int pre)
{
   for(auto it:ara[pos])
   {
      if(it==pre) continue;
      depth[it]=depth[pos]+1;
      up[it][0] = pos; 
      for(int j = 1; j < LOG; j++) 
      {
        up[it][j] = up[up[it][j-1]][j-1];
      }
      dfs(it,pos);
   }
}
int kthancestor(int pos,int k)
{
    for(int i=LOG-1;i>=0;i--)
    {
        if(k&(1<<i))
        pos=up[pos][i];
    }
    return pos;
}
int get_lca(int a, int b) 
{ 
    if(depth[a] < depth[b]) {
        swap(a, b);
    }
    // 1) Get same depth.
    int k = depth[a] - depth[b];
    a=kthancestor(a,k);
    // 2) if b was ancestor of a then now a==b
    if(a == b) {
        return a;
    }
    // 3) move both a and b with powers of two
    for(int j = LOG - 1; j >= 0; j--) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

void dfs0(int u, int p)
{
    cnt[u] = 1;

    for(auto v: ara[u]){
        if(v != p){
            dfs0(v, u);
            cnt[u] += cnt[v];
        }
    }
}
int dfs1(int u, int p, int n)
{
    for(auto v: ara[u]){
        if(v != p && cnt[v] > n/2){
            // cout << u << ' ' << p << ' ' << v << ' '<< cnt[v] << "\n";
            return dfs1(v, u, n);
        }
    }

    return u;
}
void decompose(int root, int p, int n)
{
    dfs0(root, root);
    // cout << cnt[root] << ' ';
    // for(int K = 1; K <= n; K++) cout << cnt[K] << ' ';
    //     cout << '\n';
    int centroid = dfs1(root, root, cnt[root]);

    if(p == -1) p = centroid;
    par[centroid] = p;

    // cout << root << ' ' << centroid << ' ' << p << "\n";

    // for(auto v: ara[centroid]){
    //     // if(v != p){
    //         ara[v].erase(centroid);
    //         decompose(v, centroid);
    //     // }
    // }
    for(auto v = ara[centroid].begin(); v != ara[centroid].end(); v++){
        ara[*v].erase(centroid);
        decompose(*v, centroid, n);
    }
    ara[centroid].clear();
}

int dist(int u, int v)
{
    return depth[u]+depth[v] - 2*depth[get_lca(u, v)];
}
void update(int u)
{
    int x = u;

    while(true){
        ans[x] = min(ans[x], dist(u, x));
        if(x == par[x]) break;
        x = par[x];
    }
}
int query(int u)
{
    int mn = inf;
    int x = u;

    while(true){
        mn = min(mn, dist(u, x)+ans[x]);
        if(x == par[x]) break;
        x = par[x];
    }

    return mn;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1; 
    // cin >> t;
    for(int cs = 1; cs <= t; cs++){
        // cout << "Case " << cs << ": ";

        int n, m; cin >> n >> m;

        for(int K = 0; K < n-1; K++){
            int a, b; cin >> a >> b;
            ara[a].insert(b);
            ara[b].insert(a);
        }

        dfs(1, 1);

        decompose(1, -1, n);

        // for(int K = 1; K <= n; K++) cout << par[K] << ' ';
        //     cout << "\n";

        for(int K = 1; K <= n; K++) ans[K] = inf;


        update(1);

        while(m--){
            int a, b; cin >> a >> b;

            if(a == 1){
                update(b);
            }
            else{
                cout << query(b) << "\n";
            }
        }
    }

    return 0;
}





























