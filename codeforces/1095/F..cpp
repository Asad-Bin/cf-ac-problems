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


const ll MX = 2e5;
ll dsu[MX+5];

ll Find(ll x)
{
	if(dsu[x] == x) return x;
	
	return dsu[x] = Find(dsu[x]);
}
void Union(ll a, ll b)
{
	a = Find(a);
	b = Find(b);
	
	dsu[b] = a;
}
vector<pair<ll, pair<ll, ll> > > Edges; // {weight, {u, v}};
ll kruskal()
{
	sort(Edges.begin(), Edges.end());
	ll E = (ll)Edges.size();
	ll mst_cost = 0;
	
	for(ll K = 0; K < E; K++){
		if(Find(Edges[K].second.first) != Find(Edges[K].second.second)){
			Union(Edges[K].second.first, Edges[K].second.second);
			mst_cost += Edges[K].first;
			//ll u = Edges[K].second.first;
			//ll v = Edges[K].second.second;
			
			//ara[u].push_back({v, Edges[K].first});
			//ara[v].push_back({u, Edges[K].first});
		}
	}
	
	return mst_cost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n, m; cin >> n >> m;
	
	if(n == 1){
		int x; cin >> x;
		
		cout << 0 << "\n";
		return 0;
	}
	
	ll weight[n+5];
	vector<pair<ll, ll> > v;
	for(ll K = 1; K <= n; K++){
		ll x;  cin >> x;
		v.push_back({x, K});
		weight[K] = x;
	}
	
	sort(v.begin(), v.end());
	
	for(ll K = 1; K <= n; K++){
		if(v[0].second != K) Edges.push_back({weight[K]+v[0].first, {K, v[0].second}});
		else Edges.push_back({weight[K]+v[1].first, {K, v[1].second}});
	}
	
	for(ll K = 0; K < m; K++){
		ll x, y, w; cin >> x >> y >> w;
		
		Edges.push_back({w, {x, y}});
	}
	
	//for(auto it: Edges) cout << it.first << ' ' << it.second << "\n";
	
	for(ll K = 1; K <= n; K++) dsu[K] = K;
	cout << kruskal() << "\n";
	
	
	return 0;
}





































