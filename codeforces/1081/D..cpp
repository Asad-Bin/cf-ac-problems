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
ll bigmod(ll a,ll b,ll mod){ if(b==0){ return 1;} ll tm=bigmod(a,b/2,mod); tm=(tm*tm)%mod; if(b%2==1) tm=(tm*a)%mod; return tm;}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}


const int MX = 1e5;
int dsu[MX+5], sp[MX+5], node[MX+5];
vector<pair<int, int> > ara[MX+5];
int Find(int x)
{
	if(dsu[x] == x) return x;
	
	return dsu[x] = Find(dsu[x]);
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	
	dsu[b] = a;
}
vector<pair<int, pair<int, int> > > Edges; // {weight, {u, v}};
int kruskal()
{
	sort(Edges.begin(), Edges.end());
	int E = (int)Edges.size();
	int mst_cost = 0;
	
	for(int K = 0; K < E; K++){
		if(Find(Edges[K].second.first) != Find(Edges[K].second.second)){
			Union(Edges[K].second.first, Edges[K].second.second);
			//mst_cost += Edges[K].first;
			int u = Edges[K].second.first;
			int v = Edges[K].second.second;
			
			ara[u].push_back({v, Edges[K].first});
			ara[v].push_back({u, Edges[K].first});
		}
	}
	
	return mst_cost;
}
int dfs(int u, int p)
{
	int cnt = 0;
	for(int K = 0; K < (int)ara[u].size(); K++){
		if(ara[u][K].first != p){
			cnt += dfs(ara[u][K].first, u);
		}
	}
	
	if(cnt == 0 && !sp[u]){
		node[u] = 0;
	}
	
	return cnt+(sp[u]);
}
int dfs2(int u, int p)
{
	int ans = 0;
	int mx = 0;
	for(int K = 0; K < (int)ara[u].size(); K++){
		if(ara[u][K].first != p && node[ara[u][K].first]){
			mx = max(mx, ara[u][K].second);
			ans = max(ans, dfs2(ara[u][K].first, u));
		}
	}
	
	return max(ans, mx);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, k; cin >> n >> m >> k;
	
	int st;
	for(int K = 0; K < k; K++){
		int x; cin >> x;
		sp[x] = 1;
		st = x;
	}
	
	for(int K = 0; K < m; K++){
		int a, b, w; cin >> a >> b >> w;
		
		Edges.push_back({w, {a, b}});
	}
	
	for(int K = 1; K <= n; K++) dsu[K] = K;
	kruskal();
	
	for(int K = 1; K <= n; K++) node[K] = 1;
	dfs(st, st);
	
	int ans = dfs2(st, st);
	
	for(int K = 0; K < k; K++) cout << ans << ' ';
	cout << "\n";
	
	return 0;
}





































