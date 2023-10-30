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


const ll N = 5e5;
vector<ll> ara[N+5];
ll st_time[N+5], en_time[N+5];
ll time_ = 0;

void dfs(ll u, ll p)
{
	st_time[u] = ++time_;
	
	for(auto v: ara[u]){
		dfs(v, u);
	}
	
	en_time[u] = ++time_;
}

ll tree[8*N+55];
void update(ll at, ll l, ll r, ll L, ll R, ll val)
{
	if(r < L || R < l) return;
	if(L <= l && r <= R){
		tree[at] += val;
		return;
	}
	
	tree[at*2] += tree[at];
	tree[at*2+1] += tree[at];
	tree[at] = 0;
	
	ll mid = (l + r)/2;
	
	update(at*2, l, mid, L, R, val);
	update(at*2+1, mid+1, r, L, R, val);
	
	//tree[at] = tree[at*2] + tree[at
}
ll query(ll at, ll l, ll r, ll pos)
{
	if(l == r) return tree[at];
	
	tree[at*2] += tree[at];
	tree[at*2+1] += tree[at];
	tree[at] = 0;
	
	ll mid = (l + r)/2;
	
	ll x = 0;
	
	if(pos <= mid) x = query(at*2, l, mid, pos);
	else x = query(at*2+1, mid+1, r, pos);
	
	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll t; cin >> t;
	while(t--){
		ll q; cin >> q;
		
		vector<vector<ll> > v;
		
		ll n = 1;
		for(ll K = 0; K < q; K++){
			ll type; cin >> type;
			
			if(type == 1){
				ll x; cin >> x;
				//ara[x].push_back(++n);
				n++;
				v.push_back({1, x, n});
			}
			else{
				ll x, y; cin >> x >> y;
				
				v.push_back({2, x, y});
			}
		}
		
		for(ll K = 1; K <= n; K++) ara[K].clear();
		
		//ll i = 1;
		for(ll K = 0; K < q; K++){
			if(v[K][0] == 1){
				//ll x; cin >> x;
				ara[v[K][1]].push_back(v[K][2]);
				//n++;
				//v.push_back({1, x});
			}
		}
		
		time_ = 0;
		dfs(1, 1);
		
		for(ll K = 1; K <= 8*n; K++) tree[K] = 0;
		
		ll sol[n+1];
		memset(sol, -1, sizeof sol);
		
		for(ll K = q-1; K >= 0; K--){
			if(v[K][0] == 1){
				ll val = query(1, 1, 2*n, st_time[v[K][2]]);
				sol[v[K][2]] = val;
			}
			else{
				ll u = v[K][1], val = v[K][2];
				
				update(1, 1, 2*n, st_time[u], en_time[u], val);
			}
		}
		
		sol[1] = query(1, 1, 2*n, st_time[1]);
		
		for(ll K = 1; K <= n; K++) cout << sol[K] << ' ';
		cout << "\n";
	}
	
	return 0;
}





































