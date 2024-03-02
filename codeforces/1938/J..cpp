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

const ll INF = 7e17;
const int N = 1e5 + 9;
set<pair<ll,ll>> adj[N + 1];
void dijkstra(ll u , vector<ll> &dist, vector<ll> &par){
	priority_queue<pair<ll,pair<ll,ll>>> pq;
	pq.push({0 , {u , u}});
	while(!pq.empty()){
		auto [i , j] = pq.top();
		pq.pop();
		i *= -1;
		int x = j.first;
		int y = j.second;
		if(dist[x] != INF) continue;
		dist[x] = i;
		par[x] = y;
		for(auto [z , w] : adj[x]){
			if(dist[z] != INF) continue;
			pq.push({-i - w , {z , x}});
		}
	}
}

void GG(){
	int n , m;
	cin >> n >> m;
	vector<ll> dist1(n + 1 , INF);
	vector<ll> dist2(n + 1 , INF);
	vector<ll> par(n + 1);
	
	vector<ll> lst;
	for(int i = 1; i <= m; i++){
		ll u , v , w;
		cin >> u >> v >> w;
		adj[u].insert({v , w});
		adj[v].insert({u , w});
	}
	dijkstra(1 , dist1 , par);
	if(dist1[n] == INF){
		cout << -1;
		return;
	}
	ll nd = n;
	vector<bool> mark(n + 1, false);
	while(nd != 1){
		lst.push_back(nd);
		mark[nd] = true;
		nd = par[nd];
	}
	ll sqc = dist1[n];
	ll ans = INF;
	mark[1] = true;
	lst.push_back(1);
	reverse(lst.begin() , lst.end());
	dijkstra(n , dist2 , par);
	for(int i = 1; i <= n; i++){
		if(mark[i] == false && dist1[i] != INF && dist2[i] != INF) ans = min(ans , sqc + dist1[i] + dist2[i]);  
		// cout << i << ' ' << mark[i] << ' ' << dist1[i] << ' ' << dist2[i] << ' ' << sqc << endl;
	}
	for(int i = 0; i < lst.size(); i++){
		int x = lst[i];
		for(auto [y , z] : adj[x]){
			if(!mark[y]) continue;
			if(i > 0) if(lst[i - 1] == y) continue;
			if(i < lst.size() - 1) if(lst[i + 1] == y) continue;
			ans = min(ans , sqc + dist1[x] + dist2[y] + z);
			ans = min(ans , sqc + dist2[x] + dist1[y] + z);
		}
	}
	if(ans < INF) cout << ans;
	else cout << -1;
}


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// memset(sol, 0, sizeof sol);

	int t = 1;
	// cin >> t;
	for(int cs = 1; cs <= t; cs++){
		GG();
		// cout << "Case " << cs << ": ";
	}

	return 0;
}





























