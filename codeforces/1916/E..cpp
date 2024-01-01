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


#define int long long

const int N = 3e5;
vector<int> ara[N+5];
int col[N+5];
int pc[N+5], node[N+5], start[N+5], end_[N+5];
int _time = 0;
vector<int> dest[N+5];

void dfs(int u)
{
    start[u] = ++_time;

    // if(pc[col[u]] != -1) node[u] = pc[col[u]];
    int pre = pc[col[u]];
    pc[col[u]] = u;
    dest[pre].push_back(u);


    for(auto it: ara[u]){
        dfs(it);
    }

    end_[u] = _time;
    pc[col[u]] = pre;
    // node[u] = -1;
}

int n;
int tree[4*N+5];
int lazy[4*N+5];

// pair<int, int> merge(pair<int, int> a, pair<int, int> b)
// {
//     pair<int, int> ans;
    
//     ans.first = max({a.first, b.first});

//     // if(ans.first == a.first) ans.second = max({a.second, b.first, b.second});
//     // else if(ans.first == a.second) ans.second = max({a.first, b.first, b.second});
//     // else if(ans.first == b.first) ans.second = max({a.second, a.first, b.second});
//     // else if(ans.first == b.second) ans.second = max({a.first, a.second, b.first});

//     return ans;
// }
void prop(int at, int l, int r)
{
    if(l < r){
        lazy[at*2] += lazy[at];
        lazy[at*2+1] += lazy[at];
    }

    tree[at] += lazy[at];

    lazy[at] = 0;
}
void update(int at, int l, int r, int L, int R, int val)
{
    if(L <= l && r <= R){
        lazy[at] += val;

        tree[at] += lazy[at];
        
        if(l < r){
            lazy[at*2] += lazy[at];
            lazy[at*2+1] += lazy[at];
        }
        lazy[at] = 0;

        return;
    }

    prop(at, l, r);

    if(r < L || R < l) return;

    int mid = (l + r)/2;

    update(at*2, l, mid, L, R, val);
    update(at*2+1, mid+1, r, L, R, val);

    tree[at] = max(tree[at*2], tree[at*2+1]);
}

int query(int at, int l, int r, int L, int R)
{
    prop(at, l, r);

    if(r < L || R < l) return 0;
    if(L <= l && r <= R) return tree[at];

    int mid = (l + r)/2;

    int x = query(at*2, l, mid, L, R);
    int y = query(at*2+1, mid+1, r, L, R);

    return max(x, y);
}

int ans = 0;
void dfs1(int u)
{
    for(auto it: ara[u]) dfs1(it);

    update(1, 1, n, start[u], end_[u], 1);
    for(auto it: dest[u]){
        update(1, 1, n, start[it], end_[it], -1);
    }

    vector<int> lst;
    for(auto it: ara[u]){
        lst.push_back(query(1, 1, n, start[it], end_[it]));
    }
    sort(lst.rbegin(), lst.rend());

    // cout << u << ": ";
    // for(auto it: lst) cout << it << ' ' ;
    //     cout << "\n";
    // for(auto it: dest[u]) cout << it << ' ' ;
    //     cout << "\n";

    if((int)lst.size() > 1) ans = max(ans, lst[0]*lst[1]);
    if(lst.size() >= 1) ans = max(ans, lst[0]);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1; 
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        // cout << "Case " << cs << "\n";

        cin >> n;

        for(int K = 1; K <= n; K++) ara[K].clear(), dest[K].clear();

        for(int K = 2; K <= n; K++) {
            int x; cin >> x;
            ara[x].push_back(K);
        }

        for(int K = 1; K <= n; K++) cin >> col[K];

            if(n == 1){
                cout << 1 << "\n";
                continue;
            }

        for(int K = 1; K <= n; K++) pc[K] = node[K] = 0;

        _time = 0;
        dfs(1);

        // for(int K = 1; K <= n; K++) cout << node[K] << ' ';
        //     cout << "\n";

        for(int K = 1; K <= 4*n; K++) tree[K] = 0, lazy[K] = 0;
        ans = 0;
        dfs1(1);


        cout << ans << "\n";
    }

    return 0;
}





























