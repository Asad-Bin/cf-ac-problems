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


const int N = 50;
const ll inf = 1e18;
vector<pair<int,int >> ara(N+5);
ll n, x;
ll dp[N+5][50005], vis[N+5][50005];
ll calc(ll at, ll val)
{
	if(at == 0 && ara[0].first == 0) val -= ara[0].second;
	if(val <= 0){
		return (ll)at*x;
	}
	if(at == 0) {
		return -inf;
	}

	if(vis[at][val] == 1) return dp[at][val];

	ll ans = -inf;

	ans = max(ans, calc(at-1, val-ara[at].second) + x - ara[at].first);
	if(ans < 0) ans = -inf;
	ans = max(ans, calc(at-1, val) + x);
	if(ans < 0) ans = -inf;

	vis[at][val] = 1;
	return dp[at][val] = ans;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		// cout << "Case " << cs << ": ";

		cin >>  n >> x;

		ll sum = 0;

		for(int K = 0; K < n; K++){
			cin >> ara[K].first >> ara[K].second;
			sum += ara[K].second;
		}

		// memset(vis, 0, sizeof vis);

		if(n == 1){
			if(ara[0].first) cout << 0 << '\n';
			else cout << ara[0].second << '\n';
			continue;
		}

		ll mid = min(1000, (int)1e5 / t);
		mid *= n;

		for(int K = 0; K <= n; K++){
			for(int L = 0; L <= sum; L++) vis[K][L] = 0;
		}

		for(int K = sum; K >= 0; K--){
			ll ans = ans = calc(n-1, K);

			if(ans >= 0){
				cout << K << "\n";
				break;
			}
		}
	}

	return 0;
}





























