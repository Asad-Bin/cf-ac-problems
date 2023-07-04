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


ll dist[101][101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m; cin >> n >> m;
	
	//memset(dist, 0x3f, sizeof dist);
	//for(int K = 1; K <= 10; K++) cout << dist[K] << ' ' ;
	//cout << "\n";
	for(int K = 0; K <= 100; K++) for(int L = 0; L <= 100; L++) dist[K][L] = (ll)1e18+7;
	
	for(int K  = 0; K < m; K++){
		ll a, b, c; cin >> a >> b  >> c;
		
		dist[a][b] = dist[b][a] = c;
	}
	
	for(int K = 0; K <= n; K++) dist[K][K] = 0;
	
	for(int M = 1; M <= n; M++)
		for(int K = 1; K <= n; K++)
			for(int L = 1; L <= n; L++) 
				dist[K][L] = min(dist[K][L], dist[K][M]+dist[M][L]);
				
	if(dist[1][n] >  (ll)1e18) {
		cout << "inf\n";
		return 0;
	}
				
	int ord[101];
	iota(ord, ord+n+1, 0);
	sort(ord+2, ord+n+1, [&](int a, int b){
		return dist[1][a] < dist[1][b];
	});
	
	//int tot = 0;
	vector<pair<string, ll> > ans;
	string s;
	s.assign(n, '0');
	for(int K = 1; K < n; K++){
		int u = ord[K], v = ord[K+1];
		
		s[u-1] = '1';
		
		ans.push_back({s, dist[1][v]-dist[1][u]});
		if(v == n) break;
	}
	
	cout << dist[1][n] << ' ' << (int)ans.size() << "\n";
	
	for(auto [u, v] : ans) cout << u << ' ' << v << "\n";
	
	
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
