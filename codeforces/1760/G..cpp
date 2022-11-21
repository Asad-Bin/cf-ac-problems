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


const int N = 1e5;
vector<pair<int, ll > > ara[N+5];
vector<ll> v_a;//, v_b, x_a(N+5);
int n, a, b;
bool ok = 0;
void dfs_a(int u, int p, ll x)
{
	if(u != b) v_a.push_back(x);
	if(u == b && x == 0){
		ok = 1;
		return;
	}
	if(u == b && x) return;
	
	for(int K = 0; K < (int)ara[u].size(); K++){
		if(ara[u][K].first != p){
			dfs_a(ara[u][K].first, u, x^ara[u][K].second);
			if(ok) return;
		}
	}
}
void dfs_b(int u, int p, ll x)
{
	debug(u, x);
	if(u != b){
		auto it = lower_bound(v_a.begin(), v_a.end(), x);
		if(it != v_a.end() && *it == x){
			ok = 1;
			return;
		}
	}
	
	for(int K = 0; K < (int)ara[u].size(); K++){
		if(ara[u][K].first != p){
			dfs_b(ara[u][K].first, u, x^ara[u][K].second);
			if(ok) return;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--){
		cin >> n >> a >> b;
		
		for(int K = 0; K <= n; K++) ara[K].clear();
		v_a.clear();
		//v_b.clear();
		//v_a.push_back(0);
		//v_b.push_back(0);
		
		for(int K = 1; K < n; K++){
			ll u, v, w;
			cin >> u >> v >> w;
			ara[u].push_back({v, w});
			ara[v].push_back({u, w});
		}
		
		ok = 0;
		dfs_a(a, a, 0);
		debug(v_a);
		
		if(ok){
			cout << "YES\n";
			continue;
		}
		
		sort(v_a.begin(), v_a.end());
		dfs_b(b, b, 0);
		
		if(ok) cout << "YES\n";
		else cout  << "NO\n";
	}
	
	return 0;
}





































