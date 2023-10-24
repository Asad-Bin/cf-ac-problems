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



const int inf = 1e9+7;
const int N = 2e5;
vector<pair<int, int> > ara[N+5];
vector<int> timee[N+5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, t; cin >> n >> t;

	for(int K = 1; K <= t; K++){
		int m; cin >> m;
		for(int L = 0; L < m; L++) {
			int u, v; cin >> u >> v;
			ara[u].push_back({K, v});
			ara[v].push_back({K, u});
		}
	}

	for(int K = 1; K <= n; K++) sort(ara[K].begin(), ara[K].end());

	int k; cin >> k;
	int mom[k+1];
	for(int K = 1; K <= k; K++){
		cin  >> mom[K];
		timee[mom[K]].push_back(K);
	}
	for(int K = 1; K <= t; K++) timee[K].push_back(inf);

	priority_queue<pair<int, int> > q;
	vector<int> level(n+1, inf);
	level[1] = 0;

	q.push({1, 0});
	// for(int ans = 1; ans <= k; ans++){
		// int curr = mom[ans];


	while(!q.empty()){
		int u = q.top().first, x = q.top().second;
		// qq.push(u);
		q.pop();

		if(level[u] < x) continue;

		// auto it = lower_bound(ara[u].begin(), ara[u].end(), make_pair(mom[ans], 0));
		// cout << ' ' << u << ' ' << x << "\n";


		for(auto it: ara[u]){
			// if(it.first != curr) break;
			auto it2 = lower_bound(timee[it.first].begin(), timee[it.first].end(), x+1) - timee[it.first].begin();
			it2 = timee[it.first][it2];

			// cout << it.first << ' ' << it.second << ' ' << it2 << ' ' << level[it.second] << "\n";

			if(it2 < level[it.second]){
				level[it.second] = it2;

				// cout << u << ' '  << it2 << ' ' << it.second << "\n";

				q.push({it.second, it2});

				// if(it.second == n){
				// 	if(it2 >= inf) cout << -1 << "\n";
				// 	else cout << it2 << "\n";
				// 	return 0;
				// }
			}

			// ++it;
		}
	}

		// while(!qq.empty()){
		// 	q.push(qq.front());
		// 	qq.pop();
		// }
	// }

	if(level[n] == inf) cout << -1 << "\n";
	else cout << level[n] << "\n";
	
	return 0;
}





































